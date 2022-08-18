/*
Hades son of titans, a lost and fallen king
He has nothing to lose and nothing to glean
The endless war lasted ten years
He was banned with thunder and without fear

At the river Styx he sits at the gate
Waiting for the poor to fulfill their fate
In the unseen realm the dead go upon
Leaving the world behind wher war rages on

The storm is gone
A new day has begun
Run with the light
Safe me with your sacrifice

God of terror - reign of the dead
God of terror - the sky turns to red
God of terror - reign of pain
God of terror - slaves in the bloody rain

Summon the immortal, to hell they ride
Legions of demons at dawn they'll die
As nameless creatures left in misery
Divine revelation is crying out - insanity
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,ar[300000],ar1[300000],ar2[300000];
long ps[300000];
long temp1,temp2,a,b;
vector<pair<long,long> > v;
vector<pair<pair<long, long> ,long> > v1;
map<pair<long, long>,long> mapp;
pair<long, long> tp;
long ans[300000];
long pss;
long temp;

void update(long x)
{
 ar1[x]++;
 ar2[x/bsize]++;
}
long gett(long x)
{
 long r=0;
 for (int i=0;i<x/bsize;i++)
 r+=ar2[i];
 for (int i=x/bsize*bsize;i<=x;i++)
 r+=ar1[i];
 return r;
}

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    ps[ar[i]]=i;
}
for (int i=1;i<=n;i++)
for (int j=i;j<=n;j+=i)
{
    temp1=ps[i];
    temp2=ps[j];
    if (temp1>temp2)swap(temp2,temp1);
    v.push_back(make_pair(temp2,-temp1));
}
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    v1.push_back(make_pair(make_pair(b,-a),i));
    mapp[make_pair(b,-a)]=i;
}
sort(v.begin(),v.end());
sort(v1.begin(),v1.end());
pss=0;

for (int i=0;i<v1.size();i++)
{
 while (pss<v.size()&&v[pss]<=v1[i].first)
 {
  update(-v[pss].second);++pss;
 }
 ans[v1[i].second]=gett(v1[i].first.first)-gett(-v1[i].first.second-1);
}

for (int i=1;i<=m;i++)
{
    cout<<ans[i]<<endl;
}
//cout<<endl;

cin.get();cin.get();
return 0;}