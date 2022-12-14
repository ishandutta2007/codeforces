#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<tuple<int, int, int>> a;
	a.emplace_back(1, 1, 0);
	a.emplace_back(2, 1, 2);
	a.emplace_back(2, 2, 1);
	a.emplace_back(4, 1, 32);
	a.emplace_back(4, 2, 30);
	a.emplace_back(4, 3, 80);
	a.emplace_back(4, 4, 109);
	a.emplace_back(8, 1, 6824);
	a.emplace_back(8, 2, 59808);
	a.emplace_back(8, 3, 147224);
	a.emplace_back(8, 4, 415870);
	a.emplace_back(8, 5, 1757896);
	a.emplace_back(8, 6, 1897056);
	a.emplace_back(8, 7, 4898872);
	a.emplace_back(8, 8, 7593125);
	a.emplace_back(16, 1, 776830421);
	a.emplace_back(16, 2, 290516100);
	a.emplace_back(16, 3, 746623577);
	a.emplace_back(16, 4, 293783147);
	a.emplace_back(16, 5, 33900006);
	a.emplace_back(16, 6, 735127505);
	a.emplace_back(16, 7, 565460332);
	a.emplace_back(16, 8, 428982705);
	a.emplace_back(16, 9, 472062098);
	a.emplace_back(16, 10, 161873957);
	a.emplace_back(16, 11, 117354594);
	a.emplace_back(16, 12, 515619293);
	a.emplace_back(16, 13, 578944191);
	a.emplace_back(16, 14, 312106242);
	a.emplace_back(16, 15, 569389279);
	a.emplace_back(16, 16, 391464593);
	a.emplace_back(32, 1, 261086313);
	a.emplace_back(32, 2, 584837659);
	a.emplace_back(32, 3, 683961846);
	a.emplace_back(32, 4, 468868529);
	a.emplace_back(32, 5, 211593382);
	a.emplace_back(32, 6, 736955478);
	a.emplace_back(32, 7, 229471758);
	a.emplace_back(32, 8, 157617135);
	a.emplace_back(32, 9, 398169441);
	a.emplace_back(32, 10, 360252438);
	a.emplace_back(32, 11, 629394768);
	a.emplace_back(32, 12, 264125799);
	a.emplace_back(32, 13, 647490480);
	a.emplace_back(32, 14, 342079395);
	a.emplace_back(32, 15, 391579767);
	a.emplace_back(32, 16, 225200475);
	a.emplace_back(32, 17, 486011304);
	a.emplace_back(32, 18, 513156108);
	a.emplace_back(32, 19, 628771752);
	a.emplace_back(32, 20, 132906648);
	a.emplace_back(32, 21, 142138221);
	a.emplace_back(32, 22, 20119449);
	a.emplace_back(32, 23, 444199674);
	a.emplace_back(32, 24, 195188679);
	a.emplace_back(32, 25, 387329805);
	a.emplace_back(32, 26, 44684703);
	a.emplace_back(32, 27, 651912135);
	a.emplace_back(32, 28, 737154512);
	a.emplace_back(32, 29, 612549793);
	a.emplace_back(32, 30, 519860281);
	a.emplace_back(32, 31, 186175544);
	a.emplace_back(32, 32, 212568440);
	a.emplace_back(64, 1, 240805271);
	a.emplace_back(64, 2, 239509872);
	a.emplace_back(64, 3, 581127897);
	a.emplace_back(64, 4, 6511239);
	a.emplace_back(64, 5, 156126222);
	a.emplace_back(64, 6, 509425833);
	a.emplace_back(64, 7, 672407328);
	a.emplace_back(64, 8, 366667722);
	a.emplace_back(64, 9, 459185405);
	a.emplace_back(64, 10, 509737025);
	a.emplace_back(64, 11, 554790222);
	a.emplace_back(64, 12, 165216555);
	a.emplace_back(64, 13, 703150560);
	a.emplace_back(64, 14, 74806569);
	a.emplace_back(64, 15, 398730015);
	a.emplace_back(64, 16, 383350905);
	a.emplace_back(64, 17, 506108358);
	a.emplace_back(64, 18, 51326142);
	a.emplace_back(64, 19, 298053147);
	a.emplace_back(64, 20, 104256117);
	a.emplace_back(64, 21, 391428765);
	a.emplace_back(64, 22, 374020479);
	a.emplace_back(64, 23, 206607807);
	a.emplace_back(64, 24, 87664059);
	a.emplace_back(64, 25, 275899176);
	a.emplace_back(64, 26, 56407680);
	a.emplace_back(64, 27, 551553401);
	a.emplace_back(64, 28, 448939463);
	a.emplace_back(64, 29, 582889860);
	a.emplace_back(64, 30, 129676638);
	a.emplace_back(64, 31, 226078251);
	a.emplace_back(64, 32, 135769095);
	a.emplace_back(64, 33, 61292868);
	a.emplace_back(64, 34, 578972226);
	a.emplace_back(64, 35, 190181628);
	a.emplace_back(64, 36, 390739055);
	a.emplace_back(64, 37, 184587732);
	a.emplace_back(64, 38, 446575689);
	a.emplace_back(64, 39, 732674124);
	a.emplace_back(64, 40, 232198470);
	a.emplace_back(64, 41, 676760679);
	a.emplace_back(64, 42, 352474101);
	a.emplace_back(64, 43, 611444862);
	a.emplace_back(64, 44, 575661807);
	a.emplace_back(64, 45, 628905585);
	a.emplace_back(64, 46, 320813094);
	a.emplace_back(64, 47, 522840969);
	a.emplace_back(64, 48, 469781928);
	a.emplace_back(64, 49, 156006018);
	a.emplace_back(64, 50, 554473341);
	a.emplace_back(64, 51, 239654268);
	a.emplace_back(64, 52, 643714911);
	a.emplace_back(64, 53, 433540170);
	a.emplace_back(64, 54, 199307003);
	a.emplace_back(64, 55, 496385218);
	a.emplace_back(64, 56, 291740751);
	a.emplace_back(64, 57, 67309914);
	a.emplace_back(64, 58, 370826673);
	a.emplace_back(64, 59, 202356819);
	a.emplace_back(64, 60, 279421821);
	a.emplace_back(64, 61, 421203111);
	a.emplace_back(64, 62, 63744786);
	a.emplace_back(64, 63, 520987612);
	a.emplace_back(64, 64, 550671827);
	a.emplace_back(128, 1, 482164403);
	a.emplace_back(128, 2, 768209115);
	a.emplace_back(128, 3, 462063756);
	a.emplace_back(128, 4, 154906374);
	a.emplace_back(128, 5, 36099042);
	a.emplace_back(128, 6, 341766705);
	a.emplace_back(128, 7, 678182556);
	a.emplace_back(128, 8, 621882744);
	a.emplace_back(128, 9, 478771358);
	a.emplace_back(128, 10, 231881111);
	a.emplace_back(128, 11, 175889805);
	a.emplace_back(128, 12, 243630450);
	a.emplace_back(128, 13, 168908523);
	a.emplace_back(128, 14, 671961765);
	a.emplace_back(128, 15, 55761813);
	a.emplace_back(128, 16, 652682670);
	a.emplace_back(128, 17, 773939082);
	a.emplace_back(128, 18, 517628076);
	a.emplace_back(128, 19, 756201264);
	a.emplace_back(128, 20, 124604900);
	a.emplace_back(128, 21, 750976272);
	a.emplace_back(128, 22, 498253248);
	a.emplace_back(128, 23, 676047609);
	a.emplace_back(128, 24, 137170026);
	a.emplace_back(128, 25, 705610017);
	a.emplace_back(128, 26, 495032139);
	a.emplace_back(128, 27, 561797418);
	a.emplace_back(128, 28, 703097347);
	a.emplace_back(128, 29, 500815609);
	a.emplace_back(128, 30, 95984586);
	a.emplace_back(128, 31, 739707108);
	a.emplace_back(128, 32, 265613565);
	a.emplace_back(128, 33, 387099846);
	a.emplace_back(128, 34, 777331779);
	a.emplace_back(128, 35, 594676173);
	a.emplace_back(128, 36, 591219559);
	a.emplace_back(128, 37, 407997044);
	a.emplace_back(128, 38, 208947235);
	a.emplace_back(128, 39, 93337440);
	a.emplace_back(128, 40, 478908360);
	a.emplace_back(128, 41, 685013007);
	a.emplace_back(128, 42, 487033953);
	a.emplace_back(128, 43, 671903001);
	a.emplace_back(128, 44, 39521181);
	a.emplace_back(128, 45, 738490312);
	a.emplace_back(128, 46, 33785059);
	a.emplace_back(128, 47, 465470131);
	a.emplace_back(128, 48, 310453920);
	a.emplace_back(128, 49, 54648783);
	a.emplace_back(128, 50, 346831137);
	a.emplace_back(128, 51, 427694175);
	a.emplace_back(128, 52, 474743430);
	a.emplace_back(128, 53, 705296781);
	a.emplace_back(128, 54, 435828036);
	a.emplace_back(128, 55, 429824745);
	a.emplace_back(128, 56, 663532359);
	a.emplace_back(128, 57, 261388683);
	a.emplace_back(128, 58, 244690731);
	a.emplace_back(128, 59, 533997135);
	a.emplace_back(128, 60, 596108961);
	a.emplace_back(128, 61, 506813013);
	a.emplace_back(128, 62, 371892402);
	a.emplace_back(128, 63, 590145264);
	a.emplace_back(128, 64, 104733162);
	a.emplace_back(128, 65, 143420103);
	a.emplace_back(128, 66, 654339672);
	a.emplace_back(128, 67, 700348950);
	a.emplace_back(128, 68, 685038942);
	a.emplace_back(128, 69, 578826927);
	a.emplace_back(128, 70, 286484229);
	a.emplace_back(128, 71, 501639192);
	a.emplace_back(128, 72, 434962491);
	a.emplace_back(128, 73, 299270097);
	a.emplace_back(128, 74, 27702486);
	a.emplace_back(128, 75, 335375775);
	a.emplace_back(128, 76, 111746817);
	a.emplace_back(128, 77, 565603164);
	a.emplace_back(128, 78, 294926121);
	a.emplace_back(128, 79, 676063665);
	a.emplace_back(128, 80, 735862995);
	a.emplace_back(128, 81, 710035809);
	a.emplace_back(128, 82, 437011960);
	a.emplace_back(128, 83, 668528077);
	a.emplace_back(128, 84, 138765186);
	a.emplace_back(128, 85, 508213986);
	a.emplace_back(128, 86, 615036450);
	a.emplace_back(128, 87, 353784942);
	a.emplace_back(128, 88, 624827616);
	a.emplace_back(128, 89, 343900011);
	a.emplace_back(128, 90, 241289776);
	a.emplace_back(128, 91, 52410890);
	a.emplace_back(128, 92, 72018835);
	a.emplace_back(128, 93, 352406796);
	a.emplace_back(128, 94, 415705878);
	a.emplace_back(128, 95, 4802637);
	a.emplace_back(128, 96, 376367145);
	a.emplace_back(128, 97, 65589678);
	a.emplace_back(128, 98, 333633477);
	a.emplace_back(128, 99, 341834527);
	a.emplace_back(128, 100, 303717460);
	a.emplace_back(128, 101, 282387700);
	a.emplace_back(128, 102, 42951006);
	a.emplace_back(128, 103, 254706039);
	a.emplace_back(128, 104, 423048528);
	a.emplace_back(128, 105, 526429710);
	a.emplace_back(128, 106, 68131467);
	a.emplace_back(128, 107, 669954708);
	a.emplace_back(128, 108, 12787348);
	a.emplace_back(128, 109, 500636381);
	a.emplace_back(128, 110, 317959019);
	a.emplace_back(128, 111, 479433192);
	a.emplace_back(128, 112, 657133515);
	a.emplace_back(128, 113, 416259390);
	a.emplace_back(128, 114, 610216692);
	a.emplace_back(128, 115, 340129188);
	a.emplace_back(128, 116, 44594256);
	a.emplace_back(128, 117, 257373347);
	a.emplace_back(128, 118, 138718678);
	a.emplace_back(128, 119, 530767740);
	a.emplace_back(128, 120, 292922628);
	a.emplace_back(128, 121, 37220268);
	a.emplace_back(128, 122, 605295159);
	a.emplace_back(128, 123, 480722613);
	a.emplace_back(128, 124, 458170419);
	a.emplace_back(128, 125, 30540300);
	a.emplace_back(128, 126, 487159055);
	a.emplace_back(128, 127, 232966794);
	a.emplace_back(128, 128, 149150650);
	a.emplace_back(256, 1, 412133651);
	a.emplace_back(256, 2, 386543325);
	a.emplace_back(256, 3, 139952108);
	a.emplace_back(256, 4, 289303402);
	a.emplace_back(256, 5, 102404925);
	a.emplace_back(256, 6, 317067177);
	a.emplace_back(256, 7, 396414708);
	a.emplace_back(256, 8, 80515854);
	a.emplace_back(256, 9, 663739304);
	a.emplace_back(256, 10, 317300809);
	a.emplace_back(256, 11, 228877044);
	a.emplace_back(256, 12, 493725043);
	a.emplace_back(256, 13, 715317967);
	a.emplace_back(256, 14, 490300965);
	a.emplace_back(256, 15, 315527373);
	a.emplace_back(256, 16, 743539734);
	a.emplace_back(256, 17, 488329191);
	a.emplace_back(256, 18, 553627998);
	a.emplace_back(256, 19, 533025234);
	a.emplace_back(256, 20, 242583957);
	a.emplace_back(256, 21, 706116537);
	a.emplace_back(256, 22, 614109258);
	a.emplace_back(256, 23, 645447222);
	a.emplace_back(256, 24, 523195911);
	a.emplace_back(256, 25, 492109128);
	a.emplace_back(256, 26, 722623041);
	a.emplace_back(256, 27, 111085128);
	a.emplace_back(256, 28, 766395126);
	a.emplace_back(256, 29, 654378921);
	a.emplace_back(256, 30, 691964847);
	a.emplace_back(256, 31, 496688157);
	a.emplace_back(256, 32, 399056049);
	a.emplace_back(256, 33, 654363234);
	a.emplace_back(256, 34, 102052314);
	a.emplace_back(256, 35, 191720088);
	a.emplace_back(256, 36, 473910948);
	a.emplace_back(256, 37, 259736526);
	a.emplace_back(256, 38, 332840025);
	a.emplace_back(256, 39, 388047555);
	a.emplace_back(256, 40, 665791056);
	a.emplace_back(256, 41, 627111387);
	a.emplace_back(256, 42, 139696515);
	a.emplace_back(256, 43, 441456687);
	a.emplace_back(256, 44, 443032569);
	a.emplace_back(256, 45, 283264821);
	a.emplace_back(256, 46, 771641703);
	a.emplace_back(256, 47, 452641455);
	a.emplace_back(256, 48, 511306362);
	a.emplace_back(256, 49, 117572859);
	a.emplace_back(256, 50, 127701891);
	a.emplace_back(256, 51, 721298331);
	a.emplace_back(256, 52, 176520078);
	a.emplace_back(256, 53, 357242229);
	a.emplace_back(256, 54, 611296308);
	a.emplace_back(256, 55, 696994956);
	a.emplace_back(256, 56, 405628839);
	a.emplace_back(256, 57, 429224274);
	a.emplace_back(256, 58, 465336054);
	a.emplace_back(256, 59, 695091546);
	a.emplace_back(256, 60, 689828796);
	a.emplace_back(256, 61, 574648641);
	a.emplace_back(256, 62, 351220905);
	a.emplace_back(256, 63, 507964023);
	a.emplace_back(256, 64, 675326610);
	a.emplace_back(256, 65, 517248963);
	a.emplace_back(256, 66, 453528621);
	a.emplace_back(256, 67, 220301928);
	a.emplace_back(256, 68, 494463186);
	a.emplace_back(256, 69, 681789969);
	a.emplace_back(256, 70, 339589656);
	a.emplace_back(256, 71, 44524053);
	a.emplace_back(256, 72, 417125457);
	a.emplace_back(256, 73, 339589404);
	a.emplace_back(256, 74, 747135963);
	a.emplace_back(256, 75, 341780733);
	a.emplace_back(256, 76, 734158215);
	a.emplace_back(256, 77, 396817281);
	a.emplace_back(256, 78, 21997836);
	a.emplace_back(256, 79, 5728464);
	a.emplace_back(256, 80, 147611205);
	a.emplace_back(256, 81, 456248898);
	a.emplace_back(256, 82, 714128667);
	a.emplace_back(256, 83, 377654949);
	a.emplace_back(256, 84, 3862068);
	a.emplace_back(256, 85, 128418948);
	a.emplace_back(256, 86, 589390074);
	a.emplace_back(256, 87, 304947090);
	a.emplace_back(256, 88, 11703825);
	a.emplace_back(256, 89, 228266073);
	a.emplace_back(256, 90, 127304142);
	a.emplace_back(256, 91, 429215724);
	a.emplace_back(256, 92, 361541124);
	a.emplace_back(256, 93, 521572968);
	a.emplace_back(256, 94, 468358191);
	a.emplace_back(256, 95, 341231688);
	a.emplace_back(256, 96, 65323503);
	a.emplace_back(256, 97, 613778508);
	a.emplace_back(256, 98, 15985323);
	a.emplace_back(256, 99, 291661029);
	a.emplace_back(256, 100, 410970006);
	a.emplace_back(256, 101, 591638112);
	a.emplace_back(256, 102, 349541550);
	a.emplace_back(256, 103, 89967528);
	a.emplace_back(256, 104, 224922159);
	a.emplace_back(256, 105, 361094166);
	a.emplace_back(256, 106, 584206074);
	a.emplace_back(256, 107, 640051812);
	a.emplace_back(256, 108, 324264456);
	a.emplace_back(256, 109, 652625388);
	a.emplace_back(256, 110, 693768537);
	a.emplace_back(256, 111, 11740617);
	a.emplace_back(256, 112, 309238398);
	a.emplace_back(256, 113, 211085469);
	a.emplace_back(256, 114, 194905872);
	a.emplace_back(256, 115, 639416484);
	a.emplace_back(256, 116, 110110707);
	a.emplace_back(256, 117, 296645895);
	a.emplace_back(256, 118, 748118511);
	a.emplace_back(256, 119, 131177718);
	a.emplace_back(256, 120, 511142751);
	a.emplace_back(256, 121, 775975599);
	a.emplace_back(256, 122, 421403409);
	a.emplace_back(256, 123, 475528473);
	a.emplace_back(256, 124, 434685258);
	a.emplace_back(256, 125, 1768977);
	a.emplace_back(256, 126, 80301375);
	a.emplace_back(256, 127, 708023862);
	a.emplace_back(256, 128, 569195676);
	a.emplace_back(256, 129, 56238084);
	a.emplace_back(256, 130, 632887668);
	a.emplace_back(256, 131, 88089750);
	a.emplace_back(256, 132, 631539342);
	a.emplace_back(256, 133, 396695565);
	a.emplace_back(256, 134, 38780154);
	a.emplace_back(256, 135, 695798271);
	a.emplace_back(256, 136, 469819224);
	a.emplace_back(256, 137, 439587099);
	a.emplace_back(256, 138, 69045921);
	a.emplace_back(256, 139, 682966116);
	a.emplace_back(256, 140, 112310856);
	a.emplace_back(256, 141, 64943298);
	a.emplace_back(256, 142, 534475872);
	a.emplace_back(256, 143, 40215357);
	a.emplace_back(256, 144, 389728458);
	a.emplace_back(256, 145, 286368453);
	a.emplace_back(256, 146, 736006257);
	a.emplace_back(256, 147, 501181650);
	a.emplace_back(256, 148, 54829908);
	a.emplace_back(256, 149, 603489402);
	a.emplace_back(256, 150, 338032656);
	a.emplace_back(256, 151, 512182818);
	a.emplace_back(256, 152, 627500097);
	a.emplace_back(256, 153, 462674016);
	a.emplace_back(256, 154, 3103092);
	a.emplace_back(256, 155, 157324491);
	a.emplace_back(256, 156, 43978329);
	a.emplace_back(256, 157, 596818971);
	a.emplace_back(256, 158, 259025598);
	a.emplace_back(256, 159, 9088632);
	a.emplace_back(256, 160, 91991781);
	a.emplace_back(256, 161, 577291428);
	a.emplace_back(256, 162, 211245489);
	a.emplace_back(256, 163, 429471231);
	a.emplace_back(256, 164, 142626330);
	a.emplace_back(256, 165, 172560633);
	a.emplace_back(256, 166, 510907446);
	a.emplace_back(256, 167, 444609585);
	a.emplace_back(256, 168, 758102058);
	a.emplace_back(256, 169, 375112647);
	a.emplace_back(256, 170, 744786693);
	a.emplace_back(256, 171, 276174402);
	a.emplace_back(256, 172, 19259856);
	a.emplace_back(256, 173, 233672418);
	a.emplace_back(256, 174, 745389414);
	a.emplace_back(256, 175, 225772848);
	a.emplace_back(256, 176, 23385663);
	a.emplace_back(256, 177, 324290610);
	a.emplace_back(256, 178, 519804558);
	a.emplace_back(256, 179, 120337812);
	a.emplace_back(256, 180, 402578568);
	a.emplace_back(256, 181, 360676008);
	a.emplace_back(256, 182, 450089262);
	a.emplace_back(256, 183, 551043738);
	a.emplace_back(256, 184, 337388940);
	a.emplace_back(256, 185, 512108856);
	a.emplace_back(256, 186, 28879011);
	a.emplace_back(256, 187, 690040638);
	a.emplace_back(256, 188, 106017282);
	a.emplace_back(256, 189, 558262341);
	a.emplace_back(256, 190, 99972432);
	a.emplace_back(256, 191, 608226003);
	a.emplace_back(256, 192, 612152037);
	a.emplace_back(256, 193, 42414435);
	a.emplace_back(256, 194, 776201013);
	a.emplace_back(256, 195, 39580443);
	a.emplace_back(256, 196, 518796945);
	a.emplace_back(256, 197, 494437752);
	a.emplace_back(256, 198, 583194366);
	a.emplace_back(256, 199, 723936555);
	a.emplace_back(256, 200, 415359657);
	a.emplace_back(256, 201, 309569589);
	a.emplace_back(256, 202, 751104774);
	a.emplace_back(256, 203, 166684527);
	a.emplace_back(256, 204, 249229170);
	a.emplace_back(256, 205, 353120823);
	a.emplace_back(256, 206, 130668327);
	a.emplace_back(256, 207, 753823584);
	a.emplace_back(256, 208, 580966092);
	a.emplace_back(256, 209, 561963717);
	a.emplace_back(256, 210, 543672234);
	a.emplace_back(256, 211, 393846327);
	a.emplace_back(256, 212, 586278000);
	a.emplace_back(256, 213, 327398400);
	a.emplace_back(256, 214, 278403867);
	a.emplace_back(256, 215, 156455586);
	a.emplace_back(256, 216, 363920382);
	a.emplace_back(256, 217, 190245195);
	a.emplace_back(256, 218, 290039148);
	a.emplace_back(256, 219, 547014447);
	a.emplace_back(256, 220, 466218648);
	a.emplace_back(256, 221, 146037150);
	a.emplace_back(256, 222, 585462906);
	a.emplace_back(256, 223, 666008595);
	a.emplace_back(256, 224, 691786683);
	a.emplace_back(256, 225, 374707494);
	a.emplace_back(256, 226, 622498779);
	a.emplace_back(256, 227, 231158277);
	a.emplace_back(256, 228, 685740951);
	a.emplace_back(256, 229, 115612245);
	a.emplace_back(256, 230, 681825249);
	a.emplace_back(256, 231, 545555745);
	a.emplace_back(256, 232, 551718468);
	a.emplace_back(256, 233, 277206615);
	a.emplace_back(256, 234, 640171035);
	a.emplace_back(256, 235, 757727334);
	a.emplace_back(256, 236, 195193908);
	a.emplace_back(256, 237, 658656684);
	a.emplace_back(256, 238, 457760646);
	a.emplace_back(256, 239, 225925875);
	a.emplace_back(256, 240, 505761984);
	a.emplace_back(256, 241, 18685233);
	a.emplace_back(256, 242, 506832921);
	a.emplace_back(256, 243, 112511021);
	a.emplace_back(256, 244, 396846646);
	a.emplace_back(256, 245, 290147622);
	a.emplace_back(256, 246, 113924623);
	a.emplace_back(256, 247, 669986155);
	a.emplace_back(256, 248, 336008070);
	a.emplace_back(256, 249, 63611061);
	a.emplace_back(256, 250, 238586775);
	a.emplace_back(256, 251, 119956662);
	a.emplace_back(256, 252, 616557739);
	a.emplace_back(256, 253, 772784623);
	a.emplace_back(256, 254, 334527774);
	a.emplace_back(256, 255, 410403148);
	a.emplace_back(256, 256, 51933421);

	int n, k;
	cin >> n >> k;
	for (auto [x, y, z] : a) {
		if (x == n && y == k) {
			cout << z << '\n';
			return 0;
		}
	}
}