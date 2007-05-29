#ifndef SONIXJPGUSB_H
#define SONIXJPGUSB_H
/****************************************************************************
#	 	Sonix sn9c102p sn9c105 sn9c120 library                      #
# 		Copyright (C) 2005 Michel Xhaard   mxhaard@magic.fr         #
#                                                                           #
# This program is free software; you can redistribute it and/or modify      #
# it under the terms of the GNU General Public License as published by      #
# the Free Software Foundation; either version 2 of the License, or         #
# (at your option) any later version.                                       #
#                                                                           #
# This program is distributed in the hope that it will be useful,           #
# but WITHOUT ANY WARRANTY; without even the implied warranty of            #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             #
# GNU General Public License for more details.                              #
#                                                                           #
# You should have received a copy of the GNU General Public License         #
# along with this program; if not, write to the Free Software               #
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA #
#                                                                           #
****************************************************************************/
static int sn9cxxx_init(struct usb_spca50x *spca50x);
static void sn9cxxx_start(struct usb_spca50x *spca50x);
static void sn9cxxx_stopN(struct usb_spca50x *spca50x);
static void sn9cxxx_stop0(struct usb_spca50x *spca50x);
static void sn9cxxx_setbrightness(struct usb_spca50x *spca50x);
static __u16 sn9cxxx_getbrightness(struct usb_spca50x *spca50x);
static void sn9cxxx_setcontrast(struct usb_spca50x *spca50x);
static __u16 sn9cxxx_getcontrast(struct usb_spca50x *spca50x);
static void sn9cxxx_setcolors(struct usb_spca50x *spca50x);
static __u16 sn9cxxx_getcolors(struct usb_spca50x *spca50x);
static void sn9cxxx_setAutobright(struct usb_spca50x *spca50x);
static void sn9cxxx_shutdown(struct usb_spca50x *spca50x);
static void sn9cxxx_setquality(struct usb_spca50x *spca50x);
static int sn9cxxx_sofdetect(struct usb_spca50x *spca50x,
			     struct spca50x_frame *frame, unsigned char *cdata,
			     int *iPix, int seqnum, int *datalength);
/****************************************************************************/
static void
sn9cxxx_shutdown(struct usb_spca50x *spca50x)
{
}
static void
sn9cxxx_stop0(struct usb_spca50x *spca50x)
{
}
static void
sn9cxxx_setquality(struct usb_spca50x *spca50x)
{
}

/****************************************************************************/
static int sn9cxxx_probesensor(struct usb_spca50x *spca50x);
//static unsigned int sn9cxxx_getexposure(struct usb_spca50x *spca50x);
static unsigned int sn9cxxx_setexposure(struct usb_spca50x *spca50x,
					unsigned int expo);

static struct cam_operation fsn9cxx = {
	.initialize = sn9cxxx_init,
	.configure = sonix_config,
	.start = sn9cxxx_start,
	.stopN = sn9cxxx_stopN,
	.stop0 = sn9cxxx_stop0,
	.get_bright = sn9cxxx_getbrightness,
	.set_bright = sn9cxxx_setbrightness,
	.get_contrast = sn9cxxx_getcontrast,
	.set_contrast = sn9cxxx_setcontrast,
	.get_colors = sn9cxxx_getcolors,
	.set_colors = sn9cxxx_setcolors,
	.set_autobright = sn9cxxx_setAutobright,
	.set_quality = sn9cxxx_setquality,
	.cam_shutdown = sn9cxxx_shutdown,
	.sof_detect = sn9cxxx_sofdetect,
};
enum {
	SN9C101 = 0,
	SN9C102,
	SN9C102P,
	SN9C103,
	SN9C105,
	SN9C110,
	SN9C120,
};

static __u8 sn_mi0360[] = {
	0x00, 0x61, 0x44, 0x00, 0x1A, 0x20, 0x20, 0x20, 0xB1, 0x5D, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x10, 0x03, 0x00,
//reg0  reg1  reg2  reg3  reg4  reg5  reg6  reg7  reg8  reg9  rega  regb  regc  regd  rege  regf  reg10 reg11
	0x00, 0x02, 0x0a, 0x28, 0x1e, 0x61, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//reg12 reg13 reg14 reg15 reg16 reg17 reg18 reg19 reg1a reg1b reg1c reg1d reg1e reg1f reg20 reg21 reg22 reg23
};

/*Data from sn9c102p+hv71331r */
static __u8 sn_hv7131[] = {
	0x00, 0x03, 0x64, 0x00, 0x1A, 0x20, 0x20, 0x20, 0xA1, 0x11, 0x02, 0x09, 0x00, 0x00, 0x00, 0x10, 0x03, 0x00,	//00
//reg0  reg1  reg2  reg3  reg4  reg5  reg6  reg7  reg8  reg9  rega  regb  regc  regd  rege  regf  reg10 reg11
	0x00, 0x01, 0x03, 0x28, 0x1e, 0x41, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//reg12 reg13 reg14 reg15 reg16 reg17 reg18 reg19 reg1a reg1b reg1c reg1d reg1e reg1f reg20 reg21 reg22 reg23
};

static __u8 sn_mo4000[] = {
	0x12,	0x23,	0x60,	0x00,	0x1A,	0x00,	0x00,	0x00,	0x81,	0x21,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x03,	0x00,	
	//reg0	reg1	reg2	reg3	reg4	reg5	reg6	reg7	reg8	reg9	rega	regb	regc	regd	rege	regf	reg10	reg11
	0x0b,	0x0f,	0x14,	0x28,	0x1e,	0x40,	0x08,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x08,	0x25,	0x39,	0x4b,
	//reg12	reg13	reg14	reg15	reg16	reg17	reg18	reg19	reg1a	reg1b	reg1c	reg1d	reg1e	reg1f	reg20	reg21	reg22	reg23
	0x5c,	0x6b,	0x79,	0x87,	0x95,	0xa2,	0xaf,	0xbb,	0xc7,	0xd3,	0xdf,	0xea,	0xf5
};

static __u8 sn_ov7660[]	=	{
	0x00,	0x61,	0x40,	0x00,	0x1A,	0x20,	0x20,	0x20,	0x81,	0x21,	0x07,	0x00,	0x00,	0x00,	0x00,	0x10,	0x03,	0x00,
	//reg0	reg1	reg2	reg3	reg4	reg5	reg6	reg7	reg8	reg9	rega	regb	regc	regd	rege	regf	reg10	reg11
	0x01,	0x01,	0x08,	0x28,	0x1e,	0x20,	0x07,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00
	//reg12	reg13	reg14	reg15	reg16	reg17	reg18	reg19	reg1a	reg1b	reg1c	reg1d	reg1e	reg1f	reg20	reg21	reg22	reg23
};
	
static __u8 reg9a[] = {
	0x08, 0x40, 0x20, 0x10, 0x00, 0x04
};

