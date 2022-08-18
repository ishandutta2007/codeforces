/*
It's hard to forgive a man who bought revenge with his soul.
A vein injected with a man's life and his goals.
It's in my face, it hurts and I fall into a hollow sphere.
Well, I don't want that to happen to me.

I don't want to see what my face might be.
Damn your shameful lies as my conscience it dies.

Stop and listen as silence roars out in the night.
One can't fake that anger and oh it's shining so bright.
Is this my fault, I will light it up to see. I will light it up.
I don't really see, I don't want to be. Is this my fault.
I don't see, inside of me a moment turns to infinity.

I don't want to see what my face might be.
Damn your shameful lies as my conscience it dies.

I just might hurt you my friend.

All that was left for me was destructive in misery.
I blame you for all that I did; it's eating me bit by bit.
How can all this be true, I blame it all on you.
Electrocuted with a sense of loss. Anxiety will see me through.

Flipping through the pages of a mind that hurts me.
Sometimes I wish that I could eject from this seat of pain I'm fuckin?
Placed in and let it go.

You tell me what you think of me and my sense of energetic rage compiled
Into a ball of anxiety.
Do I need your help? Do I need you?
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

long long w,h,calc[3][3],s;
long long ways;
long long ttl,inm;

long gcd(long a,long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

long long m1,m2,m3;

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

long long solv(long x0,long y0,long x1,long y1,long x2,long y2)
{
 long long res=0;
 if (x0==x2&&y0==y2)// 3 same
 {res=calc[x0][y0]*(calc[x0][y0]-1);
 res%=bs;
 res*=calc[x0][y0]-2;
 res%=bs;
 res*=inv(6);
 res%=bs;
 return res;}
 
 if (x0==x1&&y0==y1)
 {
  res=calc[x1][y1]*(calc[x1][y1]-1);
  res%=bs;
  res*=calc[x2][y2];
  res%=bs;
  res*=inv(2);
  res%=bs;
  return res;
 }
  if (x2==x1&&y2==y1)
 {
  res=calc[x1][y1]*(calc[x1][y1]-1);
  res%=bs;
  res*=calc[x0][y0];
  res%=bs;
  res*=inv(2);
  res%=bs;
  return res;
 }
 res=calc[x1][y1]*calc[x0][y0];
 res%=bs;
 res*=calc[x2][y2];
 return res%bs;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>w>>h;
for (int i=0;i<=w;i++)
 for (int j=0;j<=h;j++)
 {
  calc[i%2][j%2]++;
 }

 for (int x0=0;x0<=1;x0++)
 for (int y0=0;y0<=1;y0++)
  for (int x1=0;x1<=1;x1++)
   for (int y1=0;y1<=1;y1++)
    for (int x2=0;x2<=1;x2++)
     for (int y2=0;y2<=1;y2++)
     {
      m1=x0*2+y0;
      m2=x1*2+y1;
      m3=x2*2+y2;
      if (m1>m2)continue;
      if (m2>m3)continue;
      s=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
      s=abs(s);
      if (s%2)continue;
      ways+=solv(x0,y0,x1,y1,x2,y2);
      while (ways<0)ways+=bs;
      ways%=bs;
//      cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<
//      " "<<ways<<endl;
     }

// - lines;

//cout<<ways<<endl;

// 3ln
for (int dx=0;dx<=w;dx++)
 for (int dy=0;dy<=h;dy++)
 {
  if (dx+dy==0)continue;
  ttl=(w-dx+1)*(h-dy+1);
  if (dx>0&&dy>0)ttl*=2;
  inm=gcd(dx,dy);
  ways=ways-(inm-1)*ttl;
  ways%=bs;
  while (ways<0)ways+=bs;
//  cout<<dx<<" "<<dy<<" (("<<ways<<endl;
 }

//cout<<ways<<endl;

cout<<ways*6%bs<<endl;
 
cin.get();cin.get();
return 0;}