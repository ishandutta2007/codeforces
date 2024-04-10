/*
Sonic fires bring mass devastation,
Manic search in sad desperation,
Jeopardise the right to hide from a sad existence,
Nothing left, still searching for something,
Deep beneath the cries
Wait for the deafening silence, fly forever more.

Crushed by the thought that you're all alone, cravation in her eyes,
I will be waiting tomorrow,
Striving to understand, wasting a life not meant to be,
Twisted and so broken once again,
And the promises we cast away will shine a guiding light,
Victim of your grief and denial.

[Chorus:]
Take my hand, this one last time,
Face the world before us, the warrior inside,
In a lifetime of disaster, it's a battle to the end,
Final stand, my life must carry on,
And forever, this time.

Battered, beaten, forced to submission,
Stricken by your fatal decision,
Suddenly it's time to say your last goodbyes,
Misery remains voluntary, all illusion gone,
Break through the blistering madness,
Free forever more.

Blinded my eyes with your filtering mutation cast aside,
I'll still be waiting tomorrow,
Stand to a toxic man, forced to a life of yesterday,
Theatre of salvation crushed and burned,
Down this lonely road, recede the day our dreams are brushed,
Can't regain this emptiness in time.

[Chorus]

See through the skies,
Far beyond the road tonight,
Here the sounds of freedom ring,
In a silent dream, and a million miles away.

See through the skies, far beyond our world tonight,
Hear the sounds of freedom ring,
In a silent dream,
And a million miles away.

Reach for the stars,
And live our lives forever free,
In our hearts for a thousand years,
And a thousand lifetimes before.

And the dawn of a new day will rise, a light for us all.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long dv[2000000],used[2000000],n,m,
tp,lvl[200000],l[200000],r[200000],val[200000];
long L[200000],R[200000];
long ttl,qlvl,qv,ans;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<=20;i++)
{
 dv[1<<i]=1;
}
for (int i=1;i<=1000000;i++)
dv[i]+=dv[i-1];

cin>>n>>m;
for (int i=0;i<=1000000;i++)
used[i]=-1;

for (;m;--m)
{
 cin>>tp;
 if (tp==1)
 {
  cin>>lvl[ttl]>>l[ttl]>>r[ttl]>>val[ttl];
  ++ttl;
  continue;
 }
 cin>>qlvl;
 cin>>qv;
 ans=0;
 L[qlvl]=qv-1;
 R[qlvl]=qv;
 for (int i=qlvl+1;i<=n;i++)
 {
  L[i]=L[i-1]+dv[L[i-1]];
  R[i]=R[i-1]+dv[R[i-1]];
 }
 ans=0;
 for (int i=0;i<ttl;i++)
 {
  if (lvl[i]>=qlvl&&max(L[lvl[i]]+1,l[i])<=min(R[lvl[i]],r[i])&&used[val[i]]!=m)
  {
   used[val[i]]=m;
   ++ans;
  }
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}