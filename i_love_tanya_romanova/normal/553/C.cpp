/*
Leaving with twilight though I was chosen
To wander the way in the darkest of nights
Oh in the summer sun how soon I came to stray
A true damnation when I turned away

So fell autumn rain washed away ali my pain
I feel brighter somehow lighter somehow to breath once again
So fell autumn rain washed my sorrows away
With the sunset behind somehow I find the dreams are to stay

So fell autumn rain

Blinded by dawning so you would take me
Further away away from the fall
Oh you told me I must never dream again
A true damnation you left me the pain

So fell autumn rain but all things must pass

So fell autumn rain washed away all my pain
I feel brighter somehow lighter somehow to breath once again
So tell autumn rain washed my sorrows away
With the sunset behind somehow I find the dreams are to stay

So fell winter
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
#define bsize 256

using namespace std;

vector<pair<int, int> > g[1<<20];
int n,m,a,b,c,ans;
int used[1<<20];
int er;

void dfs(int v,int cl)
{
    used[v]=cl;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i].first;
        int C=g[v][i].second;
        int ncl=cl;
        if (C==0)
            ncl=3-ncl;
        if (used[to]==0)
        {
            dfs(to,ncl);
        }
        else if (used[to]!=ncl)
            er=1;
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
for (int i=0;i<m;i++)
{
    cin>>a>>b>>c;
    --a;
    --b;
    g[a].push_back(make_pair(b,c));
    g[b].push_back(make_pair(a,c));
}

ans=1;

int comps=0;

for (int i=0;i<n;i++)
{
    if (used[i])continue;
    dfs(i,1);
    ++comps;
}

for (int i=2;i<=comps;i++)
    ans=ans*2%bs;
    
if (er)
    ans=0;

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}