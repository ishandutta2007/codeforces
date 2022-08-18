/*
Well now this could be the last of all the rides we take
So hold on tight and don't look back
We don't care about the message or the rules they make
We'll find you when the sun goes black

And you only live forever in the lights you make
When we were young we used to say
That you only hear the music when your heart begins to break
Now we are the kids from yesterday

All the cameras watch the accidents and stars you hate
They only care if you can bleed
Does the television make you feel the pills you ate?
Or every person that you need to be

Cause you only live forever in the lights you make
When we were young we used to say
That you only hear the music when your heart begins to break
Now we are the kids from yesterday

Today, today
We are the kids from yesterday
Today, today

Here we are and we won't stop breathing
Yell it out 'till your heart stops beating
We are the kids from yesterday, today

'Cause you only live forever in the lights you make
When we were young we used to say
That you only hear the music when your heart begins to break
Now we are the kids from yesterday
We are the kids from yesterday
We are the kids from yesterday
We are the kids from yesterday
Today, today
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