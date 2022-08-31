/*
He who makes a beast out of himself
Gets rid of the pain of being a man

Caught here in a fiery blaze, won't lose my will to stay
I tried to drive all through the night
The heat stroke ridden weather, the barren empty sights
No oasis here to see
The sand is singing deathless words to me

Can't you help me? As I'm startin' to burn
(All alone)
Too many doses and I'm starting to get an attraction
My confidence is leaving me on my own
(All alone)
No one can save me and you know I don't want the attention

As I adjust to my new sights
The rarely tired lights will take me to new heights
My hand is on the trigger I'm ready to ignite
Tomorrow might not make it but everything's all right

Mental fiction follow me
Show me what it's like to be set free

Can't you help me? As I'm startin' to burn
(All alone)
Too many doses and I'm starting to get an attraction
My confidence is leaving me on my own
(All alone)
No one can save me and you know I don't want the attention

So sorry you're not here
I've been sane too long my vision's so unclear
Now take a trip with me
But don't be surprised when things aren't what they seem

Caught here in a fiery blaze, won't lose my will to stay
These eyes won't see the same, after I flip today

Sometimes I don't know why we'd rather live than die
We look up towards the sky for answers to our lives
We may get some solutions but most just pass us by
Don't want your absolution cause I can't make it right

I'll make a beast out of myself
Gets rid of all the pain of being a man

Can't you help me? As I'm startin' to burn
(All alone)
Too many doses and I'm starting to get an attraction
My confidence is leaving me on my own
(All alone)
No one can save me and you know I don't want the attention

So sorry you're not here
I've been sane too long my vision's so unclear
Now take a trip with me
But don't be surprised when things aren't what they seem

I've known it from the start
All these good ideas will tear your brain apart
Scared but you, you follow me
I'm too weird to live but much too rare to die
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