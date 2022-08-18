/*
Shadow on my shoulder
Someone's watching me
Shadow on my shoulder
A lost entity
Subtle and silent
A whisper on the wind
Benevolent and quiet
Uneasiness sets in

Covert and controlling
Random acts of fate
Conscious yet consolling
Opportunity's the bait
Coincidence, cohesion
Right time and place
Spirit of believing
In that mindspace

Evidence can only be found within
Feel the presence under your skin
Shouldn't fear what you can't see
What will be is supposed to be
Let the spirit free

Shadow on your shoulder
Someone's watching you
Shadow on your shoulder
You can't believe it's true
Subtle and silent
A whisper on the wind
Benevolent and quiet
Uneasiness within

Paranormal, paranormal
Paranormal
Paranormal, paranormal
Paranormal

Evidence can only be found within
Feel the presence under your skin
Shouldn't fear what you can't see
What will be is supposed to be
Let the spirit free
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

long long n,m,l,r,p,span,t,lwr,upr;
long pr[200000];
vector<long> vec[200000];
long calc[200000];
long long res,nmoves[200000];
long long check[200000];
long long temp;
long long answ;

long long gcd(long long a,long long b)
{
 while(a&&b)a>b?a%=b:b%=a;
 return a+b;
}

long long solve1(long long x,long long lim)
{
 long long res=0;
 for (int mask=0;mask<(1<<(vec[x].size()));mask++)
 {
  temp=1;
  //cout<<temp<<"   "<<calc[mask]<<" "<<res<<endl;
  
  for (int j=0;j<vec[x].size();j++)
  if (mask&(1<<j))temp*=vec[x][j];
  if (calc[mask]%2)res-=lim/temp;else res+=lim/temp;
 }
 return res;
}

long long solve(long long x,long long lim)
{
 long long res=0;
 long long ts=0;
 long long q,qsum;
 
 for (int mask=0;mask<(1<<(vec[x].size()));mask++)
 {
  temp=1;
  //cout<<temp<<"   "<<calc[mask]<<" "<<res<<endl;
  
  for (int j=0;j<vec[x].size();j++)
  if (mask&(1<<j))temp*=vec[x][j];
  q=lim/temp;
  qsum=q*(q+1)/2;
  qsum*=temp;
  if (calc[mask]%2)res-=qsum;else res+=qsum;
 }
 return res;
}

long long gett(long long g,long long x,long long lim)
{
 if (lim<=0)return 0;
// cout<<g<<"   "<<x<<" "<<lim<<endl;
// cout<<solve1(x,lim)<<" "<<solve(x,lim)<<endl;
 long long tsum=(g+1)*solve1(x,lim);
 tsum-=solve(x,lim);
// cout<<tsum<<endl;
// cout<<"#"<<endl;
 return tsum;
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

pr[1]=1;
for (int i=2;i<=100000;i++)
if (pr[i]==0)
 for (int j=i*2;j<=100000;j+=i)
 {
  pr[j]=1;
  vec[j].push_back(i);
 }

// dmask
for (int i=2;i<=100000;i++)
if (pr[i]==0)vec[i].push_back(i);

// bc
calc[0]=0;
for (int i=1;i<=(1<<15);i++)
{
 t=i;
 for (int j=0;j<15;j++)
 if (t&(1<<j))++calc[i];
}



long long a,b;

/*
while (cin>>a>>b)
{
      cout<<solve(a,b)<<" "<<solve1(a,b)<<endl;
}*/


cin>>n>>m;
cin>>l>>r>>p;
l*=l;
r*=r;

for (long long span=2;span<=100000&&span<=n;span++)
{
 if (span*span>r)continue;
 t=l-span*span;
 
 if (t<=0)lwr=0;
 else lwr=sqrt(t-0.5)+1;
 t=r-span*span;
 upr=sqrt(t+0.5);
 
 if (upr>=span)upr=span-1;
 if (upr>m)upr=m;
 
 if (upr<lwr)continue;
 //cout<<span<<" "<<lwr<<" "<<upr<<endl;
 res=(gett(m,span,upr)-gett(m,span,lwr-1))*(n-span+1)*2;
 answ=answ+res;
 answ%=p;
}

swap(n,m);

for (long long span=2;span<=100000&&span<=n;span++)
{
 if (span*span>r)continue;
 t=l-span*span;
 
 if (t<=0)lwr=0;
 else lwr=sqrt(t-0.5)+1;
 t=r-span*span;
 upr=sqrt(t+0.5);
 
 if (upr>=span)upr=span-1;
 if (upr>m)upr=m;
 
 if (upr<lwr)continue;
 //cout<<span<<" "<<lwr<<" "<<upr<<endl; 
 res=(gett(m,span,upr)-gett(m,span,lwr-1))*(n-span+1)*2;
 answ=answ+res;
 answ%=p;
}

//cout<<answ<<endl;

if (1>=l&&1<=r)
answ+=n*(m+1),answ+=m*(n+1);

if (2>=l&&2<=r)
answ+=2*n*m;
cout<<answ%p<<endl;
/*
long dx,dy;
for (int x1=0;x1<=n;x1++)
 for (int y1=0;y1<=m;y1++)
  for (int x2=0;x2<=n;x2++)
   for (int y2=0;y2<=m;y2++)
   {
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if (dx*dx+dy*dy<l||dx*dx+dy*dy>r)continue;
    if (x2<x1||(x2==x1&&y2<y1))continue;
    if (gcd(dx,dy)==1)--answ;
   }
cout<<answ<<endl;
*/
cin.get();cin.get();
return 0;}