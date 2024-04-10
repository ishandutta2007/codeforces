/*
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,tests,ar[1<<21];
long long val;
long long s;
long r;
long nw;
long jump[21][1<<21];
long upr;
long mx;

void build()
{
 r=1;
 s=ar[1];
 for (int l=1;l<=n;l++)
 {
  while (s+ar[r+1]<=val&&r+1<=n*2)
  {
   s+=ar[r+1];
   r++;
  }
  s-=ar[l];
  jump[0][l]=r-l+1;
 }
 for (int lev=1;lev<=upr;lev++)
 {
  for (int i=1;i<=n;i++)
  {
   nw=i+jump[lev-1][i];
   while (nw>n)nw-=n;
   jump[lev][i]=jump[lev-1][i]+jump[lev-1][nw];
   if (jump[lev][i]>n+1)jump[lev][i]=n+1;
  }
 }
}

long cur,ttl;
long rem;

long solve()
{
 long ans=n;
 for (int i=1;i<=jump[0][1]+1&&i<=n;i++)
 {
  cur=i;
  rem=n;
  ttl=0;
  for (int j=upr;j>=0;--j)
  {
//   cout<<cur<<" "<<j<<" "<<ttl<<" "<<rem<<" "<<jump[j][cur]<<endl;
   if (jump[j][cur]<=rem||(j==0&&rem>0))
   {
    ttl+=(1<<j);
    rem-=jump[j][cur];
    cur+=jump[j][cur];
    if (cur>n)cur-=n;
   }
  }
  if (rem>0)++ttl;
  ans=min(ans,ttl);
 }
 return ans;
}

long glg(long x)
{
 long s=0;
 while (x){s++;x/=2;}
 return s;
}
set<long long> done;
map<long long,long long> mapp;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

scanf("%ld",&n);
scanf("%ld",&tests);

for (int i=1;i<=n;i++)
{
 scanf("%ld",&ar[i]);
 if (ar[i]>mx)mx=ar[i];
// ar[i]=rand();
}

for (int i=n+1;i<=n*2;i++)
 ar[i]=ar[i-n];
 
 
for(;tests;--tests)
{
 cin>>val;
 upr=n/(val/mx)+(n%(val/mx)>0);
 //cout<<"%"<<upr<<endl;
 upr=glg(upr)+1;
 if (upr>19)upr=19;
 upr=19;
//val=1e15;
/* for (int i=1;i<=n;i++)
  cout<<"%"<<jump[0][i]<<" ";
 cout<<endl;
 */
 if (done.find(val)!=done.end())
 {
  cout<<mapp[val]<<endl;
  continue;
 }
 build();
 long long res=solve();
 done.insert(val);
 mapp[val]=res;
 cout<<res<<endl;
}

cin.get();cin.get();
return 0;}