/*
I thought a desires worth any pleasure, every really real sin in vain
One hundred and one shots of opportunity, I'd gladly take them all again and again and again

My angel's left me, sorrows are my own
Now I'm here, with the Devil on my own
Just like a churchyard shadow, craving after me
It's only there to terrify my mind, a black swan keeps haunting me

I promised on my soul, not to get carried away
It always starts on psychedelic, and then it turns to black
My head starts swaying, I forgot what it was that I was saying
I don't know where I am, and I'll never, never make it back

I sealed my fate, and I paid my debt
I fell from grace with deep regret

My angel's left me, sorrows are my own
Now I'm here, with the Devil on my own
Just like a churchyard shadow, craving after me
It's only there to terrify my mind, a black swan keeps haunting me
Just like a churchyard shadow, there's nothing left to see
It's only there to terrify my mind, a black swan keeps haunting me

My angel's left me, sorrows are my own
Now I'm here, with the Devil on my own
Just like a churchyard shadow, craving after me
It's only there to terrify my mind, a black swan keeps haunting me
Just like a churchyard shadow, there's nothing left to see
It's only there to terrify my mind, a black swan keeps haunting me

Just like a churchyard shadow, craving after me
There's nothing left to see, nothing left for me
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
 
using namespace std;

long used[1<<20];
long subsize[1<<20];
vector<pair<pair<long, long> ,long> > g[1<<19];
double edge_cost[1<<20];
double ans;
long a[1<<20],b[1<<20],l[1<<20];
double c[1<<19][4];
long n;

void dfs(long v)
{
 used[v]=1;
 subsize[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long id=g[v][i].first.first;
  if (used[id])continue;
  dfs(id);
  subsize[v]+=subsize[id];
  double tcost=g[v][i].first.second;
  double ways1=c[n-subsize[id]][2]*c[subsize[id]][1];// 2 out, 1 in
  double ways2=c[n-subsize[id]][1]*c[subsize[id]][2];// 2 in, 1 out
  int edge_id=g[v][i].second;
  edge_cost[edge_id]=(ways1+ways2)*2;
  ans+=edge_cost[edge_id]*tcost;
 }
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
 cin>>a[i]>>b[i]>>l[i];
/*a[i]=i;
b[i]=i+1;
l[i]=1000;*/
 g[a[i]].push_back(make_pair(make_pair(b[i],l[i]),i));
 g[b[i]].push_back(make_pair(make_pair(a[i],l[i]),i));
}

for (int i=0;i<=111111;i++)
{
 for (int j=0;j<=3&&j<=i;j++)
 {
  if (j==0||j==i)
   c[i][j]=1;
   else
   c[i][j]=c[i-1][j]+c[i-1][j-1];
 }
}

dfs(1);

cout.precision(10);

//cout<<fixed<<ans/c[n][3]<<endl;

long q,id;

cin>>q;
for (;q;--q)
{
 cin>>id;
 double old=l[id];
 cin>>l[id];
 ans-=edge_cost[id]*(old-l[id]);
 cout<<fixed<<ans/c[n][3]<<endl;
}

cin.get();cin.get();
return 0;}