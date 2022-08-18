/*
I'm, but a little bit bit bit, show
But a little bit bit bit, shame
But a little bit, bit, bit
Bit, bit, bit

I'm, but a little bit bit bit, show
But a little bit bit bit, shame
But a little bit, bit, bit
Bit, bit, bit

I'm just the man in the back
Just the man in the back
Just the man in the back

I'm just the man in the back
Just the man in the back
Just the man in the back

War
Fuck the system
War
Fuck the system
Fuck the system

War
Fuck the system
War
I need to fuck the sys
I need to fuck the sys
I need to fuck the sys

I'm, but a little bit bit bit, show
But a little bit bit bit, shame
But a little bit, bit, bit
Bit, bit, bit

I'm, but a little bit bit bit, show
But a little bit bit bit, shame
But a little bit, bit, bit
Bit, bit, bit

I'm just the man in the back
Just the man in the back
Just the man in the back

I'm just the man in the back
Just the man in the back
Just the man in the back

War
Fuck the system
War
Fuck the system
Fuck the system

War
Fuck the system
War
I need to fuck the sys
I need to fuck the sys
I need to fuck the sys

You need to fuck the sys
You need to fuck the sys
You need to fuck the sys
We all need to fuck the sys

I'm, but a little bit bit bit, show
But a little bit bit bit, shame
But a little bit, bit, bit
Bit, bit, bit

I need to fuck the system
I need to fuck the sys
I need to fuck the system
We all need to fuck the system
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

long long n,a,b,dp[300][300];
long long s;
vector<pair<long long,long long> > v;
long long r,tr;

long long gs(long long a,long long b,long long c)
{
 long long s=0;
 s=(v[b].first-v[a].first)*(v[c].second-v[a].second)-
 (v[b].second-v[a].second)*(v[c].first-v[a].first);
 return s;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{cin>>a>>b;v.push_back(make_pair(a,b));}

for (int i=0;i<n;i++)
 s+=v[(i+1)%n].first*v[i].second-v[(i+1)%n].second*v[i].first;

if (s<0)reverse(v.begin(),v.end());

for (int i=0;i<n;i++) 
 dp[i][(i+1)%n]=1;
 
for (int span=2;span<n;span++)
{
 for (int l=0;l<n;l++)
 {
  r=l+span;
  r%=n;
  for (int q=l+1;q<l+span;q++)
  {
   tr=q%n;
   if (gs(l,r,tr)>0)
   dp[l][r]=(dp[l][r]+dp[l][tr]*dp[tr][r])%bs;
  }
 }
}

cout<<dp[0][n-1]<<endl;

cin.get();cin.get();
return 0;}