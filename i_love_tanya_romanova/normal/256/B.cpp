/*
Mother earth of blackened scourges centuries
Mother of worms and inner fallacy
Enthroned obscurity of holocaust and decayment
Exterminate the sons of the so-called supremacy

Unmerciful spheres of the ancestral genocide
Reveal the signs of the inexorable alignment
Breed of pestilent abundance
Breathe the suicidal whirlwhinds of its carrying plague

Cursed inheritance to the blind servants
Dying offspring of the fallen creator
Taste of poison of its own creation
Heaven's cremation red planet's consecration

Mother earth of immense burnt plains
Mother of pain and promised lands
Listen to the rites of thy destination
From the fierceness of chaos the empire became divine
By the fierceness of chaos the empire is now becayed
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
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,x,y,c,l,r,mid;

long long gi(long long g)
{
 if (g<=0)return 0;
 return g*g;
}

long long gj(long long g)
{
 if (g<=0)return 0;
 return (g*g-g)/2+g;
}

long long gett(long long t)
{
 long long ss=(2*t+1)*(t*2+1);
 ss=ss/2+1;
 // sides
 ss-=gi(t-(x-1));
 ss-=gi(t-(n-x));
 ss-=gi(t-(y-1));
 ss-=gi(t-(n-y));
 ss+=gj(t-(x-1)-(y-1)-1);
 ss+=gj(t-(n-x)-(n-y)-1);
 ss+=gj(t-(n-x)-(y-1)-1);
 ss+=gj(t-(x-1)-(n-y)-1);
 return ss;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>x>>y>>c;
l=0;
r=1e6;
while (l<r)
{
 mid=l+r;
 mid/=2;
 if (gett(mid)>=c)r=mid;
 else l=mid+1;
}

cout<<l<<endl;

cin.get();cin.get();
return 0;}