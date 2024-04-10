/*
Let's have a black celebration
Black celebration
Tonight

To celebrate the fact
That we've seen the back
Of another black day

I look to you
How you carry on
When all hope is gone
Can't you see

Your optimistic eyes
Seem like paradise
To someone like
Me

I want to take you
In my arms
Forgetting all I couldn't do today

Black celebration
Black celebration
Tonight

I look to you
And your strong belief
Me, I want relief
Tonight

Consolation
I want so much
Want to feel your touch
Tonight

Take me in your arms
Forgetting all you couldn't do today

Black celebration
I'll drink to that
Black celebration
Tonight
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

long xs,ys,x[30],y[30],dp[1<<24],par[1<<24];
long n,q,td;

long gd(long x1,long y1,long x2,long y2)
{
 return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>xs>>ys;
cin>>n;
for (int i=0;i<n;i++)
{
 cin>>x[i]>>y[i];
}

for (int i=0;i<(1<<n);i++)
 dp[i]=1e9;

dp[0]=0;
for (int mask=0;mask<(1<<n);mask++)
{
 if (mask+1==(1<<n))continue;
 q=0;
 while (mask&(1<<q))++q;
 
 td=dp[mask]+gd(xs,ys,x[q],y[q])*2;
 if (td<dp[mask|(1<<q)])
 {
  dp[mask|(1<<q)]=td;
  par[mask|(1<<q)]=mask;
 }
 
 for (int e=q+1;e<n;e++)
  if ((mask&(1<<e))==0)
  {
   td=dp[mask]+gd(xs,ys,x[q],y[q])+gd(xs,ys,x[e],y[e])+gd(x[q],y[q],x[e],y[e]);
   if (td<dp[mask|(1<<q)|(1<<e)])
   {
    dp[mask|(1<<q)|(1<<e)]=td;
    par[mask|(1<<q)|(1<<e)]=mask;
   }
  }
}

cout<<dp[(1<<n)-1]<<endl;

cout<<0;

long mask=(1<<n)-1;
while (mask>0)
{
 vector<long> v;
 long tmask=par[mask];
 for (int i=0;i<n;i++)
 {
  if (mask&(1<<i))
   if ((tmask&(1<<i))==0)
    cout<<" "<<i+1;
 }
 cout<<" "<<0;
 mask=tmask;
}
cout<<endl;

cin.get();cin.get();
return 0;}