/*
I'm alive in here
So alive in here
Pulling down a little peace
I'm open wide in here
Slow to rise in here
Saving grace and killing me

You say this only makes me incomplete
I'm cancelled out and rendered obsolete
Tell the Machiavellian he's not welcome anymore
I know what I'm looking for

Somewhere close!
Somewhere safe!
Somewhere I know, I know, I'll never live in chains
The one, is now aware, so stay away from me
I'm just too young to care!

I can see in here
And I can feel in here
Comatose with common sense
I take my time in here
Somebody get me out of here
What am I so against?

I just wanna watch the whole world burn
Lost a million times and I won't learn
Show me someone innocent
I'll show you there's no proof
I may be gullible but I'm no fool

I'm not close
I'm not safe
I don't know, dunno, am I better off in chains?
The one, is not aware, so stay away from me
I'm just too young to care

I need somewhere close!
Somewhere safe
Somewhere I know, I know, I'll never live in chains
The one, is now aware, so stay away from me
I'm just too young to care
Oh, oh
Too young to care!
Oh, oh!
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

string st;
long n,m,ar[1<<11][1<<11];
long deg[1<<11][11<<11];
set<pair<long, long> >leaves;
set<pair<long, long> >::iterator it;
long cnt;
vector<long> edges;
pair<long, long> tp;
long qi,qj;

bool check(long a,long b)
{
 if (a<1||a>n||b<1||b>m) return false;
 if (ar[a][b])return false;
 return true;
}

void tryy(long a,long b)
{
 if (a<1||a>n||b<1||b>m)return;
 deg[a][b]--;
 if (deg[a][b]==1&&ar[a][b]==0)
  leaves.insert(make_pair(a,b));
}

void doupd(long a,long b)
{
 tryy(a-1,b);
 tryy(a+1,b);
 tryy(a,b-1);
 tryy(a,b+1);
}

void add_edge(long x1,long y1,long x2,long y2)
{
// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
 edges.push_back(1);
 
 if (x1==x2)
 {
  ar[x1][y1]=2;
  ar[x2][y2]=3;
 }
 else
 {
  ar[x1][y1]=4;
  ar[x2][y2]=5;
 }
 
 doupd(x1,y1);
 doupd(x2,y2);
 if (leaves.find(make_pair(x1,y1))!=leaves.end())
  leaves.erase(make_pair(x1,y1));
 if (leaves.find(make_pair(x2,y2))!=leaves.end())
  leaves.erase(make_pair(x2,y2));
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
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
        if (st[j-1]=='.')
        {
         ar[i][j]=0;
         }
         else ar[i][j]=1;
    }
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (ar[i][j]==0)
  {
   if (check(i-1,j))++deg[i][j];
   if (check(i+1,j))++deg[i][j];
   if (check(i,j-1))++deg[i][j];
   if (check(i,j+1))++deg[i][j];
   if (deg[i][j]==1)
   {
    leaves.insert(make_pair(i,j));
   }
//   cout<<i<<"  "<<j<<" "<<deg[i][j]<<endl;
   ++cnt;
  }
 }

while (leaves.size())
{
 it=leaves.begin();
 tp=(*it);
 leaves.erase(it);
 qi=tp.first;
 qj=tp.second;
 if (ar[qi][qj])continue;// ?
// cout<<"^"<<qi<<" "<<qj<<" "<<deg[qi][qj]<<endl;
 if (check(qi-1,qj))
 {
  add_edge(qi-1,qj,qi,qj);
 }
 if (check(qi+1,qj))
 {
  add_edge(qi,qj,qi+1,qj);
 }
 if (check(qi,qj-1))
 {
  add_edge(qi,qj-1,qi,qj);
 }
 if (check(qi,qj+1))
 {
  add_edge(qi,qj,qi,qj+1);
 }
}

//cout<<edges.size()<<endl;

if (edges.size()*2!=cnt)
{
 cout<<"Not unique"<<endl;
}
else
{
    for (int i=1;i<=n;i++)
    {
     for (int j=1;j<=m;j++)
     {
//      cout<<ar[i][j];
//      continue;
      if (ar[i][j]==1)
       cout<<"*";
      if (ar[i][j]==4)
       cout<<"^";
      if (ar[i][j]==5)
       cout<<"v";
      if (ar[i][j]==2)
       cout<<"<";
      if (ar[i][j]==3)
       cout<<">";
     }
     cout<<endl;
    }
}

cin.get();cin.get();
return 0;}