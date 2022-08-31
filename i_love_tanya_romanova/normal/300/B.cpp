/*
Life is a waterfall 
we're one in the river 
and one again after the fall 
swimming through the void 
we hear the word 
we lose ourselves 
but we find it all.... 
cause we are the ones that want to play 
always want to go 
but you never want to stay 
and we are the ones that want to choose 
always want to play 
but you never want to lose 
aerials, in the sky 
when you lose small mind 
you free your life 
life is a waterfall 
we drink from the river 
then we turn around and put up our walls 
swimming through the void 
we hear the word 
we lose ourselves 
but we find it all... 
cause we are the ones that want to play 
always want to go 
but you never want to stay 
and we are the ones that want to choose 
always want to play 
but you never want to lose 
aerials, in the sky 
when you lose small mind 
you free your life 
aerials, so up high 
when you free your eyes eternal prize 
aerials, in the sky 
when you lose small mind 
you free your life 
aerials, so up high 
when you free your eyes eternal prize
*/

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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;
long n,m,a,b;
vector<long> g[1000];
long arp[1000];
vector<long> comp[1000];
long comps;
vector<long> fre;

void dfs(long v)
{
 comp[comps].push_back(v);
 arp[v]=1;
 for(int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (arp[q]==0)dfs(q);
 }
}

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{cin>>a>>b;if (a==b)continue;
g[a].push_back(b);
g[b].push_back(a);}

for (int i=1;i<=n;i++)
if (arp[i]==0)
{
if (g[i].size()==0)fre.push_back(i);
else 
{
     ++comps;dfs(i);
 }
 arp[i]=1;
}

long fl=0;
for (int i=1;i<=comps;i++)
if (comp[i].size()>3)fl=1;

if(comps>n/3)fl=1;

if (fl)
{
       cout<<-1<<endl;
}
else
{
 comps=n/3;
  for (int i=1;i<=comps;i++)
  {
     long t=3-comp[i].size();
     for (int j=1;j<=t;j++)
     {if (fre.size()==0)comp[i].push_back(n);else{
      comp[i].push_back(fre.back());fre.pop_back();}}
  }   
  for (int i=1;i<=comps;i++)
  cout<<comp[i][0]<<" "<<comp[i][1]<<" "<<comp[i][2]<<endl;
}

cin.get();cin.get();
return 0;}