static __u8 regsn20[] = {
	0x00, 0x2D, 0x46, 0x5A, 0x6C, 0x7C, 0x8B, 0x99, 0xA6, 0xB2, 0xBF, 0xCA,
	0xD5, 0xE0, 0xEB, 0xF5, 0xFF
};
static __u8 reg84[] = {
	0x14, 0x00, 0x27, 0x00, 0x07, 0x00, 0xE5, 0x0F, 0xE4, 0x0F, 0x38, 0x00,
	0x3E, 0x00, 0xC3, 0x0F,
	0x00, 0x00, 0x00, 0x00, 0x00
};
static __u8 hv7131r_sensor_init[][8] = {
	{0xC1, 0x11, 0x01, 0x08, 0x01, 0x00, 0x00, 0x10},
	{0xB1, 0x11, 0x34, 0x17, 0x7F, 0x00, 0x00, 0x10},
	{0xD1, 0x11, 0x40, 0xFF, 0x7F, 0x7F, 0x7F, 0x10},
	{0x91, 0x11, 0x44, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x11, 0x14, 0x01, 0xE2, 0x02, 0x82, 0x10},
	{0x91, 0x11, 0x18, 0x00, 0x00, 0x00, 0x00, 0x10},
//      
	{0xA1, 0x11, 0x01, 0x08, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x01, 0x08, 0x00, 0x00, 0x00, 0x10},
	{0xC1, 0x11, 0x25, 0x00, 0x61, 0xA8, 0x00, 0x10},
	{0xA1, 0x11, 0x30, 0x22, 0x00, 0x00, 0x00, 0x10},
	{0xC1, 0x11, 0x31, 0x20, 0x2E, 0x20, 0x00, 0x10},
	{0xC1, 0x11, 0x25, 0x00, 0xC3, 0x50, 0x00, 0x10},
	{0xA1, 0x11, 0x30, 0x07, 0x00, 0x00, 0x00, 0x10},	//gain14
	{0xC1, 0x11, 0x31, 0x10, 0x10, 0x10, 0x00, 0x10},	//r g b 101a10       
//
	{0xA1, 0x11, 0x01, 0x08, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x21, 0xD0, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x23, 0x09, 0x00, 0x00, 0x00, 0x10},
//
	{0xA1, 0x11, 0x01, 0x08, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x21, 0xD0, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xA1, 0x11, 0x23, 0x10, 0x00, 0x00, 0x00, 0x10},
	{0, 0, 0, 0, 0, 0, 0, 0}
};
static __u8 mi0360_sensor_init[][8] = {
	{0xB1, 0x5D, 0x07, 0x00, 0x02, 0x00, 0x00, 0x10},
	{0xB1, 0x5D, 0x0D, 0x00, 0x01, 0x00, 0x00, 0x10},
	{0xB1, 0x5D, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x01, 0x00, 0x08, 0x00, 0x16, 0x10},
	{0xD1, 0x5D, 0x03, 0x01, 0xE2, 0x02, 0x82, 0x10},
	{0xD1, 0x5D, 0x05, 0x00, 0x09, 0x00, 0x53, 0x10},
	{0xB1, 0x5D, 0x0D, 0x00, 0x02, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x12, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x14, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x16, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x18, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x1A, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xB1, 0x5D, 0x32, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x20, 0x91, 0x01, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x22, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x24, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x26, 0x00, 0x00, 0x00, 0x24, 0x10},
	{0xD1, 0x5D, 0x2F, 0xF7, 0xB0, 0x00, 0x04, 0x10},
	{0xD1, 0x5D, 0x31, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x33, 0x00, 0x00, 0x01, 0x00, 0x10},
	{0xB1, 0x5D, 0x3D, 0x06, 0x8F, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x40, 0x01, 0xE0, 0x00, 0xD1, 0x10},
	{0xB1, 0x5D, 0x44, 0x00, 0x82, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x58, 0x00, 0x78, 0x00, 0x43, 0x10},
	{0xD1, 0x5D, 0x5A, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x5C, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x5E, 0x00, 0x00, 0xA3, 0x1D, 0x10},
	{0xB1, 0x5D, 0x62, 0x04, 0x11, 0x00, 0x00, 0x10},

	{0xB1, 0x5D, 0x20, 0x91, 0x01, 0x00, 0x00, 0x10},
	{0xB1, 0x5D, 0x20, 0x11, 0x01, 0x00, 0x00, 0x10},
	{0xB1, 0x5D, 0x09, 0x00, 0x64, 0x00, 0x00, 0x10},
	{0xD1, 0x5D, 0x2B, 0x00, 0xA0, 0x00, 0xB0, 0x10},
	{0xD1, 0x5D, 0x2D, 0x00, 0xA0, 0x00, 0xA0, 0x10},

	{0xB1, 0x5D, 0x0A, 0x00, 0x02, 0x00, 0x00, 0x10},	//sensor clck ?2
	{0xB1, 0x5D, 0x06, 0x00, 0x30, 0x00, 0x00, 0x10},
	{0xB1, 0x5D, 0x05, 0x00, 0x0A, 0x00, 0x00, 0x10},
	{0xB1, 0x5D, 0x09, 0x02, 0x35, 0x00, 0x00, 0x10},	// exposure 2

	{0xD1, 0x5D, 0x2B, 0x00, 0xB9, 0x00, 0xE3, 0x10},
	{0xD1, 0x5D, 0x2D, 0x00, 0x5f, 0x00, 0xB9, 0x10}, //42
	//{0xB1, 0x5D, 0x35, 0x00, 0x67, 0x00, 0x00, 0x10},  //gain orig
	//{0xB1, 0x5D, 0x35, 0x00, 0x20, 0x00, 0x00, 0x10},  //gain 
	{0xB1, 0x5D, 0x07, 0x00, 0x03, 0x00, 0x00, 0x10},	//update
	{0xB1, 0x5D, 0x07, 0x00, 0x02, 0x00, 0x00, 0x10},	//sensor on
	{0, 0, 0, 0, 0, 0, 0, 0}
};
static __u8 mo4000_sensor_init[][8] = {
 	{0xa1, 0x21, 0x06, 0x80, 0x00, 0x00, 0x00, 0x10}, 
 	{0xa1, 0x21, 0x06, 0x80, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x06, 0x81, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x11, 0x00, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x11, 0x20, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x11, 0x30, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x11, 0x38, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x11, 0x38, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x12, 0x00, 0x00, 0x00, 0x00, 0x10},

	{0xa1, 0x21, 0x12, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xa1, 0x21, 0x12, 0x00, 0x00, 0x00, 0x00, 0x10},
/***************/
 	{0xa1, 0x21, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x0f, 0x20, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x10, 0x20, 0x00, 0x00, 0x00, 0x10},
 	{0xa1, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10},
/***************/
 	{0xa1, 0x21, 0x11, 0x38, 0x00, 0x00, 0x00, 0x10},
	{0, 0, 0, 0, 0, 0, 0, 0}
};
static __u8 ov7660_sensor_init[][8] = {
{0xa1, 0x21, 0x12, 0x80, 0x00, 0x00, 0x00, 0x10},//reset SCCB
{0xa1, 0x21, 0x12, 0x05, 0x00, 0x00, 0x00, 0x10},//  Outformat ?? rawRGB
	{0xa1, 0x21, 0x13, 0xb8, 0x00, 0x00, 0x00, 0x10}, //init COM8
//{0xd1, 0x21, 0x00, 0x01, 0x74, 0x92, 0x00, 0x10}, //GAIN BLUE RED VREF
{0xd1, 0x21, 0x00, 0x01, 0x74, 0x74, 0x00, 0x10}, //GAIN BLUE RED VREF
{0xd1, 0x21, 0x04, 0x00, 0x7d, 0x62, 0x00, 0x10},//COM 1 BAVE GEAVE AECHH
{0xb1, 0x21, 0x08, 0x83, 0x01, 0x00, 0x00, 0x10},//RAVE COM2
{0xd1, 0x21, 0x0c, 0x00, 0x08, 0x04, 0x4f, 0x10},//COM 3 4 5 6
//	{0xd1, 0x21, 0x10, 0x7f, 0x40, 0x05, 0xf8, 0x10},//AECH CLKRC COM7 COM8
{0xd1, 0x21, 0x10, 0x7f, 0x40, 0x05, 0xff, 0x10},//AECH CLKRC COM7 COM8
{0xc1, 0x21, 0x14, 0x2c, 0x00, 0x02, 0x00, 0x10}, // COM9 COM10
{0xd1, 0x21, 0x17, 0x10, 0x60, 0x02, 0x7b, 0x10},//HSTART HSTOP VSTRT VSTOP
{0xa1, 0x21, 0x1b, 0x02, 0x00, 0x00, 0x00, 0x10},//PSHFT
{0xb1, 0x21, 0x1e, 0x01, 0x0e, 0x00, 0x00, 0x10}, //MVFP LAEC
{0xd1, 0x21, 0x20, 0x07, 0x07, 0x07, 0x07, 0x10},// BOS GBOS GROS ROS (BGGR offset)
//	{0xd1, 0x21, 0x24, 0x68, 0x58, 0xd4, 0x80, 0x10}, //AEW AEB VPT BBIAS
{0xd1, 0x21, 0x24, 0x78, 0x68, 0xd4, 0x80, 0x10}, //AEW AEB VPT BBIAS
{0xd1, 0x21, 0x28, 0x80, 0x30, 0x00, 0x00, 0x10}, //GbBIAS RSVD EXHCH EXHCL
{0xd1, 0x21, 0x2c, 0x80, 0x00, 0x00, 0x62, 0x10}, //RBIAS ADVFL ASDVFH YAVE
{0xc1, 0x21, 0x30, 0x08, 0x30, 0xb4, 0x00, 0x10}, //HSYST HSYEN HREF 
{0xd1, 0x21, 0x33, 0x00, 0x07, 0x84, 0x00, 0x10}, //reserved
{0xd1, 0x21, 0x37, 0x0c, 0x02, 0x43, 0x00, 0x10}, //ADC ACOM OFON TSLB
{0xd1, 0x21, 0x3b, 0x02, 0x6c, 0x19, 0x0e, 0x10}, //COM11 COM12 COM13 COM14
{0xd1, 0x21, 0x3f, 0x41, 0xc1, 0x22, 0x08, 0x10}, //EDGE COM15 COM16 COM17
{0xd1, 0x21, 0x43, 0xf0, 0x10, 0x78, 0xa8, 0x10}, //reserved
{0xd1, 0x21, 0x47, 0x60, 0x80, 0x00, 0x00, 0x10}, //reserved
{0xd1, 0x21, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x10}, //reserved
{0xd1, 0x21, 0x4f, 0x46, 0x36, 0x0f, 0x17, 0x10}, //MTX 1 2 3 4
{0xd1, 0x21, 0x53, 0x7f, 0x96, 0x40, 0x40, 0x10}, //MTX 5 6 7 8
{0xb1, 0x21, 0x57, 0x40, 0x0f, 0x00, 0x00, 0x10}, //MTX9 MTXS
{0xd1, 0x21, 0x59, 0xba, 0x9a, 0x22, 0xb9, 0x10}, //reserved
{0xd1, 0x21, 0x5d, 0x9b, 0x10, 0xf0, 0x05, 0x10}, //reserved
{0xa1, 0x21, 0x61, 0x60, 0x00, 0x00, 0x00, 0x10}, //reserved
{0xd1, 0x21, 0x62, 0x00, 0x00, 0x50, 0x30, 0x10}, //LCC1 LCC2 LCC3 LCC4
{0xa1, 0x21, 0x66, 0x00, 0x00, 0x00, 0x00, 0x10}, //LCC5 
{0xd1, 0x21, 0x67, 0x80, 0x7a, 0x90, 0x80, 0x10},
{0xa1, 0x21, 0x6b, 0x0a, 0x00, 0x00, 0x00, 0x10}, //band gap reference [0..3] DBLV
{0xd1, 0x21, 0x6c, 0x30, 0x48, 0x80, 0x74, 0x10}, //gamma curve
{0xd1, 0x21, 0x70, 0x64, 0x60, 0x5c, 0x58, 0x10}, //gamma curve
{0xd1, 0x21, 0x74, 0x54, 0x4c, 0x40, 0x38, 0x10}, //gamma curve
{0xd1, 0x21, 0x78, 0x34, 0x30, 0x2f, 0x2b, 0x10}, //gamma curve
{0xd1, 0x21, 0x7c, 0x03, 0x07, 0x17, 0x34, 0x10}, //gamma curve
{0xd1, 0x21, 0x80, 0x41, 0x4d, 0x58, 0x63, 0x10}, //gamma curve
{0xd1, 0x21, 0x84, 0x6e, 0x77, 0x87, 0x95, 0x10}, //gamma curve
{0xc1, 0x21, 0x88, 0xaf, 0xc7, 0xdf, 0x00, 0x10}, //gamma curve
{0xc1, 0x21, 0x8b, 0x99, 0x99, 0xcf, 0x00, 0x10}, //reserved
{0xb1, 0x21, 0x92, 0x00, 0x00, 0x00, 0x00, 0x10},
/*******************/
{0xa1, 0x21, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x10},//bits[3..0]reserved
{0xa1, 0x21, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x10},
{0xa1, 0x21, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10}, //VREF vertical frame ctrl
{0xa1, 0x21, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xa1, 0x21, 0x10, 0x20, 0x00, 0x00, 0x00, 0x10}, //0x20
{0xa1, 0x21, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x10},
{0xa1, 0x21, 0x2e, 0x00, 0x00, 0x00, 0x00, 0x10},
	{0xa1, 0x21, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x10},
//{0xb1, 0x21, 0x01, 0x78, 0x78, 0x00, 0x00, 0x10},
/******************/
{0xa1, 0x21, 0x93, 0x00, 0x00, 0x00, 0x00, 0x10},//dummy line hight
{0xa1, 0x21, 0x92, 0x25, 0x00, 0x00, 0x00, 0x10},//dummy line low
{0xa1, 0x21, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x10},
{0xa1, 0x21, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x10},
	//{0xa1, 0x21, 0x02, 0x90, 0x00, 0x00, 0x00, 0x10},
/**********startsensor boum if changed !!****/
{0xa1, 0x21, 0x93, 0x01, 0x00, 0x00, 0x00, 0x10},
{0xa1, 0x21, 0x92, 0xff, 0x00, 0x00, 0x00, 0x10},
{0xa1, 0x21, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x10},
{0xa1, 0x21, 0x2b, 0xc3, 0x00, 0x00, 0x00, 0x10},
{0, 0, 0, 0, 0, 0, 0, 0}
};
//		reg0x04		reg0x07		reg 0x10
//expo  = (COM1 & 0x02) | (AECHH & 0x2f <<10) [ (AECh << 2)

