/*
High velocity bullet at close range
Can damage the mind
Shattering the skull shredding the brain
Severing the spine

Bury a round of lead in the chest
It's quite an impression
Imagine the innards of your soul
The infliction

[Chorus:]
Instinctive regression
With intent to kill
No regard of human life
Or the blood spilled

Riddled convulsions
Confetti of flesh
Scattered helplessly
Losing your control of physical facilities

Release the slide to cleanse inside
Prepare to anoint
Snap the tongue in groove discharged
To make my hallowed point

The power of a gun
Used with conviction
Dispersed on excursions
Randomly kills its victims

My sweet revenge
Bitter in depression
The thrilling release
Of a hated deep persuasion

The power of a gun
Used with conviction
Diffused compulsions
Unending repercussions

Violent emotion
Screaming revolution
Spasm(at)ic convulsions
Death an empty gun
*/

//#pragma comment(linker, "/STACK:16777216")
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long ps;
long fl;

int main(){
//freopen("supper.in","r",stdin);
//freopen("supper.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cout<<st[0];
ps=1;
while (ps<st.size())
{
 if (fl==0&&ps+1<st.size()&&st[ps]=='a'&&st[ps+1]=='t'){cout<<"@";ps+=2;fl=1;}
 else if (ps+3<st.size()&&st[ps]=='d'&&st[ps+1]=='o'&&st[ps+2]=='t')
 {cout<<".";ps+=3;}
 else {cout<<st[ps];++ps;}
}
cout<<endl;
cin.get();cin.get();
return 0;}