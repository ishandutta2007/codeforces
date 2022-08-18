/*
Haven't slept in the week
My bed has become my coffin
Cannot breath, cannot speak
My head's like a bomb, still waiting
Take my heart and take my soul
I don't need them anymore

The one I love
Is striking me down on my knees
The one I love
Drowning me in my dreams
The one I love
Over and over again
Dragging me under

Hypnotized by the night
Silently rising beside me
Emptiness, nothingness
Is burning a hole inside me
Take my faith and take my pride
I don't need them anymore

The one I love
Is striking me down on my knees
The one I love
Drowning me in my dreams
The one I love
Over and over again
Dragging me under

This bed has become my chapel of stone
A garden of darkness to where I'm thrown
So take my life
I don't need it anymore

The one I love
Is striking me down on my knees
The one I love
Drowning me in my dreams
The one I love
Over and over again
Dragging me under

The one I love
Is striking me down on my knees
Drowning me in my dreams
Over and over again
Over and, over and
Over and, over
Again
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
#define free adsgasdg

using namespace std;

string st;
vector<pair<long, long> > g[33][33];
long arp[33][33];
queue<pair<long, long> > qu;
pair<long, long> temp;
long dx,dy,qx,qy,tx,ty;
long n,m,er;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

cin>>st;
for (int i=1;i<=n;i++)
{
 if (st[i-1]=='<')
  for (int j=2;j<=m;j++)
   g[i][j].push_back(make_pair(i,j-1));
  else 
  for (int j=1;j<m;j++)
   g[i][j].push_back(make_pair(i,j+1));
}

cin>>st;
for (int i=1;i<=m;i++)
{
 if (st[i-1]=='^')
 for (int j=2;j<=n;j++)
  g[j][i].push_back(make_pair(j-1,i));
  else
 for (int j=1;j<n;j++)
  g[j][i].push_back(make_pair(j+1,i));
}

for (int sx=1;sx<=n;sx++)
 for (int sy=1;sy<=m;sy++)
 {
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
    arp[i][j]=0;
  arp[sx][sy]=1;
  qu.push(make_pair(sx,sy));
  while (qu.size())
  {
   temp=qu.front();
   qu.pop();
   tx=temp.first;
   ty=temp.second;
   for (int j=0;j<g[tx][ty].size();j++)
   {
    dx=g[tx][ty][j].first;
    dy=g[tx][ty][j].second;
    if (arp[dx][dy])continue;
    arp[dx][dy]=1;
    qu.push(make_pair(dx,dy));
   }
  }
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
    if (arp[i][j]==0)er=1;
 }

if (er)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}