#if 0
static __u8 qtable1[] = {
	0x0B, 0x07, 0x07, 0x0B, 0x07, 0x07, 0x0B, 0x0B, 0x0B, 0x0B, 0x0E, 0x0B,
	0x0B, 0x0E, 0x12, 0x1D,
	0x12, 0x12, 0x0E, 0x0E, 0x12, 0x24, 0x19, 0x19, 0x15, 0x1D, 0x2B, 0x24,
	0x2B, 0x2B, 0x27, 0x24,
	0x27, 0x27, 0x2F, 0x32, 0x40, 0x39, 0x2F, 0x32, 0x3D, 0x32, 0x27, 0x27,
	0x39, 0x4F, 0x39, 0x3D,
	0x44, 0x48, 0x4B, 0x4B, 0x4B, 0x2B, 0x36, 0x52, 0x56, 0x4F, 0x48, 0x56,
	0x40, 0x48, 0x4B, 0x48,
	0x0B, 0x0E, 0x0E, 0x12, 0x0E, 0x12, 0x20, 0x12, 0x12, 0x20, 0x48, 0x2F,
	0x27, 0x2F, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x48
};
static __u8 qtable2[] = {
	0x09, 0x06, 0x06, 0x09, 0x06, 0x06, 0x09, 0x09, 0x09, 0x09, 0x0C, 0x09,
	0x09, 0x0C, 0x0F, 0x18,
	0x0F, 0x0F, 0x0C, 0x0C, 0x0F, 0x1E, 0x15, 0x15, 0x12, 0x18, 0x24, 0x1E,
	0x24, 0x24, 0x21, 0x1E,
	0x21, 0x21, 0x27, 0x2A, 0x36, 0x30, 0x27, 0x2A, 0x33, 0x2A, 0x21, 0x21,
	0x30, 0x42, 0x30, 0x33,
	0x39, 0x3C, 0x3F, 0x3F, 0x3F, 0x24, 0x2D, 0x45, 0x48, 0x42, 0x3C, 0x48,
	0x36, 0x3C, 0x3F, 0x3C,
	0x09, 0x0C, 0x0C, 0x0F, 0x0C, 0x0F, 0x1B, 0x0F, 0x0F, 0x1B, 0x3C, 0x27,
	0x21, 0x27, 0x3C, 0x3C,
	0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C,
	0x3C, 0x3C, 0x3C, 0x3C,
	0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C,
	0x3C, 0x3C, 0x3C, 0x3C,
	0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C,
	0x3C, 0x3C, 0x3C, 0x3C
};
static __u8 qtable3[] = {
	0x07, 0x05, 0x05, 0x07, 0x05, 0x05, 0x07, 0x07, 0x07, 0x07, 0x0A, 0x07,
	0x07, 0x0A, 0x0C, 0x14,
	0x0C, 0x0C, 0x0A, 0x0A, 0x0C, 0x19, 0x11, 0x11, 0x0F, 0x14, 0x1E, 0x19,
	0x1E, 0x1E, 0x1B, 0x19,
	0x1B, 0x1B, 0x20, 0x23, 0x2D, 0x28, 0x20, 0x23, 0x2A, 0x23, 0x1B, 0x1B,
	0x28, 0x37, 0x28, 0x2A,
	0x2F, 0x32, 0x34, 0x34, 0x34, 0x1E, 0x25, 0x39, 0x3C, 0x37, 0x32, 0x3C,
	0x2D, 0x32, 0x34, 0x32,
	0x07, 0x0A, 0x0A, 0x0C, 0x0A, 0x0C, 0x16, 0x0C, 0x0C, 0x16, 0x32, 0x20,
	0x1B, 0x20, 0x32, 0x32,
	0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
	0x32, 0x32, 0x32, 0x32,
	0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
	0x32, 0x32, 0x32, 0x32,
	0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
	0x32, 0x32, 0x32, 0x32
};

