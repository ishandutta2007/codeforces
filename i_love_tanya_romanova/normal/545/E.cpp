/*
Born to push you around
You better just stay down
You pull away, he hits the flesh
You hit the ground

Mouths so full of lies
Tend to black your eyes
Just keep them closed
Keep praying, just keep waiting

Waiting for the one
The day that never comes
When you stand up and feel the warmth
But the sunshine never comes, no
No, the sunshine never comes

Push you cross that line
Just stay down this time
Hiding yourself, crawling yourself
You'll have your time

God, I'll make them pay
Take it back one day
I'll end this day
I'll splatter color on this gray

Waiting for the one
The day that never comes
When you stand up and feel the warmth
But the sunshine never comes

Love is a four letter word
And never spoken here
Love is a four letter word
Here in this prison

I suffer this no longer
I'll put it into this I swear
This I swear the sun will shine
This I swear, this I swear
This I swear!
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,m,a[1<<20],b[1<<20],c[1<<20];
vector<long long> g[1<<20],G[1<<20];
long long dist[1<<20];
set<pair<long long, long long> > S;
set<pair<long long, long long> > ::iterator it;
pair<long long, long long> tp;
vector<pair<long long, long long> > V;
long long to;
long long v;
long long start;
long long cost,par[1<<20];
long long pedge[1<<20];
set<pair<long long, long long> > good;
long long w[1<<20];
vector<long long> ans;
long long answ;
long long used[1<<20];
long long cheap[1<<20];
long long cid[1<<20];

long long get(long long x)
{
    if (w[x]==x)return x;
    return w[x]=get(w[x]);
}
void merge(long long a,long long b)
{
    if (rand()%2)swap(a,b);
    w[a]=b;
}

long long get_vertex(long have, long id)
{
    if (a[id]==have) return b[id];
    return a[id];
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a[i]>>b[i]>>c[i];
    g[a[i]].push_back(i);
    g[b[i]].push_back(i);
}

for (int i=1;i<=n;i++)
 dist[i]=1e18;
cin>>start;

//cout<<"^"<<start<<endl;

dist[start]=0;

for (int i=1;i<=n;i++)
 S.insert(make_pair(dist[i],i));

while (S.size())
{
    it=S.begin();
    v=(*it).second;
    S.erase(it);
    for (int i=0;i<g[v].size();i++)
    {
        to=get_vertex(v,g[v][i]);
        cost=dist[v]+c[g[v][i]];
        if (dist[to]>cost)
        {
            S.erase(make_pair(dist[to],to));
            dist[to]=cost;
            par[to]=v;
            S.insert(make_pair(dist[to],to));
        }
    }
}
/*
for (int i=1;i<=n;i++)
 cout<<i<<"^"<<dist[i]<<endl;
 */
for (int i=1;i<=m;i++)
{
    if (dist[a[i]]+c[i]==dist[b[i]])
     G[a[i]].push_back(i);
    if (dist[b[i]]+c[i]==dist[a[i]])
     G[b[i]].push_back(i);  
}

for (int i=1;i<=n;i++)
{
    cheap[i]=1e9+1e7;
    cid[i]=0;
}

for (int i=1;i<=n;i++)
 for (int j=0;j<G[i].size();j++)
 {
    int id=G[i][j];
    int to=get_vertex(i,id);
    if (cheap[to]>c[id])
     cheap[to]=c[id],
     cid[to]=id;
 }
 
 for (int i=1;i<=n;i++)
  if (i!=start)
   ans.push_back(cid[i]),
   answ+=c[cid[i]];
   
cout<<answ<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}