/*
This is year zero, all we knew has died
The mutiny came so sudden, killing yesterday

Thoughts that forced discordance away
Once more an era is fading
Whatever dreams we're reaching to claim
Decides the path we are taking

Gone forever
We are done with world views mechanical
None shall, none shall ever be a slave
To thoughts inside their heads

Mind is the master, morphogenesis
This structure remained untrodden a new reality

Gone forever
We are done with world views mechanical
None shall, none shall ever be a slave
To thoughts inside their heads

Gone forever
We are done with world views mechanical
None shall, none shall ever be a slave
To thoughts inside their heads

Bleeding through all spheres, all our thoughts, all our fears
Gaining life, soul, mind, heart, feeding starts now
Rising from ashen dust, through our sins, karmic cost
Measured souls, weigh our hearts, judge our thoughts, no

Thoughts that forced discordance away
Once more an era is fading
Whatever dreams we're reaching to claim
Decides the path we are taking

Gone forever
We are done with world views mechanical
None shall, none shall ever be a slave
To thoughts inside their heads

Gone forever
We are done with world views mechanical
None shall, none shall ever be a slave
To thoughts inside their heads
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

long n,k,a,b,c,deg[20000],temp;
vector<long> ans1,ans2,ans3;
vector<pair<long, long> > g[20000];
long lst;

long dfs(long v)
{
 lst=v;
 if (g[v].size()==0)return 1e9;
 return min(g[v][0].second,dfs(g[v][0].first));
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=k;i++)
{
 cin>>a>>b>>c;
 g[a].push_back(make_pair(b,c));
// g[b].push_back(make_pair(a,c));
 deg[b]++;   
}

for (int i=1;i<=n;i++)
{
 if (deg[i])continue;
 if (g[i].size()==0)continue;
 temp=dfs(i);
 ans1.push_back(i);
 ans2.push_back(lst);
 ans3.push_back(temp);
}

cout<<ans1.size()<<endl;
for (int i=0;i<ans1.size();i++)
{
 cout<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i]<<endl;
}

cin.get();cin.get();
return 0;}