#endif
static __u8 qtable4[] = {
	0x06, 0x04, 0x04, 0x06, 0x04, 0x04, 0x06, 0x06, 0x06, 0x06, 0x08, 0x06,
	0x06, 0x08, 0x0A, 0x11,
	0x0A, 0x0A, 0x08, 0x08, 0x0A, 0x15, 0x0F, 0x0F, 0x0C, 0x11, 0x19, 0x15,
	0x19, 0x19, 0x17, 0x15,
	0x17, 0x17, 0x1B, 0x1D, 0x25, 0x21, 0x1B, 0x1D, 0x23, 0x1D, 0x17, 0x17,
	0x21, 0x2E, 0x21, 0x23,
	0x27, 0x29, 0x2C, 0x2C, 0x2C, 0x19, 0x1F, 0x30, 0x32, 0x2E, 0x29, 0x32,
	0x25, 0x29, 0x2C, 0x29,
	0x06, 0x08, 0x08, 0x0A, 0x08, 0x0A, 0x13, 0x0A, 0x0A, 0x13, 0x29, 0x1B,
	0x17, 0x1B, 0x29, 0x29,
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29,
	0x29, 0x29, 0x29, 0x29,
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29,
	0x29, 0x29, 0x29, 0x29,
	0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29,
	0x29, 0x29, 0x29, 0x29
};

