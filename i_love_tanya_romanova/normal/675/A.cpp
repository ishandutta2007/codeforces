/*
Flesh and steel collide
Severed remnants, disembodied veins
Brutal homicide
Bloodbath trauma, diabolic gash
Tempered alloy sledge
Bludgeoned to death in a manic rage
Massive torque condemned
Malevolent scourge, vital decrement

Epidemic of violence
Persecution reigns
Blood
Rampant siege of pain

Violent purveyors of death
Depraved reprobates
Venomous vile rampage
Lacerating horde of maleficence
Savage murderous binge
Blatant anarchy
Sadistic damage tantrum
Brute malignancy

Callous hostile attack
Strangled blue and cold
Tracheal crush victim
Respiratory death, agonized torment
Carnage dilation
Bullet-ridden dead
Ballistic lead rupture
Barbarous maelstrom of pain

Chaos dominates
Plundering rape, pandemonium
Arson escalates
Raging killing spree, vicious decadence

Epidemic of violence
Persecution reigns
Kill
Rampant siege of pain

Despiteful savagery perponderates
Viperous destruction regnant
Vigilant snipers exterminate
Staring down the barrel of a gun

Rabid vicious assault
Sordid massacre
Multiple slain corpses
Decomosed remains
Of butchered innocents
Seething heinous disease
Lethal butchery
Psyhotic raving culture
Pestilence of hate

Scathing truculence
Rancorous plague of ferocity
Defenestration
Vehement contempt, sanguinary raid

Epidemic of violence
Persecution reigns
Death
Rampant siege of pain
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int a, b, c, dif;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a >> b >> c;
	if (c == 0)
	{
		if (a == b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}

	dif = b - a;
	if (dif%c != 0 || dif / c < 0)
	{
		cout << "NO" << endl;
	}
	else
		cout << "YES" << endl;
	
	cin.get(); cin.get();
	return 0;
}