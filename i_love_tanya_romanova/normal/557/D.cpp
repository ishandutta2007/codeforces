/*
Two, two, two thousand years of oppression
Slowly, intelligence died
Bringing another obsession
Singing the songs of the blind

Two thousand years of devotion
Misery conquered the mind
Finally found a way out of this terror
Before final death of the soul, killed your sight

The second awakening, finally reborn
Together, we're standing
Now, the time has come

The second awakening
Things won't be the same
As the spirit awakes again

Come, praise those years for progression
Come, curse those years for it's wars
Blood thirst and endless aggression
Government put into force

Two thousand years of confusion
Finally come to an end
Cleaning the earth from this spiritual poison
Before a new chapter of life can begin, can begin

The second awakening, finally reborn
Together, we're standing
Now, the time has come

The second awakening
Things won't be the same
As the spirit awakes again

Raise your hand as we transcend
Time to rise
Reawakening

Raise your hand as we transcend
Time to rise
Reawakening

Awake again, awake again
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,m,a,b,er;
int used[1<<20];
vector<int> g[1<<19];
vector<pair<int, int> > comps;
int cnt[1<<10];
int one,two;

void dfs(int v,int cl)
{
    used[v]=cl;
    cnt[cl]++;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (used[to]==0)
        {
            dfs(to,3-cl);
            continue;
        }
        if (used[to]==used[v])
        {
            er=1;
        }
    }
}
int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

er=0;

for (int i=1;i<=n;i++)
{
    if (used[i])continue;
    cnt[1]=cnt[2]=0;
    dfs(i,1);
    comps.push_back(make_pair(cnt[1],cnt[2]));
    if (cnt[1]>1||cnt[2]>1) 
        one=1;
    if (cnt[1]+cnt[2]==2)
        two=1;
}

if (er) // nbp
{
    cout<<0<<" "<<1<<endl;
}
else if (one)
{
    cout<<1<<" ";
    long long ans=0;
    for (int i=0;i<comps.size();i++)
    {
        ans+=1ll*comps[i].first*(comps[i].first-1)/2;
        ans+=1ll*comps[i].second*(comps[i].second-1)/2;
    }
    cout<<ans<<endl;
}
else if (two)
{
    cout<<2<<" ";
    long long ans=0;
    
    for (int i=0;i<comps.size();i++)
    {
        if (comps[i].first+comps[i].second==2)
            ans+=n-2;
    }
    cout<<ans<<endl;
}
else
{
    cout<<3<<" ";
    cout<<1ll*n*(n-1)*(n-2)/6<<endl;
}

//cin.get();cin.get();
return 0;}