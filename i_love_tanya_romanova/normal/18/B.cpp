/*
Crushing all your worthless goals
I define control
Your pain's my fucking ecstasy
So putrid is my world of tyranny

Accentuate your desperation
Flesh from bone, I'll rip and tear
I hate the fact
That we breathe the same air

Helpless, as I dominate
I won't celebrate
Until you've all been crucified
I can not rest 'til everyone has died

I can't stand the victim in you
Infecting everything that I do

I will eradicate
Obliterate, depopulate
Divine, atrocious suffering
Cleansation of the weak, supremacy

Pissing on your faith
Incinerate God's whore
Perpetual is my reign
I will eat your soul

Must maintain control of the weak

Must maintain control of the weak
Must contain the minds of the free
Must maintain control of the weak
Must contain the minds of the free
Must maintain control of the weak
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long long n,d,m,l,qpos,crd,tr,span;
long long ans;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>d>>m>>l;

qpos=0;
crd=0;

while (true)
{
 while (crd*m+l<qpos)++crd;
 if (crd>=n||crd*m>qpos){ans=qpos;break;}
 tr=crd*m+l;
 span=tr-qpos;
 qpos+=span/d*d+d;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}