/*
Now we are here, we are closer to absolute control
More than ever before
My growing desire to conquer the world
Increases over night

This surge of poetic tyranny
Gushes through my body conduits
Feelings meet me face to face, I stand up taller than you
And watch my hands smother this world

I want to leave millions hypnotized
And gasping for their last breath
I have been here once before by myself
This is nothing new for me

I am degraded and thrown aside
Realization steps away from its waltz
With my mental shadows
To present this uncoated truth
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long a1,a2,b1,b2,cur,val;
set<long long> s[3];
set<long long> ::iterator it;
map<long long, pair<long long ,long long> > vert[10];
map<long long, long long> dist[10];
long long ans,d;
set<pair<long long, long long> >was;
queue<pair<long long, pair<long long, long long> > > qu;
pair<long long, pair<long long, long long> > temp;
long long qd;

void tryy(long long a,long long b)
{
 if (was.find(make_pair(a,b))!=was.end()) return;
 was.insert(make_pair(a,b));
 qu.push(make_pair(a*b,make_pair(a,b)));
 if (s[cur].find(a*b)==s[cur].end())
 {
  s[cur].insert(a*b);
  dist[cur][a*b]=qd+1;
  vert[cur][a*b]=make_pair(a,b);
 }
}

void solve(long long a,long long b)
{
 was.clear();
 qu.push(make_pair(a*b,make_pair(a,b)));
 s[cur].insert(a*b);
 was.insert(make_pair(a,b));
 vert[cur][a*b]=make_pair(a,b);
 dist[cur][a*b]=0;
 while(qu.size())
 {
  temp=qu.front();
  a1=temp.second.first;
  b1=temp.second.second;
  qd=dist[cur][a1*b1];
  qu.pop();
  if (a1%2==0)
  {
   tryy(a1/2,b1);
  }
  if (a1%3==0)
  {
   tryy(a1/3*2,b1);
  }
  if (b1%2==0)
   tryy(a1,b1/2);
  if (b1%3==0)
   tryy(a1,b1/3*2);
 }
 
}

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a1>>b1;
cin>>a2>>b2;

cur=1;
solve(a1,b1);
cur=2;
solve(a2,b2);

pair<long long, long long> a1,a2;
ans=2e9;
for (it=s[1].begin();it!=s[1].end();++it)
{
    val=(*it);
    if (s[2].find(val)==s[2].end())continue;
    d=dist[1][val]+dist[2][val];
    if (d<ans)
    {
     ans=d;
     a1=vert[1][val];
     a2=vert[2][val];
    }
}

if (ans>1e6)cout<<-1<<endl;
else 
{
     cout<<ans<<endl;
     cout<<a1.first<<" "<<a1.second<<endl;
     cout<<a2.first<<" "<<a2.second<<endl;
}
 
cin.get();cin.get();
return 0;}