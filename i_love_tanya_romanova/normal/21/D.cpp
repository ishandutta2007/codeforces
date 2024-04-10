/*
Known for years the trouble you've been nothing
And you thought we wouldn't have seen anything
Now that the real truth is resurfacing
It isn't your innocence you should be craving

Don't wait for a truce,
The war is on, the war is on

You try so hard to deny
All the mistakes and all the lies
We've heard the bullshit, we know the lies
No excuses can get you off this time.

Don't wait for a truce,
The war is on, the war is on
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

long n,m,ar[100][100],deg[100],a,b,c;
long tc;
long bst,used[1<<10];
long er;
long pen;

void dfs(long v)
{
 used[v]=1;
 for (int i=1;i<=n;i++)
  if (used[i]==0&&ar[v][i]<1e8)
   dfs(i);
}

void solve(long v)
{
// cout<<v<<" "<<pen<<" "<<used[v]<<" "<<deg[v]<<endl;
 if (v==n+1)
 {
  bst=min(bst,pen);
  return;
 }
 if (deg[v]%2==0)
  {solve(v+1);return;}
 if (used[v])
 {
  solve(v+1);return;
 }
 if (pen>=bst)return;
 
 for (int i=v+1;i<=n;i++)
 {
     if (used[i]==1)continue;
     if (deg[i]%2==0)continue;;
//     cout<<i<<"   "<<v<<" "<<ar[i][v]<<endl;
     used[i]=1;
     pen+=ar[i][v];
     solve(v+1);
     used[i]=0;
     pen-=ar[i][v];
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
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  ar[i][j]=1e9;

for(int i=1;i<=n;i++)
 ar[i][i]=0;
 
for (int i=0;i<m;i++)
{
 cin>>a>>b>>c;
 ++deg[a];
 ++deg[b];
 ar[a][b]=min(ar[a][b],c);
 ar[b][a]=min(ar[b][a],c);
 tc+=c;
}

for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
   ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);

dfs(1);
for (int i=1;i<=n;i++)
 if (deg[i]>0&&used[i]==0)
  er=1;

if (er)
{
 cout<<-1<<endl;
 return 0;
}

for (int i=1;i<=n;i++)
 used[i]=0;

bst=1e9;

solve(1);

cout<<tc+bst<<endl;

cin.get();cin.get();
return 0;}