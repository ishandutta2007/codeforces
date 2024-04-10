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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1200000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long long n,sz,m,ans,ttl,q;
long long szz[1200000];

long a,b;

int main(){
//freopen("subseq.in","r",stdin);
//freopen("subseq.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

ttl=n*(n-1)*(n-2)/6;

ans=ttl;
ans-=(n-2)*m;

for (int i=0;i<m;i++)
{
 cin>>a>>b;
szz[a]++;
szz[b]++;// g[a].push_back(b);
// g[b].push_back(a);
}

for (int i=1;i<=n;i++)
{sz=szz[i];
 ans+=(sz*(sz-1))/2;}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}