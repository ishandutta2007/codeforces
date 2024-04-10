/*
I descended from the Mount Sinai
Unleashed the splendour upon a scroundel mob
To shelter where no messianic light
Drove one single ray into the pulp ov life
O sweet Salome I beckon thee
Bring forth thy heinous offering
Without your love
So incomplete
Corrupt me with your dignity

I decompose in rapture ov hells
Dissolve divide disintegrate
I am yours
In euphoria below

At faintest whim they would impale the sun
And thus the sheep in me became the wolf in man
I am the fly that flew forth from the ark
My thoughts like insects
Whoring wounds divine
Been bored with cosmos my dear old foe
This universe has never been enough
Compelled to liberate the spring ov life
When the levee breaks gush forth o' stream ov ice

I decompose in rapture ov hells
Dissolve divide disintegrate
I am yours
In euphoria below

I cast my halo from perdition's clay
Behold my bliss profane
Born ov a lie
Condemned to lurk
Live in denial
Yet coiled aflame...

I am the great rebellion
Neath Milton's tomb I dwell
An existence even sin would not pardon
No guilt, no reason, saviour, or shame
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
#define bsize 512

using namespace std;

long n,m,ar[1<<17],tp,q,a,b;
long ps;
pair<pair<long, long>, long> ans[1<<17];

void rebuild(long x)
{
 ps=x*bsize+bsize-1;
 if(ps>=n)ps=n-1;
 for (int i=ps;i>=0&&i/bsize==x;--i)
 {
  if (i+ar[i]>=n||(i+ar[i])/bsize>x)
  {
   ans[i]=make_pair(make_pair(i,i+ar[i]),1);
  }
  else
  {
   ans[i]=make_pair(make_pair(ans[i+ar[i]].first.first,ans[i+ar[i]].first.second),ans[i+ar[i]].second+1);
  }
 }
}

pair<long, long> solve(long x)
{
 long s=0;
 long aa=0;
 while (x<n)
 {
  pair<pair<long, long>,long> tp=ans[x];
  s+=tp.second;
  aa=tp.first.first;
  x=tp.first.second;
 }
 return make_pair(aa,s);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
}

for (int i=0;i<=n/bsize;i++)
 rebuild(i);

for (;m;--m)
{
 cin>>tp;
 if (tp==1)
 {
  cin>>q;
  --q;
  pair<long, long> pp=solve(q);
  cout<<pp.first+1<<" "<<pp.second<<endl;
 }
 else
 {
  cin>>a>>b;
  --a;
  ar[a]=b;
  rebuild(a/bsize);
 }
}

cin.get();cin.get();
return 0;}