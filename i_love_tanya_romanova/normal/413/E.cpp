/*
We are the chosen ones, we sacrifice our blood
We kill for honor
We are the holy ones our armours stained with blood
We killed the dragon
In glory we return, our destination's end
We slayed the dragon!
No more living in fear it's time to raise our king.
We made it happen we're the chosen ones!

Riding through thunder and lighting once again
We slayed the beast we brought an end
Now we have left the kingdom of the damned
Heroes of the day, legends forever!

It seems to me like a journey without end
So many years, too many battles
We've finally arrived, now we're standing at the gates
Heroes of the day, legends forever
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

string st1,st2;
long n,m,used[500000];
vector<long> g[500000];
long comp;
long a,b;
long ttl[500000];
set<long> sett;
long x1,y1,x2,y2;
set<long>::iterator it;
long p1,p2,last,tans;

void dfs(long v)
{
 used[v]=comp;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  dfs(q);
 }
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>st1;
cin>>st2;
for (int i=0;i<n;i++)
{
 if (st1[i]=='.'&&st2[i]=='.')
 {
  g[i].push_back(i+n);
  g[i+n].push_back(i);
 }
 if (i>0&&st1[i]=='.'&&st1[i-1]=='.')
 {
  g[i].push_back(i-1);
  g[i-1].push_back(i);
 }
 if (i>0&&st2[i]=='.'&&st2[i-1]=='.')
 {
  g[i+n].push_back(i+n-1);
  g[i+n-1].push_back(i+n);
 }
}

for (int i=0;i<n*2;i++)
{
 if (used[i]==0)
 {
  comp++;
  dfs(i);
 }
}

for (int i=0;i<n;i++)
{
 if (i)ttl[i]=ttl[i-1];
 if (st1[i]=='X')
 {
  if (last>0)ttl[i]++;
  last=0;
 }
 if (st2[i]=='X')
 {
  if (last==0)ttl[i]++;
  last=1;
 }
 if (st1[i]=='X'||st2[i]=='X')
 sett.insert(i);
}

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 --a;
 --b;
 if (used[a]!=used[b])// dif
 {
  cout<<-1<<endl;
  continue;
 }
 y1=a/n;
 x1=a%n;
 y2=b/n;
 x2=b%n;
 if (x1>x2)
 {swap(x1,x2);swap(y1,y2);}
 it=sett.lower_bound(x1);
 if (it==sett.end()||(*it)>x2)// clear way
 {
  cout<<abs(x2-x1)+(y2!=y1)<<endl;
  continue;
 }
 p1=(*it);
 tans=0;
 tans+=p1-x1;
 if (st1[p1]=='X'&&y1==0)++tans;
 if (st2[p1]=='X'&&y1==1)++tans;
 it=sett.upper_bound(x2);
 --it;
 p2=(*it);
 tans+=x2-p2;
 if (st1[p2]=='X'&&y2==0)++tans;
 if (st2[p2]=='X'&&y2==1)++tans;
 tans+=p2-p1;
 tans+=ttl[p2]-ttl[p1];
 cout<<tans<<endl;
}

cin.get();cin.get();
return 0;}