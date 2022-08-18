/*
The doctor is calling

Something's gone wrong
Nowhere do I belong
I listen to the voices in the dark room

Something's going down
But I can't make a sound
Looking past the bars of my mind

The coat of arms falling
I hear the doctor calling
The family crest is falling
I hear the doctor calling

Always sharing trips
Remove me from your lips
Sight and mind still and never go away

One too many tantrums
Deviated symptoms
Better lock the phantom away

The coat of arms falling
I hear the doctor calling
The family crest is falling
I hear the doctor calling
I see the chalkline crawling
I hear the doctor calling me away

This place is my home
My mind still runs free
The doctor's prescription
Less for you and more for me

The coat of arms falling
I hear the doctor calling
The family crest is falling
I hear the doctor calling
I see the chalkline crawling
I hear the doctor calling me away
A merciful embalming
I hear the doctor calling me away
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define ttl 4888888
#define clone agsdahfaassdg

using namespace std;

long n,ar[200000],ss[200000],ps[200000],ans;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=n;i++)
ps[i]=ps[i-1]+ar[i];

for (int i=1;i<=n;i++)
ss[i]=ps[n]-ps[i];

for (int i=1;i<=n;i++)
if (ps[i-1]<=ss[i])ans++;
cout<<ans<<" "<<n-ans<<endl;
cin.get();cin.get();
return 0;}