/*
Sailing of sea of lies
Of perfect unformity
Created stimulated
Fabricate the falsification

Suspension of Disbelief

And I fall into the ocean
Will you be there to rescue me?
As I start to take on water
Drowning me

Commencing your ending
Believing falsity
Your ending inception
Consummating your demise

Suspension of disbelief

And I fall into ocean
Will you be there to rescue me?
As i start to take on water
Drowning me

Sailing on the sea of doubt
Believing the forgery
Distorting your invention
Fabricate the falsification

Suspension of disbelief
Suspension of disbelief

And I fall into ocean
Will you be there to rescue me?
As I start to take on water
Drowning me

And I fall into ocean
Will you be there to rescue me?
As I start to take on water
Drowning me
Drowning me
Drowning me

Commencing your ending
Believing falsity
Your ending inception
Consummating your demise
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,m,ar[1200000],l,r,mid1,mid2;
long long ans;

long long gett(long long x)
{
 long long res=0;
 for (int i=1;i<=x;i++)
  if (i%m==1||m==1)
   res+=ar[x]-ar[i];
  for (int i=n;i>=x;--i)
   if (i%m==n%m)res+=ar[i]-ar[x];
  return res*2;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar[i];

l=1;
r=n;
while (l<r-5)
{
 mid1=l*2+r;
 mid2=l+2*r;
 mid1/=3;
 mid2/=3;
 if (gett(mid1)<gett(mid2))r=mid2;
 else l=mid1;
}
ans=1e18;
for (int i=l;i<=r;i++)
 if (i>=1&&i<=n)
 ans=min(ans,gett(i));

cout<<ans<<endl;

cin.get();cin.get();
return 0;}