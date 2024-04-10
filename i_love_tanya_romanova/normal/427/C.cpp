/*
Things move when I'm not watching them 
They have their own will
And I don't even feel insane
Because I know I'm ill 
I know there is an eye and I'm under observation
I am a marked man got some information
Governments use millions for supervision
Global message interception
Satellite receivers of Echelon system
Carnivore technique for digital control
It is said that terror lives behind the wall of privacy
But what do the rights really mean in our society?
Finger prints, personal I.D, credit card, database
A paradox of privacy
Doubtful about it all 
Doubtful about it all 
Doubtful about it all 
Doubtful about it all 
Eyes of god, secret crimes, causality, reckoning day
A paradox of humanity
A paradox of humanity
Doubtful about it all 
Doubtful about it all 
Doubtful about it all 
Doubtful about it all
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,m,a,b,cost[200000];
vector<long> g[200000],gr[200000];
long long ans;
long used[200000];
vector<long> temp,order,comp;

void dfs1(long v)
{
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  dfs1(q);
 }
 order.push_back(v);
}

void dfs2(long v)
{
 used[v]=1;
 for (int i=0;i<gr[v].size();i++)
 {
  long q=gr[v][i];
  if (used[q])continue;
  dfs2(q);
 }
 comp.push_back(v);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>cost[i];
cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 gr[b].push_back(a);
}

ans=1;
for (int i=1;i<=n;i++)
 if (used[i]==0)dfs1(i);
 for (int i=1;i<=n;i++) 
  used[i]=0;

long long tans=0;
for (int i=1;i<=n;i++)
{
 long v=order[n-i];
 if (used[v])continue;
 dfs2(v);
 temp.clear();
 for (int j=0;j<comp.size();j++)
  temp.push_back(cost[comp[j]]);
 sort(temp.begin(),temp.end());
 comp.clear();
 long p=0;
 tans+=temp[0];
 while (p+1<temp.size()&&temp[p+1]==temp[0])++p;
 ans=ans*(p+1)%bs;
}
cout<<tans<<" "<<ans<<endl;

cin.get();cin.get();
return 0;}