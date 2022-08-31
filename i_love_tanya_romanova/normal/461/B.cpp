/*
Lost in a dream nothing's what it seems
Searching my head for the words that you said
Tears filled my eyes as we said our last goodbyes
The sad scene replays of you walking away

My body aches from mistakes betrayed by lust
We lied to each other so much that in nothing we trust

Time and again she repeats let's be friends
I smile and say yes another truth bends, I must confess
I try to let go, but I know we'll never end 'til we're dust
We lied to each other again but I wish I could trust

My body aches from mistakes betrayed by lust
We lied to each other so much that in nothing we trust
God help me please, on my knees betrayed by lust
We lied to each other so much now there's nothing we trust

How could this be happening to me I'm lying when I say, "Trust me"
I can't believe this is true trust hurts, why does trust equal suffering?

My body aches from mistakes betrayed by lust
We lied to each other so much that in nothing we trust
God help me please, on my knees betrayed by lust
We lied to each other so much now there's nothing we trust

My body aches from mistakes betrayed by lust
We lied to each other so much that in nothing we trust
God help me please, on my knees betrayed by lust
We lied to each other so much now there's nothing we trust
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
#define right adsgasgadsg

using namespace std;

long long n,p[500000],dp[500000][2];
vector<long long> g[500000];
long long cl[500000];
long long t[1000000];

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2)return a*pw(a,b-1)%bs;
 return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
 return pw(x,bs-2);
}

void update(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  t[v]=val;
  return;
 }
 long mid=tl+tr;
 mid/=2;
 if (ps<=mid)update(v*2,tl,mid,ps,val);
 else update(v*2+1,mid+1,tr,ps,val);
 t[v]=(t[v*2]*t[v*2+1])%bs;
}

long long gett(long v,long tl,long tr,long l,long r)
{
 if (l>r)return 1;
 if (l==tl&&r==tr)return t[v];
 long tm=tl+tr;
 tm/=2;
 long long res=gett(v*2,tl,tm,l,min(r,tm))*
 gett(v*2+1,tm+1,tr,max(l,tm+1),r);
 return res%bs;
}

void solve(long v)
{
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i];
     solve(q);
 }
 if (cl[v]==0)dp[v][0]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  dp[v][0]=(dp[v][0]*(dp[q][0]+dp[q][1]))%bs;
 }
 if (cl[v]==1)
 {
  dp[v][1]=1;
  for (int i=0;i<g[v].size();i++)
  {
   long q=g[v][i];
   dp[v][1]=(dp[v][1]*(dp[q][0]+dp[q][1]))%bs;
  }
  return ;
 }
 
 long nn;
 nn=g[v].size();
 for (int i=0;i<nn;i++)
 {
  long q=g[v][i];
  update(1,0,nn-1,i,(dp[q][0]+dp[q][1])%bs);
 }
 for (int i=0;i<nn;i++)
 {
  long long temp=1;
  long q=g[v][i];
  temp*=dp[q][1];
  temp*=gett(1,0,nn-1,0,i-1);
  temp%=bs;
  temp*=gett(1,0,nn-1,i+1,nn-1);
  temp%=bs;
  dp[v][1]+=temp;
  dp[v][1]%=bs;
 }
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>p[i];
    g[p[i]].push_back(i);
}

for (int i=0;i<n;i++)
 cin>>cl[i];

solve(0);
cout<<dp[0][1]%bs<<endl;
 
cin.get();cin.get();
return 0;}