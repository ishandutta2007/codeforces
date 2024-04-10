/*
Through the smoke of dancers move
Demonic dirty downtown groove
Visions of the day retreat
Come on baby feel the heat

Then I can disappear
And be at peace
But when my mind is clear
I can't get no release

In the dark the dancers shout
Scream the cry of freedom out
Strobe crescendos in the night
Minds take cover, souls take flight

Oh let me disappear
Set me free, set me free
But when my mind is clear
I can't get no release

Set me free, set me free baby
Well I can feel it yeah
I can feel it, feel it, feel it, feel it.
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

long long pw[1200000];
long n,m,a[1200000],b[1200000];
long long ans;
vector<long> g[1200000];
long long s[1200000];
long long t1,t2;
vector<long long> d;
long long calc;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw[0]=1;
for (int i=1;i<=1000000;i++)
 pw[i]=pw[i-1]*17;
 
cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i];
 g[a[i]].push_back(b[i]);
 g[b[i]].push_back(a[i]);
}

for (int i=1;i<=n;i++)
{
 for (int j=0;j<g[i].size();j++)
 {
  s[i]+=pw[g[i][j]];
 }
// ans+=calc[s[i]];
// calc[s[i]]++;
 d.push_back(s[i]);
}

sort(d.begin(),d.end());
calc=0;
for (int i=0;i<d.size();i++)
{
 if (i>0&&d[i]!=d[i-1])
 {
  ans+=1ll*calc*(calc-1)/2;
  calc=1;
 }
 else++calc;
}
ans+=1ll*calc*(calc-1)/2;

for (int i=1;i<=m;i++)
{
 t1=s[a[i]];
 t2=s[b[i]];
 t1-=pw[b[i]];
 t2-=pw[a[i]];
 if (t1==t2)++ans;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}