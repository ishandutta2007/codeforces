/*
My secrets are buried now
From my heart and my bones catch a fever
When it cuts you up this deep
It's hard to find a way to breathe

Your eyes are swallowing me
Mirrors start to whisper
Shadows start to see
My skin's smothering me
Help me find a way to breathe

Time stood still
The way it did before
It's like I'm sleepwalking
Fell into another hole again
It's like I'm sleepwalking

I'm at the edge of the world
Where do I go from here?
Do I disappear?
Edge of the world
Should I sink or swim?
Or simply disappear?

Your eyes are swallowing me
Mirrors start to whisper
Shadows start to see
My skin's smothering me
Help me find a way to breathe

Seeing as time stood still
The way it did before
It's like I'm sleepwalking
Fell into another hole again
It's like I'm sleepwalking

Wake up!
Take my hand and
Give me a reason to start again
Wake up!
Pull me out and
Give me a reason to start again

Time stands still
(Time stands still)
Time stands still
(Time stands still)

Your eyes are swallowing me
Mirrors start to whisper
Shadows start to see
My skin's smothering me
Help me find a way to breathe

Time stood still
The way it did before
It's like I'm sleepwalking
Fell into another hole again
It's like I'm sleepwalking
(It's like I'm sleepwalking)
(It's like I'm sleepwalking)
(It's like I'm sleepwalking)

Time stood still
The way it did before
It's like I'm sleepwalking
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;
long n,m,a,b,c;
vector<pair<long, long> > g[220000];
long cap[220000];
map<pair<long, long> ,long> mapp;
set<pair<long, long> > done;
long ans[220000];

void solve(long v)
{
//     cout<<v<<"%"<<endl;
     
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i].first;
     long val=g[v][i].second;
     
     if (done.find(make_pair(v,q))!=done.end())continue;
     done.insert(make_pair(v,q));
     done.insert(make_pair(q,v));
     
     ans[mapp[make_pair(v,q)]]=1;
     cap[q]-=val;
     if (cap[q]==0&&q<n)solve(q);
 }
}

int main(){
//freopen("test.in","r",stdin);
//freopen("test.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b>>c;
    mapp[make_pair(b,a)]=i;
    g[a].push_back(make_pair(b,c));
    g[b].push_back(make_pair(a,c));
    cap[a]+=c;
    cap[b]+=c;
}

for (int i=1;i<=n;i++)
cap[i]/=2;

cap[n]=0;
cap[1]=0;
solve(1);

for (int i=1;i<=m;i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}