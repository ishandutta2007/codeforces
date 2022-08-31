/*
Another day in my life
I live and die by the knife
I swear there's nothing inside
Sometimes I wish it would end
How many hands could I shake
How many smiles must I fake
How many miles till I break
To start all over again
That's not what I was promised
That's not me

Feels like I'm falling away
Getting deeper and deeper everyday
And like nothing has changed or ever will
It seems like I'm going insane
Getting farther and farther everyday
I just swallow the pain
And always will
Welcome to a day in my life
Welcome to a day in my fucking life!

Unleashed the beast from its cage
Feel like a puppet on stage
It only adds to the rage
I'm sick of trying to pretend
They think I'm something I'm not
I give them all that I got
Feels like I'm soul to be bought
It starts all over again
That's not what I was promised
That's not me

Feels like I'm falling away
Getting deeper and deeper everyday
And like nothing has changed or ever will
It seems like I'm going insane
Getting farther and farther everyday
I just swallow the pain
And always will
Welcome to a day in my life
Welcome to a day in my fucking life!

It feels like I'm falling away
I'm getting deeper and deeper everyday
And like nothing has changed or ever will
It seems like I'm going insane
Getting farther and farther everyday
I just swallow the pain
And always will
I just swallow the pain
And always will
Welcome to a day in my life
Welcome to a day in my fucking life!
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