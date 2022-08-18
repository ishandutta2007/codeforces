/*
Dead start in my head
And the day is been laid
The things I really want
Always torn from my heart

You never saw the way
How I wanted you to stay
And now when you're gone
I'm on my own

When I was thinking there
Was something permanent?
You were already thinking
Of going away
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

int n;
int d[1<<20];
vector<int> g[1<<20],pref[1<<20],suf[1<<20];
int ans[1<<20];
int par[1<<20];

void dfs(int v)
{
    d[v]=1;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        par[to]=v;
        dfs(to);
        d[v]=1ll*d[v]*(d[to]+1)%bs;
    }
    pref[v].push_back(1);
    
    int prod=1;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        prod=1ll*prod*(d[to]+1)%bs;
        pref[v].push_back(prod);
    }
    reverse(g[v].begin(),g[v].end());
    
    prod=1;
    suf[v].push_back(1);
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        prod=1ll*prod*(d[to]+1)%bs;
        suf[v].push_back(prod);
    }
    reverse(g[v].begin(),g[v].end());
}

void solve(int v)
{
    int memo1,memo2;
    ans[v]=d[v];
    
    //cout<<v<<"  "<<d[v]<<endl;
    
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        memo1=d[v];
        memo2=d[to];
        d[v]=1ll*pref[v][i]*suf[v][g[v].size()-i-1]%bs;
        //cout<<suf[v][g[v].size()-i-1]<<"@"<<endl;
        //cout<<"!"<<d[v]<<"%"<<v<<endl;
        if (v!=1)
            d[v]=1ll*d[v]*(1+d[par[v]])%bs;
//      cout<<"@"<<d[v]<<endl;
        d[to]=1ll*d[to]*(d[v]+1)%bs;
        solve(to);
        d[v]=memo1;
        d[to]=memo2;
    }
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=2;i<=n;i++)
{
    int q;
    cin>>q;
    g[q].push_back(i);
}

dfs(1);

solve(1);

for (int i=1;i<=n;i++)
{
    if (i>1)
        cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}