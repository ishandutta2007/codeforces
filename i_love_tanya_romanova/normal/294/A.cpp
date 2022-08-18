/* 
Let's start a fire, biggest one you've ever seen
You bring the matches, I'll bring the gasoline
Ignite it, delight it, the flames grow higher
Burn the world upon a funeral pyre

[Chorus:]
Raze!
Light this motherfucker like a roman candle
Burn this bitch staight to the ground
Raze!
Let's not worry about consequences
If it's standing we'll bring it down

Destroy it all, show no inhibition
Revel and rejoice in unbridled demolition
Smash it, fuck it, nothing will remain
Detect it and wreck it but never take the blame

[Chorus]

We have ignition!

Shake the earth from its very foundation
Lay waste to the world without hesitation
Break it, take it, you don't have any reason
Fuck it, destuct it, its domolition season
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,x,y,sz[1000],quer;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>sz[i];

cin>>quer;
for (;quer;--quer)
{
 cin>>x>>y;
 sz[x-1]+=y-1;
 sz[x+1]+=sz[x]-y;
 sz[x]=0;   
}

for (int i=1;i<=n;i++)
cout<<sz[i]<<endl;

cin.get();cin.get();
return 0;}