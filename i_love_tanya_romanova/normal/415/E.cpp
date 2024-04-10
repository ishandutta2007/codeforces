/*
Stroboscopic contortion, assault
Light bulb language translated into fits
Codes of tendon flickers I can't grasp
Focus lost as I writhe and twitch

Random beats of blinding shock waves
Erratic suns that twist my eyes
Flashes pounding at my thoughts
As the intrinsic pains multiply

Muscle and tissue twined with every violent lash
Battered by an unrelenting shine
Immobilized by the increasing pains
The procreating agonies of system breakdown

Light wave frequency, body oscillation
Undeciphered motions pass through my flesh
Bodily reverberation induced
A corporeal system lost in its waves

Bleached into their existence
By tremulous epileptic strokes
Blasts of irregular pulsar radiation
Triggering the process of mind and body control

Lost to their control
A sentence, in flashes told
Enticed by their calls
Insane, divine

Torn, undone, dissolved
By incandescent gods condemned
Burned their mark on my soul
To my inverted shadow confined

Twisted, spun vertebras
And spinal column unaligned
Joints shattered and torn apart
Spasm rendered distortion

Organic spiral stretched
And torn into a new creation
A world less thing, a thing less world
Light born malformation
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

long n,input[1200000];
vector<long> v;
map<long,long> mapp;
long calc;
long long span,tinv[200],linv[200];
long long p;
vector<pair<long, long> >ad;
long tests;
long lvl;
long long answ;
long vars[1200000];

class Fenwick
{
 long *m,*mt,N;
 public:
 Fenwick(long n);
 Fenwick( long a[],long n);
 void add_range(long l,long d);
 void add_range(long l,long r,long d);
 long sum(long r);
 long sum(long l,long r);
};

Fenwick::Fenwick(long n)
{
 N=n;
 m=new long[N];
 mt=new long[N];
 for (int i=0;i<n;i++)
 m[i]=mt[i]=0;
}

void Fenwick::add_range(long r,long d)
{
 if (r<0)return;
 for (int i=r;i>=0;i=(i&(i+1))-1)mt[i]+=d;
 for (int i=r|(r+1);i<N;i|=i+1)m[i]+=d*(r-(i&(i+1))+1);
}

void Fenwick::add_range(long l,long r,long d)
{
 add_range(r,d);
 add_range(l-1,-d);
}

long Fenwick::sum(long r)
{
 if (r<0)return 0;
 long long res=0;
 for (int i=r;i>=0;i=(i&(i+1))-1)res+=m[i]+mt[i]*(i-(i&(i+1))+1);
 for (int i=r|(r+1);i<N;i|=i+1)res+=mt[i]*(r-(i&(i+1))+1);
 return res;
}

long Fenwick::sum(long l,long r)
{
 return sum(r)-sum(l-1);
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
/*for (int i=0;i<(1<<n);i++)
input[i]=i;
random_shuffle(input,input+(1<<n));
*/
for (int i=0;i<(1<<n);i++)
{
// cin>>input[i];
scanf("%d",&input[i]);
 vars[i]=input[i];
 v.push_back(input[i]);
}

sort(v.begin(),v.end());
reverse(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 if (i==0||v[i]!=v[i-1])
 {
  mapp[v[i]]=calc+1;
  calc++;
 }
}

for (int i=0;i<(1<<n);i++)
{
 input[i]=mapp[input[i]];
 //cout<<input[i]<<endl;
 ad.push_back(make_pair(input[i],-i));
}

sort(ad.begin(),ad.end());

Fenwick inv(1100100);

for (int pp=0;pp<(1<<n);pp++)
{
    long i=-ad[pp].second;
    for (int lev=1;lev<=n;lev++)
    {
     span=i%(1<<lev);
     p=i-span;
     if (span<(1<<(lev-1)))continue;
     linv[lev]+=inv.sum(p,p+(1<<(lev-1))-1);
  //   cout<<i<<"   "<<lev<<" "<<linv[lev]<<" "<<p<<"  "<<p+(1<<(lev-1))<<endl;
    }
    inv.add_range(-ad[pp].second,-ad[pp].second,1);
  //  cout<<tinv<<endl;
}

for (int lev=1;lev<=n;lev++)
 tinv[lev]=linv[lev];

/*for (int lev=1;lev<=n;lev++)
 cout<<"%"<<tinv[lev]<<endl;
 */
Fenwick inv1(1100100);

// rinv

ad.clear();
for (int i=0;i<(1<<n);i++)
{
 input[i]=calc-input[i]+1;
// cout<<input[i]<<endl;
 ad.push_back(make_pair(-input[i],i));
}

sort(ad.begin(),ad.end());
for (int pp=0;pp<(1<<n);pp++)
{
//    cout<<ad[pp].first<<"  "<<ad[pp].second<<endl;
    long i=ad[pp].second;
    for (int lev=1;lev<=n;lev++)
    {
     span=i%(1<<lev);
     p=i-span+(1<<(lev-1));
     if (span>=(1<<(lev-1)))continue;
     tinv[lev]+=inv1.sum(p,p+(1<<(lev-1))-1);
   //  cout<<i<<"   "<<lev<<" "<<tinv[lev]<<" "<<p<<"  "<<p+(1<<(lev-1))<<endl;
    }
    inv1.add_range(ad[pp].second,ad[pp].second,1);
  //  cout<<tinv<<endl;
}

/*
for (int i=1;i<=n;i++)
{
 cout<<tinv[i]<<" "<<linv[i]<<endl;
}*/

cin>>tests;
for (;tests;--tests)
{
// cin>>lvl;
scanf("%d",&lvl);
 for (int i=lvl;i>0;--i)
  linv[i]=tinv[i]-linv[i];
 answ=0;
 for (int i=1;i<=n;i++)
 answ+=linv[i];
 printf("%I64d\n",answ);
//cout<<answ<<endl;
/*for (int i=0;i<(1<<n);i+=(1<<lvl))
reverse(vars+i,vars+i+(1<<lvl));
answ=0;
for (int i=0;i<(1<<n);i++)
 for (int j=0;j<i;j++)
 {
   if (vars[i]<vars[j])++answ;
 }
 cout<<answ<<endl;*/
}

//cout<<tinv<<endl;


cin.get();cin.get();
return 0;}