#if 0
static __u8 qtable5[] = {
	0x05, 0x03, 0x03, 0x05, 0x03, 0x03, 0x05, 0x05, 0x05, 0x05, 0x07, 0x05,
	0x05, 0x07, 0x09, 0x0E,
	0x09, 0x09, 0x07, 0x07, 0x09, 0x11, 0x0C, 0x0C, 0x0A, 0x0E, 0x15, 0x11,
	0x15, 0x15, 0x13, 0x11,
	0x13, 0x13, 0x16, 0x18, 0x1F, 0x1C, 0x16, 0x18, 0x1D, 0x18, 0x13, 0x13,
	0x1C, 0x26, 0x1C, 0x1D,
	0x21, 0x23, 0x24, 0x24, 0x24, 0x15, 0x1A, 0x28, 0x29, 0x26, 0x23, 0x29,
	0x1F, 0x23, 0x24, 0x23,
	0x05, 0x07, 0x07, 0x09, 0x07, 0x09, 0x10, 0x09, 0x09, 0x10, 0x23, 0x16,
	0x13, 0x16, 0x23, 0x23,
	0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23,
	0x23, 0x23, 0x23, 0x23,
	0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23,
	0x23, 0x23, 0x23, 0x23,
	0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23,
	0x23, 0x23, 0x23, 0x23
};
static __u8 qtable6[] = {
	0x04, 0x03, 0x03, 0x04, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04, 0x06, 0x04,
	0x04, 0x06, 0x07, 0x0C,
	0x07, 0x07, 0x06, 0x06, 0x07, 0x0E, 0x0A, 0x0A, 0x09, 0x0C, 0x11, 0x0E,
	0x11, 0x11, 0x10, 0x0E,
	0x10, 0x10, 0x13, 0x14, 0x1A, 0x17, 0x13, 0x14, 0x18, 0x14, 0x10, 0x10,
	0x17, 0x20, 0x17, 0x18,
	0x1B, 0x1D, 0x1E, 0x1E, 0x1E, 0x11, 0x16, 0x21, 0x23, 0x20, 0x1D, 0x23,
	0x1A, 0x1D, 0x1E, 0x1D,
	0x04, 0x06, 0x06, 0x07, 0x06, 0x07, 0x0D, 0x07, 0x07, 0x0D, 0x1D, 0x13,
	0x10, 0x13, 0x1D, 0x1D,
	0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D,
	0x1D, 0x1D, 0x1D, 0x1D,
	0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D,
	0x1D, 0x1D, 0x1D, 0x1D,
	0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D,
	0x1D, 0x1D, 0x1D, 0x1D
};
static __u8 qtable7[] = {
	0x04, 0x02, 0x02, 0x04, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x05, 0x04,
	0x04, 0x05, 0x06, 0x0A,
	0x06, 0x06, 0x05, 0x05, 0x06, 0x0C, 0x08, 0x08, 0x07, 0x0A, 0x0E, 0x0C,
	0x0E, 0x0E, 0x0D, 0x0C,
	0x0D, 0x0D, 0x10, 0x11, 0x16, 0x13, 0x10, 0x11, 0x14, 0x11, 0x0D, 0x0D,
	0x13, 0x1A, 0x13, 0x14,
	0x17, 0x18, 0x19, 0x19, 0x19, 0x0E, 0x12, 0x1C, 0x1D, 0x1A, 0x18, 0x1D,
	0x16, 0x18, 0x19, 0x18,
	0x04, 0x05, 0x05, 0x06, 0x05, 0x06, 0x0B, 0x06, 0x06, 0x0B, 0x18, 0x10,
	0x0D, 0x10, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	0x18, 0x18, 0x18, 0x18
};
static __u8 qtable8[] = {
	0x03, 0x02, 0x02, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x03,
	0x03, 0x04, 0x05, 0x08,
	0x05, 0x05, 0x04, 0x04, 0x05, 0x0A, 0x07, 0x07, 0x06, 0x08, 0x0C, 0x0A,
	0x0C, 0x0C, 0x0B, 0x0A,
	0x0B, 0x0B, 0x0D, 0x0E, 0x12, 0x10, 0x0D, 0x0E, 0x11, 0x0E, 0x0B, 0x0B,
	0x10, 0x16, 0x10, 0x11,
	0x13, 0x14, 0x15, 0x15, 0x15, 0x0C, 0x0F, 0x17, 0x18, 0x16, 0x14, 0x18,
	0x12, 0x14, 0x15, 0x14,
	0x03, 0x04, 0x04, 0x05, 0x04, 0x05, 0x09, 0x05, 0x05, 0x09, 0x14, 0x0D,
	0x0B, 0x0D, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,
	0x14, 0x14, 0x14, 0x14
};

static int
sn9c102p_status(struct usb_device *dev)
{
	__u8 status = 0;
	__u8 count = 10;
	while (count--) {
		status = 0;
		sonixRegRead(dev, 0x00, 0x08, 0x0000, &status, 1);
		if (status & 0x04)
			return 0;
		if (status & 0x08)
			return -EIO;
		wait_ms(1);
	}
	return -ETIMEDOUT;
}
#endif
static int
sn9c102p_i2cwrite(struct usb_spca50x *spca50x, __u8 * buffer, __u16 length)
{
	struct usb_device *dev = spca50x->dev;
	__u8 mode[] = { 0x81, 0x11, 0, 0, 0, 0, 0, 0x10 };
	/* is i2c ready */
	__u8 i2cbase = spca50x->i2c_base;
	__u8 i2cCtrl = spca50x->i2c_ctrl_reg;
	mode[0] = i2cCtrl;
	mode[1] = i2cbase;
	if (length > 5 || !buffer)
		return -1;
	mode[0] = mode[0] | length << 4;
	memcpy(&mode[2], buffer, length);
	sonixRegWrite(dev, 0x08, 0x08, 0x0000, mode, 8);
	return 0;
}

static void
sn9c102p_i2cwritebuf(struct usb_device *dev, __u8 * buffer)
{
	sonixRegWrite(dev, 0x08, 0x08, 0x0000, buffer, 8);
	wait_ms(1);
}

static int
sn9c102p_i2cread(struct usb_spca50x *spca50x, __u8 reg,
		 __u8 * buffer, __u16 length)
{
	struct usb_device *dev = spca50x->dev;
	__u8 i2cbase = spca50x->i2c_base;
	__u8 i2cCtrl = spca50x->i2c_ctrl_reg;
	int err = 0;
	__u8 mode[] = { 0x91, 0x11, 0, 0, 0, 0, 0, 0x10 };
	__u8 result[] = { 0, 0, 0, 0, 0 };
	mode[0] = i2cCtrl | 0x10;
	mode[1] = i2cbase;
	if (length > 5 || !buffer)
		return -1;
	mode[2] = reg;
	sonixRegWrite(dev, 0x08, 0x08, 0x0000, mode, 8);
	wait_ms(1);
	mode[2] = 0;
	mode[0] = i2cCtrl | length << 4 | 0x02;
	sonixRegWrite(dev, 0x08, 0x08, 0x0000, mode, 8);
	wait_ms(1);
	sonixRegRead(dev, 0x00, 0x0a, 0x0000, result, 5);
	memcpy(buffer, result, length);
	return err;
}

static int
sn9cxxx_probesensor(struct usb_spca50x *spca50x)
{
	struct usb_device *dev = spca50x->dev;
	int err = 0;
	__u8 reg02 = 0x66;
	/* reg val1 val2 val3 val4 */
	__u8 datasend[] = { 0, 0, 0, 0, 0 };
	__u8 datarecd[] = { 0, 0, 0, 0, 0 };
	datasend[0] = 2;	//sensor wakeup
	err = sn9c102p_i2cwrite(spca50x, datasend, 2);
	//should write 0xa1 0x11 0x02 0x00 0x00 0x00 0x00 the 0x10 is add by i2cw
	wait_ms(10);
	sonixRegWrite(dev, 0x08, 0x02, 0x0000, &reg02, 1);	//Gpio on
	wait_ms(10);
	err += sn9c102p_i2cread(spca50x, 0, datarecd, 5);	//read sensor id
	if (err)
		goto errors;
	if (datarecd[0] == 0x02 && datarecd[1] == 0x09 && datarecd[2] == 0x01
	    && datarecd[3] == 0x00 && datarecd[4] == 0x00) {
		PDEBUG(1, "Find Sensor sn9c102P HV7131R");
		spca50x->sensor = SENSOR_HV7131R;
		return SENSOR_HV7131R;
	}
	PDEBUG(0, "Find Sensor %d %d %d", datarecd[0], datarecd[1],
	       datarecd[2]);
	PDEBUG(0, "Sensor sn9c102P Not found Contact mxhaard@free.fr ");
	return -ENODEV;
      errors:PDEBUG(0,
	       "Sensor sn9c102P too many errors Contact mxhaard@free.fr ");
	return -ENODEV;
}

