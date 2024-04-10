/*
This dreary darkened sky
in which I float benumbed
into my Enola-gay filled with ambitions failed
and when it will collide with the towers of madness
I'll fall off to the ground
hope will flow out from my wounds
some unfit dog shall spell a tear of grief

Far at east, by the silky way
the mirage of a forgotten town rescuse me
in storms religions lost and empty sanctuaries
I let my body being slowly buries along other fools

To the silence we belong,
and the silence in this wilderness throve
the Via Crucis across the Dead Sea
then caught in Samarkand bazaar dream

No, don't search for me at North
where the nonsense of my frienzied notes lead
as now I am the Czar

In sleep I spread my veils
as day is much too harsh to sail
while dream are bright and manifold
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,ar[200000];
set<long> bad;
long q;
long ans,s,tans;
long temp;
long gcd(long a,long b)
{
 while( a&&b)a>b?a%=b:b%=a;
 return a+b;
}

set<long>done;
map<long, long> val;
long ps,tcost;

long gett(long x)
{
 long xx=x;
 if (done.find(x)!=done.end())return val[x];
 done.insert(x);
 long cost=0;
 
 for (int i=2;i*i<=x;i++)
 {
  while (x%i==0)
  {
   if (bad.find(i)!=bad.end())
   cost--;
   else cost++;
   x/=i;
  }
 }
 
 if (x>1)
 {
  if (bad.find(x)==bad.end())
   cost++;
   else cost--;
 }
// cout<<"%"<<xx<<" "<<cost<<endl;
 val[xx]=cost;
 return cost;
}

void showw(long x)
{
 for (int i=2;i<=x;i++)
 {
  while(x%i==0){cout<<i<<" ";x/=i;}
 }
 cout<<endl;
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=1;i<=m;i++)
{
  cin>>q;
  bad.insert(q);
}

while (true)
{
 ps=0;
 temp=0;
 tcost=0;
 
 for (int i=1;i<=n;i++)
 {
  temp=gcd(temp,ar[i]);
  if (gett(temp)<0)ps=i,tcost=temp;
  //cout<<temp<<" "<<gett(temp)<<endl;
  //showw(temp);
 }
 if (ps==0)break;
 for (int i=1;i<=ps;i++)
 ar[i]/=tcost;
// cout<<ps<<endl;
 
}

for (int i=1;i<=n;i++)
ans+=gett(ar[i]);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}