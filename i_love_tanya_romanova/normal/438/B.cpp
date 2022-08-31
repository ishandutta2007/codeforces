/*
In the silence of the darkness, when all are fast asleep
I live inside a dream, calling to your spirit
As a sail calls the wind, hear the Angel's sing
Far beyond the sun, across the western sky
Reach into the blackness, find a silver line
In a voice I whisper, a candle in the night
Will carry all our dreams on a single beam of light

Close your eyes, look into the dream
Winds of change will winds of fortune bring

Fly away to a rainbow in the sky
Gold is at the end for each of us to find
There the road begins where another one will end
Here the four winds know who will break and who will bend
All to be the master of the wind

Falling stars now light my way, my life was written on the wind
Clouds above, clouds below, I ascend the dreams within
When the wind fills the sky, the clouds will move aside
And there will be the road to all our dreams
And for any day that stings, two better days it brings
Nothing is as bad as it seems

Close your eyes, look into the dream
Winds of change will winds of fortune bring

Fly away to a rainbow in the sky
Gold is at the end for each of us to find
There the road begins where another one will end
Here the four winds know who will break and who will bend
All to be the master of the wind

Fly away to a rainbow in the sky
Gold is at the end for each of us to find
There the road begins where another one will end
Here the four winds know who will break and who will bend
All to be the master of the wind

Fly away to a rainbow in the sky
Gold is at the end for each of us to find
There the road begins where another one will end
Here the four winds know who will break and who will bend
All to be the master of the wind
Fly away to a rainbow in the sky
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
#define bsize 256

using namespace std;

long n,m,ar[200000],a,b,cost;
vector<pair<long,pair<long,long> > > g;
long w[200000],d[200000],sz[200000];
long long ans;
long v1,v2;

long gett(long x)
{
 while (x!=w[x])x=w[x];
 return x;
}

void merg(long a,long b)
{
 if (d[a]>d[b])swap(a,b);
 w[a]=b;
 sz[b]+=sz[a];
 if(d[a]==d[b])d[b]++;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 cin>>ar[i];
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 cost=min(ar[a],ar[b]);
 g.push_back(make_pair(cost,make_pair(a,b))); 
}
sort(g.begin(),g.end());
reverse(g.begin(),g.end());

for (int i=1;i<=n;i++)
 w[i]=i,d[i]=1,sz[i]=1;

for (int i=0;i<g.size();i++)
{
 v1=g[i].second.first;
 v2=g[i].second.second;
 v1=gett(v1);
 v2=gett(v2);
 if (v1==v2)continue;
 ans+=1ll*g[i].first*sz[v1]*sz[v2];
 merg(v1,v2);
}

ans*=2.0;

cout.precision(10);
cout<<fixed<<ans*1.0/(n*1.0)/(n*1.0-1)<<endl;

cin.get();cin.get();
return 0;}