static void
hv7131R_InitSensor(struct usb_spca50x *spca50x)
{
	int i = 0;
	struct usb_device *dev = spca50x->dev;
	__u8 SetSensorClk[] = { 0xA1, 0x11, 0x01, 0x18, 0x00, 0x00, 0x00, 0x10 };	//0x08 Mclk

	while (hv7131r_sensor_init[i][0]) {
		sn9c102p_i2cwritebuf(dev, hv7131r_sensor_init[i]);
		i++;
	}
	sn9c102p_i2cwritebuf(dev, SetSensorClk);
}
static void
mi0360_InitSensor(struct usb_spca50x *spca50x)
{
	int i = 0;
	struct usb_device *dev = spca50x->dev;

	while (mi0360_sensor_init[i][0]) {
		sn9c102p_i2cwritebuf(dev, mi0360_sensor_init[i]);
		i++;
	}
}
static void
mo4000_InitSensor(struct usb_spca50x *spca50x)
{
	int i = 0;
	struct usb_device *dev = spca50x->dev;

	while (mo4000_sensor_init[i][0]) {
		sn9c102p_i2cwritebuf(dev, mo4000_sensor_init[i]);
		i++;
	}
}
static void
ov7660_InitSensor(struct usb_spca50x *spca50x)
{
	int i = 0;
	struct usb_device *dev = spca50x->dev;

	while (ov7660_sensor_init[i][0]) {
		sn9c102p_i2cwritebuf(dev, ov7660_sensor_init[i]);
		i++;
	}
}
static int
sn9cxxx_init(struct usb_spca50x *spca50x)
{
	struct usb_device *dev = spca50x->dev;
	int err = 0;
	__u8 *sn9c1xx = NULL;
	__u8 regF1 = 0x01;
	__u8 regGpio[] = { 0x29, 0x74 };
	__u8 data = 0x00;
	/* setup a selector by customid */
	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		sn9c1xx = sn_hv7131;
		break;
	case SENSOR_MI0360:
		sn9c1xx = sn_mi0360;
		break;
	case SENSOR_MO4000:
		sn9c1xx = sn_mo4000;
		break;
	case SENSOR_OV7660:
		sn9c1xx = sn_ov7660;
		break;
	}
	if (sn9c1xx == NULL)
		return -ENODEV;
	sonixRegWrite(dev, 0x08, 0xf1, 0x0000, &regF1, 1);
	sonixRegRead(dev, 0x00, 0x00, 0x0000, &regF1, 1);
	sonixRegWrite(dev, 0x08, 0xf1, 0x0000, &regF1, 1);
	sonixRegRead(dev, 0x00, 0x00, 0x0000, &regF1, 1);
	switch (spca50x->customid) {
	case SN9C102P:
		if (regF1 != 0x11)
			return -ENODEV;
		sonixRegWrite(dev, 0x08, 0x02, 0x0000, &regGpio[1], 1);
	case SN9C105:
		if (regF1 != 0x11)
			return -ENODEV;
		sonixRegWrite(dev, 0x08, 0x02, 0x0000, regGpio, 2);
		break;
	case SN9C110:
		if (regF1 != 0x12)
			return -ENODEV;
		regGpio[1] = 0x62;
		sonixRegWrite(dev, 0x08, 0x02, 0x0000, &regGpio[1], 1);
		break;
		break;
	case SN9C120:
		if (regF1 != 0x12)
			return -ENODEV;
		regGpio[1] = 0x70;
		sonixRegWrite(dev, 0x08, 0x02, 0x0000, regGpio, 2);
		break;
	}

	regF1 = 0x01;
	sonixRegWrite(dev, 0x08, 0xf1, 0x0000, &regF1, 1);

	regF1 = 0x00;
	sonixRegWrite(dev, 0x08, 0xf1, 0x0000, &regF1, 1);

	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &sn9c1xx[1], 1);

	// configure gpio 
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &sn9c1xx[1], 2);

	sonixRegWrite(dev, 0x08, 0x08, 0x0000, &sn9c1xx[8], 2);

	sonixRegWrite(dev, 0x08, 0x017, 0x0000, &sn9c1xx[0x17], 3);

	sonixRegWrite(dev, 0x08, 0x9a, 0x0000, reg9a, 6);

	data = 0x60;
	sonixRegWrite(dev, 0x08, 0xD4, 0x0000, &data, 1);

	sonixRegWrite(dev, 0x08, 0x03, 0x0000, &sn9c1xx[3], 0x0f);

	data = 0x43;
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &data, 1);

	data = 0x61;
	sonixRegWrite(dev, 0x08, 0x17, 0x0000, &data, 1);

	data = 0x42;
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &data, 1);
	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		// probe sensor
		if ((err = sn9cxxx_probesensor(spca50x)) < 0)
			return -ENODEV;
		break;
	}

	return 0;
}
static void
sn9cxxx_stopN(struct usb_spca50x *spca50x)
{
	struct usb_device *dev = spca50x->dev;
	__u8 stophv7131[] = { 0xA1, 0x11, 0x02, 0x09, 0x00, 0x00, 0x00, 0x10 };
	__u8 stopmi0360[] = { 0xB1, 0x5D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x10 };
	__u8 regF1 = 0x01;
	__u8 data = 0x0b;
	__u8 *sn9c1xx = NULL;
	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		sn9c1xx = sn_hv7131;
		data = 0x2b;
		sn9c102p_i2cwritebuf(dev, stophv7131);
		break;
	case SENSOR_MI0360:
		sn9c1xx = sn_mi0360;
		data = 0x29;
		sn9c102p_i2cwritebuf(dev, stopmi0360);
		break;
	case SENSOR_MO4000:
		sn9c1xx = sn_mo4000;
		break;
	case SENSOR_OV7660:
		sn9c1xx = sn_ov7660;
		break;
	}
	if (sn9c1xx == NULL)
		return;
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &sn9c1xx[1], 1);
	sonixRegWrite(dev, 0x08, 0x17, 0x0000, &sn9c1xx[0x17], 1);
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &sn9c1xx[1], 1);
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &data, 1);
	sonixRegWrite(dev, 0x08, 0xf1, 0x0000, &regF1, 1);
}
static void
sn9cxxx_start(struct usb_spca50x *spca50x)
{
	struct usb_device *dev = spca50x->dev;
	int i;
	__u8 DC29[] = { 0x6a, 0x50, 0x00, 0x00, 0x50, 0x3c };
	__u8 C0[] = { 0x2d, 0x2d, 0x3a, 0x05, 0x04, 0x3f };
	__u8 CA[] = { 0x28, 0xd8, 0x14, 0xec };
	__u8 CE[] = { 0x32, 0xdd, 0x2d, 0xdd };	//MI0360
	__u8 data = 0;
	__u8 regF1 = 0x00;
	__u8 reg17 = 0x61;
	__u8 reg1 = 0x02;
	int err = 0;
	__u8 *sn9c1xx = NULL;
	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		sn9c1xx = sn_hv7131;
		break;
	case SENSOR_MI0360:
		sn9c1xx = sn_mi0360;
		break;
	case SENSOR_MO4000:
		sn9c1xx = sn_mo4000;
		break;
	case SENSOR_OV7660:
		sn9c1xx = sn_ov7660;
		break;
	}
	if (sn9c1xx == NULL)
		return;
	sonixRegWrite(dev, 0x08, 0xf1, 0x0000, &regF1, 1);
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &sn9c1xx[1], 1);
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &sn9c1xx[1], 2);
	sonixRegWrite(dev, 0x08, 0x08, 0x0000, &sn9c1xx[8], 2);
	sonixRegWrite(dev, 0x08, 0x17, 0x0000, &sn9c1xx[0x17], 3);

	sonixRegWrite(dev, 0x08, 0x9a, 0x0000, reg9a, 6);
	data = 0x60;
	sonixRegWrite(dev, 0x08, 0xD4, 0x0000, &data, 1);

	sonixRegWrite(dev, 0x08, 0x03, 0x0000, &sn9c1xx[3], 0x0f);
	data = 0x43;
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &data, 1);
	data = 0x61;
	sonixRegWrite(dev, 0x08, 0x17, 0x0000, &data, 1);
	data = 0x42;
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &data, 1);

	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		if ((err = sn9cxxx_probesensor(spca50x)) < 0)
			return;
		break;
	}

	sonixRegWrite(dev, 0x08, 0x15, 0x0000, &sn9c1xx[0x15], 1);
	sonixRegWrite(dev, 0x08, 0x16, 0x0000, &sn9c1xx[0x16], 1);
	sonixRegWrite(dev, 0x08, 0x12, 0x0000, &sn9c1xx[0x12], 1);
	sonixRegWrite(dev, 0x08, 0x13, 0x0000, &sn9c1xx[0x13], 1);
	sonixRegWrite(dev, 0x08, 0x18, 0x0000, &sn9c1xx[0x18], 1);
	sonixRegWrite(dev, 0x08, 0xd2, 0x0000, &DC29[0], 1);
	sonixRegWrite(dev, 0x08, 0xd3, 0x0000, &DC29[1], 1);
	sonixRegWrite(dev, 0x08, 0xc6, 0x0000, &DC29[2], 1);
	sonixRegWrite(dev, 0x08, 0xc7, 0x0000, &DC29[3], 1);
	sonixRegWrite(dev, 0x08, 0xc8, 0x0000, &DC29[4], 1);
	sonixRegWrite(dev, 0x08, 0xc9, 0x0000, &DC29[5], 1);
	sonixRegWrite(dev, 0x08, 0x18, 0x0000, &sn9c1xx[0x18], 1);
	data = 0x60;
	sonixRegWrite(dev, 0x08, 0x17, 0x0000, &data, 1);
	sonixRegWrite(dev, 0x08, 0x05, 0x0000, &sn9c1xx[5], 1);
	sonixRegWrite(dev, 0x08, 0x07, 0x0000, &sn9c1xx[7], 1);
	sonixRegWrite(dev, 0x08, 0x06, 0x0000, &sn9c1xx[6], 1);
	sonixRegWrite(dev, 0x08, 0x14, 0x0000, &sn9c1xx[0x14], 1);
	sonixRegWrite(dev, 0x08, 0x20, 0x0000, regsn20, 0x11);
	for (i = 0; i < 8; i++)
		sonixRegWrite(dev, 0x08, 0x84, 0x0000, reg84, 0x15);
	data = 0x08;
	sonixRegWrite(dev, 0x08, 0x9a, 0x0000, &data, 1);
	data = 0x59;
	sonixRegWrite(dev, 0x08, 0x99, 0x0000, &data, 1);

	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		hv7131R_InitSensor(spca50x);
		if (spca50x->mode)
		reg1 = 0x46;	//320 clk 48Mhz
	else {
		reg1 = 0x06;	//640 clk 24Mz
	}
		break;
	case SENSOR_MI0360:
		mi0360_InitSensor(spca50x);
		if (spca50x->mode)
		reg1 = 0x46;	//320 clk 48Mhz
	else {
		reg1 = 0x06;	//640 clk 24Mz
	}
		break;
	case SENSOR_MO4000:
		mo4000_InitSensor(spca50x);
		if (spca50x->mode)
		reg1 = 0x46;	//320 clk 48Mhz
	else {
		reg1 = 0x06;	//640 clk 24Mz
	}
		break;
	case SENSOR_OV7660:
		reg1 = 0x44;
		ov7660_InitSensor(spca50x);
		if (spca50x->mode)
		reg17 = 0x21;	//320 
	else {
		reg17 = 0x22;	//640 
	}
		
		break;
	}
	sonixRegWrite(dev, 0x08, 0xc0, 0x0000, C0, 6);
	sonixRegWrite(dev, 0x08, 0xca, 0x0000, CA, 4);
	sonixRegWrite(dev, 0x08, 0xce, 0x0000, CE, 4);	//?? {0x1e,0xdd,0x2d,0xe7}

	// here change size mode 0 -> VGA; 1 -> CIF
	data = 0x40 | sn9c1xx[0x18] | (spca50x->mode << 4);
	sonixRegWrite(dev, 0x08, 0x18, 0x0000, &data, 1);

	sonixRegWrite(dev, 0x08, 0x100, 0x0000, qtable4, 0x40);
	sonixRegWrite(dev, 0x08, 0x140, 0x0000, qtable4 + 0x40, 0x40);

	data = sn9c1xx[0x18] | (spca50x->mode << 4);
	sonixRegWrite(dev, 0x08, 0x18, 0x0000, &data, 1);

	sonixRegWrite(dev, 0x08, 0x17, 0x0000, &reg17, 1);
	
	sonixRegWrite(dev, 0x08, 0x01, 0x0000, &reg1, 1);
	
	sn9cxxx_setbrightness(spca50x);
	sn9cxxx_setcontrast(spca50x);
}


