/*
Hey, I'm your life
I'm the one who takes you there
Hey, I'm your life
I'm the one who cares

They, they betray
I'm your only true friend now
They, they'll betray
I'm forever there

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true, sad but true

You, you're my mask
You're my cover, my shelter
You, you're my mask
You're the one who's blamed

Do, do my work
Do my dirty work, scapegoat
Do, do my deeds
For you're the one who's shamed

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true, sad but true

I'm your dreams, I'm your eyes, I'm your pain
I'm your dreams, I'm your eyes, I'm your pain
You know it's sad but true

Hate, I'm your hate
I'm your hate when you want love
Pay, pay the price
Pay for nothing's fair

Hey, I'm your life
I'm the one who took you there
Hey, I'm your life
And I no longer care

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your truth, telling lies
I'm your reasoned alibis
I'm inside, open your eyes
I'm you, sad but true
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m;
vector<long> g[200000];
long a,b;
long tp[200000];
long start;
long used[200000];
vector<long> ans;
long calc[200000];
long has[200000];

void dfs(long v)
{
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  dfs(q);
 }
}

void solve(long v)
{
 ans.push_back(v);// entr
 calc[v]^=1;
 used[v]=1;

 vector<long> sons;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  solve(q);
  ans.push_back(v);
  calc[v]^=1;
  sons.push_back(q);
 }
 
 for (int i=0;i<sons.size();i++)
 {long
  temp=sons[i];
  if (calc[temp]!=tp[temp])
  {ans.push_back(temp);calc[temp]^=1;ans.push_back(v);calc[v]^=1;}
 }
 /*
 if (sons.size())
 {
 ans.push_back(v);// out
 calc[v]^=1;
 }*/
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

for (int i=1;i<=n;i++)
cin>>tp[i];

start=0;
for (int i=1;i<=n;i++)
{
 if (tp[i]==1)start=i;
}

if (start==0)
{
 cout<<0<<endl;
 return 0;
}

dfs(start);

for (int i=1;i<=n;i++)
if (tp[i]==1&&used[i]==0)// fld
{
 cout<<-1<<endl;
 return 0;
}

for (int i=1;i<=n;i++)
 used[i]=0;

solve(start);
if (tp[start]!=calc[start])ans.pop_back();

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

for (int i=0;i<ans.size();i++)
 has[ans[i]]^=1;
/*
for (int i=1;i<=n;i++)
 cout<<tp[i]<<" ";
 cout<<endl;
for (int i=1;i<=n;i++)
 cout<<has[i]<<" ";
 cout<<endl;
 */
cin.get();cin.get();
return 0;}