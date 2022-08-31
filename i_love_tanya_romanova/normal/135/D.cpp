/*
People like you
You live in a dream world
You despise the outside
And you fear the next one

Its in your dream
Theres just one question
Should I kill
Or should I be left behind?

Sick and tired
Of all your complaints
This is the hour
We bring it down

Ive come to realize
With every little glimpse you fade
I was told that I could fly
When least expected, cloud connected

You seem to be
So introverted
How come we fail
With all that is given

You crossed the line
You remember my name
Time runs backwards
As we're heading that way

I've come to realize
With every little glimpse you fade
I was told that I could fly
When least expected, cloud connected

Why don't you realize
With every little glimpse you fade
I was told that I could fly
When least expected, cloud connected
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,m;
string st;
long ar[1010][1010];
long arp0[1010][1010];
long bnd;
vector<pair<long, long> > ones;
long iter;
long done[1010][1010];
long checkd,er;
long ans;

void dfs0(long x,long y)
{
 if (x<=0||x>n||y<=0||y>m)return ;
 arp0[x][y]=1;
 if (x==1||x==n||y==1||y==m)bnd=1;
 if (ar[x-1][y]==0&&arp0[x-1][y]==0)dfs0(x-1,y);
 if (ar[x+1][y]==0&&arp0[x+1][y]==0)dfs0(x+1,y);
 if (ar[x][y-1]==0&&arp0[x][y-1]==0)dfs0(x,y-1);
 if (ar[x][y+1]==0&&arp0[x][y+1]==0)dfs0(x,y+1);
 
 if (ar[x+1][y+1]==0&&arp0[x+1][y+1]==0)dfs0(x+1,y+1);
 if (ar[x-1][y+1]==0&&arp0[x-1][y+1]==0)dfs0(x-1,y+1);
 if (ar[x+1][y-1]==0&&arp0[x+1][y-1]==0)dfs0(x+1,y-1);
 if (ar[x-1][y-1]==0&&arp0[x-1][y-1]==0)dfs0(x-1,y-1);
 
 if (ar[x-1][y]==1&&done[x-1][y]!=iter)
 {
  ones.push_back(make_pair(x-1,y));
  done[x-1][y]=iter;
 }
 if (ar[x+1][y]==1&&done[x+1][y]!=iter)
 {
  ones.push_back(make_pair(x+1,y));
  done[x+1][y]=iter;
 }
 if (ar[x][y-1]==1&&done[x][y-1]!=iter)
 {
  ones.push_back(make_pair(x,y-1));
  done[x][y-1]=iter;
 }
 if (ar[x][y+1]==1&&done[x][y+1]!=iter)
 {
  ones.push_back(make_pair(x,y+1));
  done[x][y+1]=iter;
 }
 
 if (ar[x+1][y+1]==1&&done[x+1][y+1]!=iter)
 {
  ones.push_back(make_pair(x+1,y+1));
  done[x+1][y+1]=iter;
 } 
 if (ar[x-1][y+1]==1&&done[x-1][y+1]!=iter)
 {
  ones.push_back(make_pair(x-1,y+1));
  done[x-1][y+1]=iter;
 } 
 if (ar[x+1][y-1]==1&&done[x+1][y-1]!=iter)
 {
  ones.push_back(make_pair(x+1,y-1));
  done[x+1][y-1]=iter;
 } 
 if (ar[x-1][y-1]==1&&done[x-1][y-1]!=iter)
 {
  ones.push_back(make_pair(x-1,y-1));
  done[x-1][y-1]=iter;
 }
}

long gf(pair<long, long> p)
{
 long x,y;
 x=p.first;
 y=p.second;
 long r=0;
 if (ar[x-1][y]==1&&done[x-1][y]==iter-1)++r;
 if (ar[x+1][y]==1&&done[x+1][y]==iter-1)++r;
 if (ar[x][y-1]==1&&done[x][y-1]==iter-1)++r;
 if (ar[x][y+1]==1&&done[x][y+1]==iter-1)++r;
 return r;
}

void dfs1(long x,long y)
{
 done[x][y]=iter;
 ++checkd;
 if (ar[x-1][y]==1&&done[x-1][y]==iter-1)
  dfs1(x-1,y);
 if (ar[x+1][y]==1&&done[x+1][y]==iter-1)
  dfs1(x+1,y);
 if (ar[x][y-1]==1&&done[x][y-1]==iter-1)
  dfs1(x,y-1);
 if (ar[x][y+1]==1&&done[x][y+1]==iter-1)
  dfs1(x,y+1);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
 {
  if (st[j-1]=='1')ar[i][j]=1;else ar[i][j]=0;
 }
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (arp0[i][j]==0&&ar[i][j]==0)
  {
   bnd=0;
   ++iter;
   ones.clear();
   dfs0(i,j);
   checkd=0;
   ++iter;
//   cout<<ones.size()<<endl;
   if (bnd)continue;
   er=0;
   for (int i=0;i<ones.size();i++)
   {
    if (gf(ones[i])!=2)er=1;
   }
   if (er)continue;
   dfs1(ones[0].first,ones[0].second);
   if (checkd==ones.size())
   {
    long p=ones.size();
    ans=max(ans,p);
   }
  }
 }

if (ans==0)

for (int i=1;i<n;i++)
 for (int j=1;j<m;j++)
 {
  if (ar[i][j]+ar[i][j+1]+ar[i+1][j]+ar[i+1][j+1]==4)ans=4;
 }
 
cout<<ans<<endl;

cin.get();cin.get();
return 0;}