static unsigned int
sn9cxxx_getexposure(struct usb_spca50x *spca50x)
{
	__u8 hexpo,mexpo,lexpo;
	__u8 expo[] = { 0, 0, 0, 0, 0 };
	int err = 0;
	
	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		err += sn9c102p_i2cread(spca50x, 0x25, expo, 5);	//read sensor exposure
		return (unsigned int) (expo[0] << 16 | expo[1] << 8 | expo[2]);
	break;
	case SENSOR_MI0360:
		err += sn9c102p_i2cread(spca50x, 0x09, expo, 5);	//read sensor exposure
		return (unsigned int) (expo[0] << 8 | expo[1]);
	break;
	case SENSOR_OV7660:
	case SENSOR_OV7630:
		err += sn9c102p_i2cread(spca50x, 0x04, expo, 5);	//read sensor exposure
		hexpo = expo[3] & 0x2f;
		lexpo = expo[0] & 0x02;
		err += sn9c102p_i2cread(spca50x, 0x08, expo, 5);	
		mexpo = expo[2];
		return (unsigned int) ((hexpo << 10) | (mexpo << 2) | (lexpo));
	break;
	}
	return 0;
}

static unsigned int
sn9cxxx_setexposure(struct usb_spca50x *spca50x, unsigned int expo)
{
	__u8 Expodoit[] = { 0xc1, 0x11, 0x25, 0x07, 0x27, 0xc0, 0x00, 0x16 };
	__u8 doit[] = { 0xB1, 0x5D, 0x07, 0x00, 0x03, 0x00, 0x00, 0x10 };	//update sensor
	__u8 sensorgo[] = { 0xB1, 0x5D, 0x07, 0x00, 0x02, 0x00, 0x00, 0x10 };	//sensor on
	__u8 expoMi[] = { 0xB1, 0x5D, 0x09, 0x06, 0x35, 0x00, 0x00, 0x16 };	// exposure 0x0635 -> 4 fp/s 0x10
	unsigned int expotimes = expo;

	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		Expodoit[3] = (expotimes >> 16) & 0xff;
		Expodoit[4] = (expotimes >> 8) & 0xff;
		Expodoit[5] = (expotimes & 0xff);
		sn9c102p_i2cwritebuf(spca50x->dev, Expodoit);
		break;
	case SENSOR_MI0360:
		if (expo > 0x0635)
			expo = 0x0635;
		if (expo < 0x0001)
			expo = 0x0001;
		expoMi[3] = (expo >> 8) & 0xFF;
		expoMi[4] = expo & 0xff;
		sn9c102p_i2cwritebuf(spca50x->dev, expoMi);
		sn9c102p_i2cwritebuf(spca50x->dev, doit);
		sn9c102p_i2cwritebuf(spca50x->dev, sensorgo);
		break;
	}
	return expo;
}

