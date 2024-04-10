//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

 vector<long> g[300000];
vector<long> tin, tout;
long timer;
 vector<long> up[300000];
 long n,l,k,a,b,ans[600000],ts[600000],arp[600000],d[500000],ind;

pair <long, long> p;
map <pair <long, long> ,long> m;


void dfs (long v, long p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (long a, long b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

long lca (long a, long b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}


void dfs1(long a)
{
 arp[a]=1;
 long q;
 

 
 for (int i=0;i<g[a].size();++i)
 {
  q=g[a][i];
  if (arp[q]==0){
                 dfs1(q);
                 p=make_pair(a,q);
                 ind=m[p];
                // cout<<ind<<endl;
                 ans[ind]=ts[q];
                  ts[a]+=ts[q];    
                 }     
 }
 ts[a]+=d[a];
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;

for (int i=0;i<n-1;i++)
{
    cin>>a>>b;
    --a;--b;
    p=make_pair(a,b);
    m[p]=i;
    p=make_pair(b,a);
    m[p]=i;
    g[a].push_back(b);
    g[b].push_back(a);
}

cin>>k;

tin.resize (n);tout.resize (n);
l = 1;
while ((1<<l) <= n)  ++l;
for (int i=0; i<n; ++i)  up[i].resize (l+1);
dfs (0);


for (int i=0;i<k;i++) 
        {
        cin>>a>>b;
        --a;--b;
        d[a]++;
        d[b]++;
        d[lca(a,b)]-=2;
        }


dfs1(0);
/*
for (int i=0;i<n;i++)
cout<<d[i]<<" ";cout<<endl;
for (int i=0;i<n;i++)
cout<<ts[i]<<" ";cout<<endl;
*/

for (int i=0;i<n-1;i++)
{
if (i)cout<<" ";    cout<<ans[i];
}

cout<<endl;


cin.get();cin.get();
return 0;}