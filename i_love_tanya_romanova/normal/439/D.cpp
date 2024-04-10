/*
At the edge, looking up,
Shifting focus onto a majestic void.
Leaving myself open to let go,
Drift along and disappear.

I listen when you sing. Astral resonance rings.
My gaze ascends, never ends. Numbness strikes like fever.

Whispers generate waves;
I can't heed them all.

On my knees, mesmerized;
In awe of. Solarised.
Acceptance before I return to the stars.
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

long long n,m,a[200000],b[200000],l,r,mid1,mid2,ans;

long long solve(long long val)
{
 long long res=0;
 for (int i=1;i<=n;i++)
  if (a[i]<val)res+=val-a[i];
 for (int i=1;i<=m;i++)
  if (b[i]>val)res+=b[i]-val;
  return res;
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
 cin>>a[i];
for (int i=1;i<=m;i++)
 cin>>b[i]; 
l=0;
r=1e9;
while (l<r-5)
{
 mid1=l*2+r;
 mid2=l+r*2;
 mid1/=3;
 mid2/=3;
 if (solve(mid1)<solve(mid2))r=mid2;
 else l=mid1;
}

ans=1e18;
for (int i=l;i<=r;i++)
 ans=min(ans,solve(i));

cout<<ans<<endl;

cin.get();cin.get();
return 0;}