static void
sn9cxxx_setbrightness(struct usb_spca50x *spca50x)
{
	unsigned int expo, expotimesret;
	__u8 k2;
	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		expo = spca50x->brightness << 4;
		if (expo > 0x002dc6c0)
			expo = 0x002dc6c0;
		if (expo < 0x02a0)
			expo = 0x02a0;
		expotimesret = sn9cxxx_setexposure(spca50x, expo);
		spca50x->exposure = expotimesret;
		break;
	case SENSOR_MI0360:
		expo = spca50x->brightness >> 4;
		expotimesret = sn9cxxx_setexposure(spca50x, expo);
		spca50x->exposure = expotimesret;
		break;
	}

	k2 = spca50x->brightness >> 10;
	sonixRegWrite(spca50x->dev, 0x08, 0x96, 0x0000, &k2, 1);

}

static __u16
sn9cxxx_getbrightness(struct usb_spca50x *spca50x)
{
	/* hardcoded registers seem not readable */
	switch (spca50x->sensor) {
	case SENSOR_HV7131R:
		//spca50x->brightness = 0x7fff;
		spca50x->brightness = sn9cxxx_getexposure(spca50x) >> 4;
		break;
	case SENSOR_MI0360:
		//spca50x->brightness = 0x1fff;
		spca50x->brightness = sn9cxxx_getexposure(spca50x) << 4;
		break;
	}
	return spca50x->brightness;
}

static void
sn9cxxx_setcontrast(struct usb_spca50x *spca50x)
{
	__u8 k2;
	__u8 contrast[] = { 0x14, 0x00, 0x28, 0x00, 0x07, 0x00 };
	k2 = spca50x->contrast >> 8;
	if (k2 > 0x7f)
		k2 = 0x7f;
	contrast[2] = k2;
	contrast[0] = (k2 + 1) >> 1;
	contrast[4] = (k2 + 1) / 5;
	sonixRegWrite(spca50x->dev, 0x08, 0x84, 0x0000, contrast, 6);
}
static __u16
sn9cxxx_getcontrast(struct usb_spca50x *spca50x)
{
	/* hardcoded registers seem not readable */
	spca50x->contrast = 0x3f << 8;	//0x28
	return spca50x->contrast;
}
static int
sn9cxxx_sofdetect(struct usb_spca50x *spca50x, struct spca50x_frame *frame,
		  unsigned char *cdata, int *iPix, int seqnum, int *datalength)
{
	int sof;
	sof = *datalength - 64;
	if (sof < 0) {
		*iPix = 0;
		return (seqnum + 1);
	} else if (cdata[sof] == 0xff && cdata[sof + 1] == 0xd9) {
		// copy the end of data frame
		memcpy(frame->highwater, cdata, sof + 2);
		frame->highwater += (sof + 2);
		//      totlen += (sof + 2);
// w1 w2 w3
// w4 w5 w6
// w7 w8
		spin_lock(&spca50x->v4l_lock);
		spca50x->avg_lum = ((cdata[sof + 29] << 8) | cdata[sof + 30]) >> 6;	//w4
		spca50x->avg_lum += ((cdata[sof + 33] << 8) | cdata[sof + 34]) >> 6;	//w6
		spca50x->avg_lum += ((cdata[sof + 25] << 8) | cdata[sof + 26]) >> 6;	//w2
		spca50x->avg_lum += ((cdata[sof + 37] << 8) | cdata[sof + 38]) >> 6;	//w8               
		spca50x->avg_lum += ((cdata[sof + 31] << 8) | cdata[sof + 32]) >> 4;	//w5
		spca50x->avg_lum = spca50x->avg_lum >> 4;

		spin_unlock(&spca50x->v4l_lock);
		PDEBUG(4,"mean luma %d", spca50x->avg_lum);
		// setting to skip the rest of the packet
		*iPix = *datalength;
		*datalength = 0;
		return 0;	//start of frame
	} else
		*iPix = 0;
	return (seqnum + 1);
}
static __u16
sn9cxxx_getcolors(struct usb_spca50x *spca50x)
{
//__u8 red,green,blue;

//sonixRegRead(spca50x->dev, 0x00, 0x05, 0x0000, &red, 1);
//sonixRegRead(spca50x->dev, 0x00, 0x06, 0x0000, &blue, 1);
//sonixRegRead(spca50x->dev, 0x00, 0x07, 0x0000, &green, 1);
//PDEBUG(0,"Colors gain red %d green %d blue %d", red & 0x7f,green & 0x7f,blue & 0x7f);
	spca50x->colour = (0x80) << 8;
	return spca50x->colour;
}

static void
sn9cxxx_setcolors(struct usb_spca50x *spca50x)
{
	__u8 red, blue;
	int colour;
	colour = (spca50x->colour >> 8) - 128;
	if (colour > 0) {
		blue = (colour + 32) & 0x7f;
		sonixRegWrite(spca50x->dev, 0x08, 0x06, 0x0000, &blue, 1);
	} else {
		red = (-colour + 32) & 0x7f;
		sonixRegWrite(spca50x->dev, 0x08, 0x05, 0x0000, &red, 1);
	}
}
static void
sn9cxxx_setAutobright(struct usb_spca50x *spca50x)
{
	// Thanks S., without your advice, autobright should not work :) 
	int delta;
	int expotimes = 0;
	unsigned int expotimesret = 0;
	__u8 luma_mean = 130;
	__u8 luma_delta = 20;

	spin_lock_irq(&spca50x->v4l_lock);
	delta = spca50x->avg_lum;
	spin_unlock_irq(&spca50x->v4l_lock);
	if ((delta < (luma_mean - luma_delta)) ||
	    (delta > (luma_mean + luma_delta))) {
		switch (spca50x->sensor) {
		case SENSOR_HV7131R:
			expotimes = spca50x->exposure >> 8;
			expotimes += ((luma_mean - delta) >> 4);
			if (expotimes < 0)
				expotimes = 0;
			expotimesret =
			    sn9cxxx_setexposure(spca50x,
						(unsigned int) (expotimes <<
								8));
			spca50x->exposure = expotimes << 8;
			break;
		case SENSOR_MI0360:
			expotimes = spca50x->exposure;
			expotimes += ((luma_mean - delta) >> 6);
			if (expotimes < 0)
				expotimes = 0;
			expotimesret =
			    sn9cxxx_setexposure(spca50x,
						(unsigned int) expotimes);
			spca50x->exposure = expotimes;
			sn9cxxx_setcolors(spca50x);
			break;
		}
	}

}

#endif				//SONIXJPGUSB
