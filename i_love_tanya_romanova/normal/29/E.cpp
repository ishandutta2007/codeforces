/*
False eyes are staring
disrespectfully and untrue
The burden that we are carrying
is way too much for me and you

Sometimes it is better to lay
Don't you think?

I'm evaporating
A veil of smoke is what I am
Your thoughts will take on their way
To grow old and to be certain
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
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,m,a,b,temp,v1,v2,v3,v4;
queue<long> qu;
vector<long> g[1<<20];
long par[1<<20];
long used[1<<20];
long v;
long did[1000][1000];

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 --a;--b;
 g[a].push_back(b);
 g[b].push_back(a);
}

qu.push(n-1);
used[n-1]=1;

while (qu.size())
{
 temp=qu.front();
 qu.pop();
 v1=temp/n;
 v2=temp%n;
 // both
 for (int i=0;i<g[v1].size();i++)
 {
  v3=g[v1][i];
  if (did[v3][v2])continue;
  for (int j=0;j<g[v2].size();j++)
  {
//   v3=g[v1][i];
   v4=g[v2][j];
   if (v3==v4)continue;
   v=v3*n+v4;
   if (used[v])continue;
   par[v]=temp;
   used[v]=used[temp]+1;
   qu.push(v);
  }
  did[v3][v2]=1;
 }
 /*
 for (int i=0;i<g[v1].size();i++)
 {
  v3=g[v1][i];
  v4=v2;
  if (v3==v4)continue;
   v=v3*n+v4;
   if (used[v])continue;
   par[v]=temp;
   used[v]=used[temp]+1;
   qu.push(v);
 }
 
 for (int i=0;i<g[v2].size();i++)
 {
  v4=g[v2][i];
  v3=v1;
  if (v3==v4)continue;
   v=v3*n+v4;
   if (used[v])continue;
   par[v]=temp;
   used[v]=used[temp]+1;
   qu.push(v);
 }*/
}

//cout<<used[n*(n-1)]<<endl;

if (used[n*n-n]==0)
{
 cout<<-1<<endl;
 return 0;
}

long vert;
vector<long> ans;
vert=n*n-n;
while (vert!=n-1)
{
 ans.push_back(vert);
 vert=par[vert];
}
reverse(ans.begin(),ans.end());
cout<<ans.size()<<endl;
cout<<1;
for (int i=0;i<ans.size();i++)
{
 cout<<" "<<ans[i]/n+1;
}
cout<<endl;
cout<<n;
for (int i=0;i<ans.size();i++)
{
    cout<<" "<<ans[i]%n+1;
}
cout<<endl;

cin.get();cin.get();
return 0;}