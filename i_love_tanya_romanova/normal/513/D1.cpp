/*
The priesthood is trembling
the five knights of light has betrayed mankind
Now known as the dark ones
we strike down on earth with powers from hell

We ride on the wind we ride through the sky
like unholy birds of war we fly
we bring agony and insanity
Once blessed by the light now serving the night
and soon cursed by every man on earth
We follow our lust, in no god we trust

Come join us
Leave this world behind and you will find satisfaction
fight on our side you cannot hide from us forever more

Once greeted as heroes
now treated as foes wherever we go
Recruiting more warriors
the hordes of undead march on our command

Now mankind will pay from this very day
every man on earth will curse his birth
We spread fear and pain resistance in vain
We march in the dark your king is our mark
avoid the daylight in dark we fight
We'll control your souls you'll end up like ghouls
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
#define MAG 10000

using namespace std;

long n,m,a,b,t;
vector<pair<long, string> > g[1000];
string st;
vector<long> ans;
long cut[200][200];
long Mincp[200],Maxcp[200];
long mem[200][200];
long done[200][200];

bool solve(long l,long r)
{
 if (done[l][r])return mem[l][r];
 done[l][r]=1;
 if (l>r){mem[l][r]=1;return true;}
 if (l==r)
 {
  if (g[l].size()){mem[l][r]=0;return false;}
  mem[l][r]=1;
  return true;
 }
 for (int i=0;i<g[l].size();i++)
 {
  if (g[l][i].first<=l||g[l][i].first>r)
   {mem[l][r]=0;return false;}
 }
 
 long mincp,maxcp;
 mincp=l;
 maxcp=r;
 
 for (int i=0;i<g[l].size();i++)
 {
  long id=g[l][i].first;
  string temp=g[l][i].second;
  if (temp[0]=='L') 
   mincp=max(mincp,id);
  if (temp[0]=='R')
   maxcp=min(maxcp,id-1);
 }
 
// cout<<l<<" "<<mincp<<"  "<<maxcp<<endl;
 if (mincp>maxcp){mem[l][r]=0;
  return false;}
  
 for (int cp=mincp;cp<=maxcp;cp++)
 {
  //if(cp==l)continue;
  if (solve(l+1,cp)&&solve(cp+1,r))
  {
   cut[l][r]=cp;
   mem[l][r]=1;
   return true;
  }
 }
 mem[l][r]=0;
 return false;
}

void dfs(long l,long r)
{
 if (l>r)return;
 if (l==r)
 {
  ans.push_back(l);
  return;
 }
 dfs(l+1,cut[l][r]);
 ans.push_back(l);
 dfs(cut[l][r]+1,r);
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>st;
 g[a].push_back(make_pair(b,st));
}


for (int q=1;q<=n;q++)
{
 Mincp[q]=-1;
 Maxcp[q]=n;
 for (int i=0;i<g[q].size();i++)
 {
  long id=g[q][i].first;
  string temp=g[q][i].second;
  if (temp[0]=='L') 
   Mincp[q]=max(Mincp[q],id);
  if (temp[0]=='R')
   Maxcp[q]=min(Maxcp[q],id-1);
 }
}
if (solve(1,n))
{
 //cout<<cut[1][n]<<endl;
 dfs(1,n);
 for (int i=0;i<ans.size();i++)
 {
  if (i)cout<<" ";
  cout<<ans[i];
 }
 cout<<endl;
}
else
{
 cout<<"IMPOSSIBLE"<<endl;
}
cin.get();cin.get();
return 0;}