/*
Hide my face again.
Harboring the shadows
Feel this weight of sin.
Hammering away.

Die, with the guilt of a thousand AWOL soldiers.
Die, watch the scythe usher me astray.

I can't go on this way.
Not as I am today.
The ugly side of me is strong.

Take aim, a loaded gun.
Pull back on all who run.
A coward's truth inside the wrong.

This means war! [3x]

Lash your tongue of bane.
Carry me to nowhere.
Mental holocaust.
Battle never ends.

Lie, mask the pain of a child who's forsaken.
Lie, to myself, praise the new regime.

I left me long ago.
Reasons you'll never know.
No one to miss me when I'm gone.

With no more words to say.
No argument to stay.
Another post I don't belong.

This means war! [5x]

No home to call my own.
No finding someone new.
No one to break the fall.
No one to see me through.

No name to carry on.
No promise for today.
No one to hear the call.
No tattered flag to raise.

Walk the razor's edge.
Cut into the madness
Question all you trust.
Buy into the fear.

I see the man ripping at my soul now
I, I know the man, I know him all too well.

There's nothing here for free.
Lost who I wanna be.
My serpent blood can strike so cold.

On any given day.
I'll take it all away.
Another thought I can't control.

This means war! [5x]
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long l,r;

long long gett(long long x,long long iters,long long block)
{
     long long temp=x;
     for (int i=1;i<iters;i++)
     x=(x<<block)+temp;
     return x;
}

long long solv(long long size,long long uplim)
{
 long long dp[100];
 for (int i=0;i<100;i++)
 dp[i]=0;
 for (int bsize=1;bsize<size;bsize++)
 {
  if (size%bsize)continue;
  
  long long tt,m,l,r;
  l=(1<<(bsize-1));
  r=l*2+1;
  while (l<r)
  {
   m=l+r+1;
   m/=2;
   tt=gett(m,size/bsize,bsize);
   if (tt>uplim)r=m-1;else l=m;
  }
//  cout<<l<<" "<<uplim<<" "<<bsize<<endl;
  tt=gett(l,size/bsize,bsize);
  if (tt>uplim)dp[bsize]=0;
  else dp[bsize]=l-(1<<(bsize-1))+1;
  
  for (int j=1;j<bsize;j++)
  if (bsize%j==0)dp[bsize]-=dp[j];   
 }
 /*for (int i=1;i<=size;i++)
 cout<<dp[i]<<" ";
 cout<<endl;
 */
 long long tans=0;
 for (int i=0;i<=size;i++)
 tans+=dp[i];
 return tans;
// return dp[size];
}

long long solve(long long num)
{
 vector<long> vec;
 long long ans=0;
 long long num1=num;
 while (num){vec.push_back(num%2);num/=2;}
 for (int sz=1;sz<=vec.size();sz++)
 {
     if (sz<vec.size())
     ans+=solv(sz,(1ll<<sz)-1);
     else ans+=solv(sz,num1);
 }
 return ans;
}

int main(){
//freopen("line3.in","r",stdin);
//freopen("line3.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>l>>r;
//cout<<gett(4,2,3)<<endl;

cout<<solve(r)-solve(l-1)<<endl;

cin.get();cin.get();
return 0;}