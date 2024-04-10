/*
Stormbound is our world, seething and confined
Profound is this Hell, draconian in design
Arise from slumber to the call of the awaker
Renounce your leaders and lead me to your undertaker

Deep in Death's realm we still lay hiding
For despite our demise we still keep dying

A dystopia formed from the traits of our kind
Incarceration unfitting our crime
Recall ideals we once held so uphigh
But the die was cast and we were all cast to die...

Lost in Death's realm we continue trying
For despite our demise we still keep dying

Dead and dying
Lifeless yet espying

Trapped in Death's realm we carry on denying
For despite our demise we still keep dying
In spite our cries the truth remains binding

Dead and dying
Deceased yet defying
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

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long long n,m,a,b,ans;
long w[2000];

void merg(long a,long b)
{
 while (a!=w[a])a=w[a];
 while (b!=w[b])b=w[b];
 w[b]=a;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 w[i]=i;
 
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 merg(a,b);
}

ans=(1ll<<n);
for (int i=1;i<=n;i++)
 if (w[i]==i)ans/=2;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}