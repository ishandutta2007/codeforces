/*
I'll keep on burning this bridges that you hold so dear
If I keep disregarding the pain that has brought me here
I'll leave the misery out, you can't keep me delivering something real
If I keep disrespecting the path that will help you heal
You keep on thinking it's the only direction

I'll keep on burning these bridges that you hold so dear
If I keep disregarding the pain that has brought me here
I'll leave the misery out, you can't keep me delivering something real
If I keep disrespecting the path that will help you heal
You keep on guessing but don't know my intentions

With every lesson you learn, keep it shining as you throw it at me
Say then you might get burned
With every lesson you learn, keep it shining as you throw it at me
Say then you might get burned

You must have done something to me

With every lesson you learn, keep it shining as you throw it at me
Say then you might get burned
With every lesson you learn, keep it shining as you throw it at me
Say then you might get burned

I can't breathe
I can't breathe
I can't breathe
I can't breathe

Break it, break it, break it, break it, break it up
Break it, break it, break it, break it, break it up
Break it, break it, break it, break it, break it up
Break it, break it, break it, break it, break it up

With every lesson you learn, keep it shining as you throw it at me
Say then you might get burned
With every lesson you learn, keep it shining as you throw it at me
Say then you might get burned
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,m,a,b;
vector<long> G[1<<20],g[1<<20],gr[1<<20];
vector<long> component;
long used[1<<20];
long ans;
vector<long> order;
long found;
long bad[1<<20];

void check_dfs(long v)
{
 used[v]=1;
 if (bad[v])found=1;
 for (int i=0;i<G[v].size();i++)
 {
  long id=G[v][i];
  if (used[id])continue;
  check_dfs(id);
 }
}

void dfs(long v)
{
 used[v]=1;
 for (int i=0;i<G[v].size();i++)
 {
  long id=G[v][i];
  if (used[id])continue;
  dfs(id);
 }
}

void dfs1(long v)
{
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long id =g[v][i];
  if (used[id])continue;
  dfs1(id);
 }
 order.push_back(v);
 
}

void dfs2(long v)
{
 used[v]=1;
 component.push_back(v);
 for (int i=0;i<gr[v].size();i++)
 {
  long id=gr[v][i];
  if (used[id])continue;
  dfs2(id);
 }    
}
int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 G[a].push_back(b);
 G[b].push_back(a);
 g[a].push_back(b);
 gr[b].push_back(a);
}

ans=n;
for(int i=1;i<=n;i++)
 if (used[i]==0)
 {
  --ans;
  dfs(i);
 }

for (int i=1;i<=n;i++)
 used[i]=0;

for (int i=1;i<=n;i++)
{
 if (used[i])continue;
 dfs1(i);
}
for (int i=1;i<=n;i++)
 used[i]=0;

reverse(order.begin(),order.end());

for (int i=0;i<order.size();i++)
{
 long v=order[i];
 if (used[v])continue;
 dfs2(v);
// cout<<component.size()<<endl;
 if (component.size()>1)
 {
  for (int j=0;j<component.size();j++)
   bad[component[j]]=1;
 }
 component.clear();
}

for (int i=1;i<=n;i++)
 used[i]=0;

for (int i=1;i<=n;i++)
{
    if (used[i])continue;
    found=0;
    check_dfs(i);
    if (found)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}