/*
I have come to the end of my line
With these final steps I take back my freedom
Unchain the shackles that never could hold my mind

Time keeps running and running
Outstripping the dead tired ones
The hours will run out from us all
And in the end no one differs from the other

Only the blue sky and the green grass
Go on forever in this world
Where seconds feel like eternity
And years pass in blink of an eye

When the last rays of light
Set behind these shores
Night wraps me in its blanket
And leads my way to the stars

Through the fear and the ache
Pass the storm and the rain
I have made peace with the world
I am born again

I may be gone in the flesh
But my love will stay here
I am always with you in spirit
So just stay strong

No one wins tonight
No one gets a closure
No one walks away victorious

But don't forget me
Don't you forget me
Burn a candle for me when you can
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

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define bsize 256

using namespace std;

long n,m,px[200000],py[200000],gx[200000],gy[200000];
double sy,minx,maxx,miny,maxy,mid1,mid2;

double eval(double x,double y)
{
 double s=0;
 for (int i=0;i<n;i++)
 s+=(x-gx[i])*(x-gx[i])+(y-gy[i])*(y-gy[i]);
 return s;
}

double get(double x)
{
 miny=1e9;
 maxy=-1e9;
 for (int i=0;i<m;i++)
 {
  if (px[i]!=px[i+1]&&min(px[i],px[i+1])<=x&&max(px[i],px[i+1])>=x)
  {
   double y=py[i]+(py[i+1]-py[i])*(x-px[i])/(px[i+1]-px[i]);
   miny=min(miny,y);
   maxy=max(maxy,y);
  }
 }
 if (sy>maxy)return eval(x,maxy);
 if (sy<miny)return eval(x,miny);
 return eval(x,sy);
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>gx[i]>>gy[i];
 sy+=gy[i];
}
sy/=n;

cin>>m;
minx=1e9;maxx=1e9;

for (int i=0;i<m;i++)
{
 cin>>px[i]>>py[i];
 minx=min(minx,px[i]+.0);
 maxx=max(maxx,px[i]+.0);
}

px[m]=px[0];py[m]=py[0];

double l,r;
l=minx;
r=maxx;

while (l<r-eps)
{
 mid1=2*l+r;
 mid2=l+2*r;
 mid1/=3,mid2/=3;
// cout<<get(l)<<" "<<get(r)<<" "<<get(mid1)<<" "<<get(mid2)<<endl;
 if (get(mid1)>get(mid2))l=mid1;
 else r=mid2;
}
cout.precision(12);
cout<<fixed<<get(l)<<endl;

cin.get();cin.get();
return 0;}