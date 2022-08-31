/*
Convalescent livid we succumb
Stagnation now complete
This is the new plague called
Unconsciousness
We're selfcaged in defeat
Clotted minds coagulate we are trapped
Inside the tears we obey resignate to our
Self-inflected fears

Voices calm will be never heard
In this mode who will change
Bantised in our minds so absurd
Is this the world sublime
Into pools of paranoia we're fading with
Reality drained by lies we are al inhuman
Introspective vanishing

Sterile thoughts now upraised in subhuman
Majesty bodies numb still enchained
Where am i in hell of our dreams
Wrong wrong i'm in the now the vain reality

So it seems we're dying yet content
Worship our chrysalis stage since when are
Lies devine

Since when

This is now degrade indulge
This is us servile obliging

Swallowed by our hunger for mendacity
As this dance whirls deeper into hate

We're vanishing

In down deep cold where am i caught cage
Trapped not in dreams now time has killed
Our eyes fall fade gone dead away
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,k,t,bd[2000],frend;
vector<pair<long, long> > v;
long fr1;
set<pair<long, long> > sett;
long svert;
vector<long> q;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;

if (k==n)cout<<-1<<endl;
else
{
for (int i=1;i<=k;i++)
{
    cin>>t;
 bd[t]=1;
}

for (int i=1;i<=n;i++)
if (bd[i]==0)q.push_back(i);
for (int i=1;i<=n;i++)
if (bd[i]==1){q.push_back(i);if (svert==0)svert=i;}

//cout<<svert<<endl;

for (int i=0;i<q.size();i++)
 for (int j=i+1;j<q.size();j++)
 {
     if ((q[i]!=svert&&q[j]!=svert)||(bd[q[i]]+bd[q[j]]<2))
     v.push_back(make_pair(q[i],q[j]));
 }
if (v.size()<m)
cout<<-1<<endl;
else
for (int i=0;i<m;i++)
{cout<<v[i].first<<" "<<v[i].second<<endl;
}
}
cin.get();cin.get();
return 0;}