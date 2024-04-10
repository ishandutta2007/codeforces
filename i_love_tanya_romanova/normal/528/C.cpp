/*
Crawling through broken glass
But I feel no pain, no pain at all
Fed through the grief machine
Just lifelessness within my soul

My trembling hands on
A cold tile floor
I had a vision
The night before

That I am bleeding
My inside out
In need for shelter
I'd die without

According to my heartbeat
I'm already dead, already dead
I'm falling down a black hole
My sleep won't bring relief, won't bring relief

Wake up in fear
Scared of the dark

Cold hand touches my heart
But I feel no cold, no cold at all
Craving for inner peace
Colliding with an evil force

These revelations
Shown in my dreams
I cannot read them
I just hear screams

And still I'm bleeding
My inside out
In need for shelter
I'd die without!

According to my heartbeat
I'm already dead, already dead
I'm falling down a black hole
My sleep won't bring relief, won't bring relief

Wake up in fear
Scared of the dark

From the depths of hell my fate will rise
Profound and inferior, an opponent to warming lights
My nightmares start to become reality

According to my heartbeat
I'm already dead, already dead
I'm falling down a black hole
My sleep won't bring relief
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
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

long n,a,b,m;
vector<long> odd;
vector<pair<long, long> > edges;
vector<long> g[1<<20];
long deg[1<<20];
vector<pair<long, long> > ans;
long ptr[1<<20];
long used[1<<20];

void dfs(long v)
{
 //cout<<"%"<<v<<endl;
 
 for (;ptr[v]<g[v].size();ptr[v]++)
 {
  long id=g[v][ptr[v]];
  long a,b;
  a=edges[id].first;
  b=edges[id].second;
  if (a!=v)
   swap(a,b);
  if (used[id])continue;
  used[id]=1;
  dfs(b);
  ans.push_back(make_pair(b,a));
 }
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 edges.push_back(make_pair(a,b));
 deg[a]++;
 deg[b]++;
 g[a].push_back(i-1);
 g[b].push_back(i-1);
}

for (int i=1;i<=n;i++)
 if (deg[i]%2)
 {
  odd.push_back(i);
 }

for (int i=0;i<odd.size();i+=2)
{
 int id1=odd[i];
 int id2=odd[i+1];
 edges.push_back(make_pair(id1,id2));
 g[id1].push_back(edges.size()-1);
 g[id2].push_back(edges.size()-1);
} 

if (edges.size()%2==1)
{
 g[1].push_back(edges.size());
 edges.push_back(make_pair(1,1));
}

dfs(1);
cout<<ans.size()<<endl;

for (int i=0;i<ans.size();i++)
{
 if (i%2)swap(ans[i].first,ans[i].second);
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

cin.get();cin.get();
return 0;}