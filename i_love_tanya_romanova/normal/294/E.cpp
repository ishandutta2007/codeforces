/* 
Midnight - can you hear the wolves are howling
No light - but the evil ones ore prowling
Pitch black - and their wicked eyes are on you
They attack - 'cause there's nowhere they can find you

Swirling you round, taking you down
You're the chosen one
You're looking back, you left your track
So now you run with the pack

Run with the pack

Screaming wind - from the valley of the dead
They'll win - the soul from you of which they led
They lie - but you listen just the same
You cry - but now tell me who's to blame

Swirling you round, taking you down
You're the chosen one
You're looking back, you left your track
So now you run with the pack

Run with the pack

Midnight - can you hear the wolves are howling
No light - but the evil ones are prowling
Screaming wind - from the valley of the dead
They'll win - the soul from you of which they led

Swirling you round, taking you down
You're the chosen one
You're looking back, you left your track
So now you run with the pack

Nowhere to hide
So run with pride
You run with me
You won't be free
Why don't you see
It's not a dream
No turning back
Run with the pack

Nowhere to hide
So run with pride
You run with me
You won't be free
So now you run, run, run...
Run with the pack
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,a[20000],b[20000],c[20000]; long long arp[20000],dsum[20000],
upsum[20000],subsize[20000];
vector<pair<long, long> > g[7000];
long csize;
long long ans,minsum,minsum1;
long long tans;
long tresize;

void dfs1(long v)
{
     arp[v]=1;
     subsize[v]=1;
     for (int i=0;i<g[v].size();i++)
     {
      long ver=g[v][i].first;
      long cost=g[v][i].second;
      if (arp[ver])continue;
      dfs1(ver);
      subsize[v]+=subsize[ver];
      dsum[v]+=dsum[ver];
      dsum[v]+=subsize[ver]*cost;
     }
}

void dfs2(long v)
{
     arp[v]=1;
     for (int i=0;i<g[v].size();i++)
     {
      long ver=g[v][i].first;
      long cost=g[v][i].second;
      if (arp[ver])continue;
      upsum[ver]=upsum[v];
      upsum[ver]+=dsum[v]-dsum[ver]-subsize[ver]*cost;
      upsum[ver]+=(tresize-subsize[ver])*cost;
      dfs2(ver);
     }
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

ans=1000000000;
ans*=ans;
ans*=3;

for (int i=1;i<n;i++)
{
 cin>>a[i]>>b[i]>>c[i];
}

for (int cedge=1;cedge<n;cedge++)
{
    
    for (int i=1;i<=n;i++)
    g[i].clear();
    
    for (int i=1;i<n;i++)
    if (i!=cedge)
    {g[a[i]].push_back(make_pair(b[i],c[i]));
     g[b[i]].push_back(make_pair(a[i],c[i]));
    }
    
    for (int i=1;i<=n;i++)
    arp[i]=dsum[i]=upsum[i]=subsize[i]=0;
    
    dfs1(a[cedge]);
    csize=0;
    for (int i=1;i<=n;i++)
    {csize+=arp[i];arp[i]=0;}
    tresize=csize;
    dfs2(a[cedge]);
    
    minsum=1000000000000000000ll;
    for (int i=1;i<=n;i++)
     if (arp[i]==1)minsum=min(minsum,dsum[i]+upsum[i]);
     
    for (int i=1;i<=n;i++)
    arp[i]=0;
    tresize=n-tresize;
    dfs1(b[cedge]);
    for (int i=1;i<=n;i++)
    arp[i]=0;
    
    dfs2(b[cedge]);
    minsum1=1000000000000000000ll;
    for (int i=1;i<=n;i++)
     if (arp[i]==1)minsum1=min(minsum1,dsum[i]+upsum[i]);
    
    for (int i=1;i<=n;i++)
    arp[i]=0;
    tans=0;
    for (int i=1;i<=n;i++)tans+=dsum[i]+upsum[i];
    tans/=2;
    //cout<<tans<<endl;
   // cout<<minsum<<" "<<minsum1<<" "<<csize<<" "<<c[cedge]<<endl;
    tans+=minsum*(n-csize)+minsum1*csize+1ll*csize*(n-csize)*c[cedge];
    ans=min(ans,tans);
//cout<<ans<<endl;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}