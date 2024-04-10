/*
Riders on the storm 
Riders on the storm 
Into this house we're born 
Into this world we're thrown 
Like a dog without a bone 
An actor out on loan
Riders on the storm 

There's a killer on the road 
His brain is squirmin' like a toad 
Take a long holiday 
Let your children play 
If ya give this man a ride 
Sweet memory will die 
Killer on the road, yeah 

Girl ya gotta love your man 
Girl ya gotta love your man 
Take him by the hand 
Make him understand 
The world on you depends 
Our life will never end 
Gotta love your man, yeah 

Wow! 

Riders on the storm 
Riders on the storm 
Into this house we're born 
Into this world we're thrown 
Like a dog without a bone 
An actor out alone 
Riders on the storm 

Riders on the storm 
Riders on the storm 
Riders on the storm 
Riders on the storm 
Riders on the storm
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
#include <memory.h>

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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,q;
vector<long> st;
long quers;
long q1[200000],q2[200000];
vector<long> req[200000];
vector<long> g[200000];
vector<long> dep;
vector<long> test[200000];
long point[200000];
vector<long> sons[200000];
long ans[200000];

void dfs(long v)
{
 dep.push_back(v);
 
 for (int i=0;i<req[v].size();i++)
 {
  long q=req[v][i];
  if (q2[q]>=dep.size())continue;
  long ps=dep.size()-q2[q]-1;
  test[dep[ps]].push_back(q);  
 }
 
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  dfs(q);
 }
  dep.pop_back();
}

void merg(long v,long q)
{
     if (sons[point[v]].size()<sons[point[q]].size())
     swap(point[v],point[q]);
     long spn=sons[point[v]].size()-sons[point[q]].size();
     for (int i=0;i<sons[point[q]].size();i++)
     sons[point[v]][i+spn]+=sons[point[q]][i];
}

void dfs1(long v)
{
 point[v]=v;
 
 for (int i=0;i<g[v].size();i++)
 {
     long q=g[v][i];
     dfs1(q);
     merg(v,q);
 }
 
 sons[point[v]].push_back(1);
 
 for (int i=0;i<test[v].size();i++)
 {
  long q=test[v][i];
  long dep=q2[q];
  if (dep>=sons[point[v]].size())continue;
  long ps1=sons[point[v]].size()-dep-1;
  ans[q]=sons[point[v]][ps1]-1;   
 }
 
}

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 if (q==0)
 st.push_back(i);
 else
 {
     g[q].push_back(i);
 }   
}

cin>>quers;

for (int i=1;i<=quers;i++)
{
    cin>>q1[i]>>q2[i];
    req[q1[i]].push_back(i);
}

for (int i=0;i<st.size();i++)
{
 dfs(st[i]);   
}

for (int i=0;i<st.size();i++)
dfs1(st[i]);

for (int i=1;i<=quers;i++)
{
    if (i>1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}