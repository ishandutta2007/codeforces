/*
Love me two times, baby
Love me twice today
Love me two times, girl
I'm goin' away

Love me two times, girl
One for tomorrow
One just for today
Love me two times
I'm goin' away

Love me one time
Could not speak
Love me one time
Yeah, my knees got weak

Love me two times, girl
Last me all through the week

Love me two times
I'm goin' away
Love me two times
I'm goin' away, oh, yes

Love me one time
Could not speak
Love me one time, baby
Yeah, my knees got weak

Love me two times, girl
Last me all through the week

Love me two times
I'm goin' away
Love me two times, babe
Love me twice today

Love me two times, babe
'Cause I'm goin' away
Love me two time, girl
One for tomorrow
One just for today

Love me two times
I'm goin' away
Love me two times
I'm goin' away
Love me two times
I'm goin' away
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
#define right adsgasgadsg

using namespace std;

long n;
long ar[1<<11][1<<11],ans[1<<11][1<<11];
long dist[1<<11];
long used[1<<11],bst;
long bp;
long par[1<<11];
vector<pair<long, long> >g[1<<11];
queue<long> qu;
long arp[1<<11];
long temp;
long er;

void add_edge(long a,long b,long c)
{
// cout<<a<<"  "<<b<<" "<<c<<endl;
 g[a].push_back(make_pair(b,c));
 g[b].push_back(make_pair(a,c));
}

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
  cin>>ar[i][j];
 }

for (int i=1;i<=n;i++)
dist[i]=2e9;
dist[1]=0;

for (int iter=1;iter<=n;iter++)
{
 bst=2e9;
 for (int i=1;i<=n;i++)
  if (used[i]==0&&dist[i]<bst)
  {
   bst=dist[i];
   bp=i;
  }   
 if (iter>1)
  add_edge(par[bp],bp,bst);
 
 if (bst==0&&iter>1)er=1;
 
 used[bp]=1;
 for (int i=1;i<=n;i++)
  if (ar[bp][i]<dist[i]&&used[i]==0)
  {
   par[i]=bp;
   dist[i]=ar[bp][i];
  }
}

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)
  arp[j]=0;
 qu.push(i);
 arp[i]=1;
 while(qu.size())
 {
  temp=qu.front();
  qu.pop();
  for (int j=0;j<g[temp].size();j++)
  {
   long tv=g[temp][j].first;
   long tc=g[temp][j].second;
   if (arp[tv])continue;
   arp[tv]=1;
   ans[i][tv]=ans[i][temp]+tc;
   qu.push(tv);
   arp[tv]=1;
  }
 }
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  if (ar[i][j]!=ans[i][j])er=1;
 
if (er)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}