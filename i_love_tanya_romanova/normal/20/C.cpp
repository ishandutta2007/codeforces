/*
A rider came from far away
To tell the story to the king
He was a saint in armour
Find the sole crusader
Take him to the cliff, let him see the vultures
The phantoms of universe

Rage is a sin and we're all giving in
Let the weapons of evil rust
The death machine won't wait until tomorrow

[Chorus:]
Don't fear the new revelation
No more reign of blood
You must stand united side by side
It's a new revelation
Save our troops tonight
While metal hails are falling on their shields

Cravens from the underworld
Live by the rules of slaying or be tamed
It's hard to kill dead creatures
Outcasts in euphoria
Dwell in the tombs of dark illusions
Be brothers of deliverance

Fathers and sons let us gather as one
Fight together until the end
The war machine won't stop before tomorrow

[Chorus]

No more rain on blood on their shields
You got to start to march

The conclusion of life
Is it only a paradox?
Want to be in a cowards shape?
Cast your chains, victory will cost

The conclusion of life
Is it only a paradox?
Want to be in a cowards shape?
Cast your chains, victory will cost

Rage is a sin and we're all giving in
Let the weapons of evil rust
The death machine won't wait until tomorrow

[Chorus]

The conclusion of life
Is a new revelation
Want to be in a cowards shape?
Cast your chains, victory will cost
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

long long n,m,a,b,c,dist[200000];
vector<pair<long long, long long> > g[200000];
set<pair<long long, long long> > sett;
set<pair<long long ,long long> > ::iterator it;
long long v,par[200000];
vector<long long> ans;
pair<long long, long long> tp;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 g[a].push_back(make_pair(b,c));
 g[b].push_back(make_pair(a,c));
}

for (int i=1;i<=n;i++)
{
 dist[i]=1e15;   
}
dist[1]=0;
for (int i=1;i<=n;i++)
 sett.insert(make_pair(dist[i],i));

while (sett.size())
{
 it=sett.begin();
 tp=(*it);
 v=tp.second;
 sett.erase(it);
 for (int i=0;i<g[v].size();i++)
 {
  long tv=g[v][i].first;
  long long tc=g[v][i].second+dist[v];
  if (tc<dist[tv])
  {
   sett.erase(make_pair(dist[tv],tv));
   dist[tv]=tc;
   sett.insert(make_pair(dist[tv],tv));
   par[tv]=v;
  }
 }
}

if (dist[n]>1e14)
cout<<-1<<endl;
else
{
 ans.push_back(n);
 while (n>1){ans.push_back(par[n]);n=par[n];}
 reverse(ans.begin(),ans.end());
 for (int i=0;i<ans.size();i++)
 {
  if (i)cout<<" ";
  cout<<ans[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}