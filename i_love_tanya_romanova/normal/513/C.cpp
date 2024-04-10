/*
Hide from the public eye, choose to appear when it suits you
Claim you're just, killing women and children
Fight, when you choose to fight, hide in a cave when you're hunted
Like a beast spawned from hell, utilizing fear

Chosen by god or a coward insane?
Stand up and show me your face!

Suicidal, in a trance
A religious army
Fight without a uniform and hide in the crowd
Call it holy, call it just
Authorized by heaven
Leave your wounded as they die, and call it gods will

Run when its time to pay, fear consequence of your action
Reappear, when you're almost forgotten
Dream of a world in peace, yet you cause pain and destruction
Kill your own, a response of your actions

Captured in all you lies, fear is in your eyes
Creature who's gone insane, your war is in vain
Trapped in a cage of stone, we'll destroy your home
Consequence of your action
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
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,l[10],r[10];
double p[1<<20];
long gb(long x)
{
 long s=0;
 for (int i=0;i<=5;i++)
  if (x&(1<<i))
   s++;
  return s;
}

long gp(long l1,long r1,long l2,long r2)
{
 l1=max(l1,l2);
 r1=min(r1,r2);
 if (l1>r1)
  return 0;
  return r1-l1+1;
}

double solve(long mask,long val)
{
 double p=1.0;
 for (int i=0;i<n;i++)
  if (mask&(1<<i))
  {long ttl=r[i]-l[i]+1;
   p*=1.0*gp(l[i],r[i],val,10000)/ttl;
  }
 return p;
}

double ev;
long brute()
{
 vector<long> v;
 for (int i=0;i<n;i++)
 {
  long temp=rand()%(r[i]-l[i]+1);
  temp+=l[i];
  v.push_back(temp);
 }
 sort(v.begin(),v.end());
 reverse(v.begin(),v.end());
 return v[1];
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
 cin>>l[i]>>r[i];

for (int val=1;val<=10000;val++)
{
 p[val]=0;
 for (int mask=0;mask<(1<<n);mask++)
 {
  long bts=gb(mask);
  if (bts<2)continue;
  if (bts==2)
   p[val]+=solve(mask,val);
  else if (bts==3)
  {
   p[val]-=2*solve(mask,val);
  }
  else if (bts==4)
  {
   p[val]+=3*solve(mask,val);
  }
  else
   p[val]-=4*solve(mask,val);
 }
/* if (p[val]>0)
  cout<<val<<"  "<<p[val]<<endl;*/
}

p[0]=1;

for(int i=10001;i;--i)
 p[i]=p[i-1]-p[i];
double res=0;

for (int i=1;i<=10001;i++)
 res+=p[i]*i;
 /*
for (int i=1;i<=10;i++)
 cout<<p[i]<<" ";
 cout<<endl;
 */
 cout.precision(9);
 cout<<fixed<<res-1<<endl;
/*
for (int iter=1;iter<=20000;iter++)
{
 ev+=brute();
}
cout<<ev/20000<<endl;
*/
cin.get();cin.get();
return 0;}