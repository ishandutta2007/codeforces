/*
The first thing that I saw as,
the fisherman smiled at me
Were empty people dressed in grey,
floating out to sea
The rain lashed down in darkness
A lizard blinked an eye
And time stopped in the silence
The small fish gave a cry

The next thing that I saw as,
things were fading fast
Were dreams of children's laughter,
smouldering to dust
The rain lashed down in darkness
A lizard blinked an eye
And time stopped in the silence
The small fish gave a cry

The last thing that I saw as, my life passed by
Were fields of empty people, laying down to die
The rain lashed down in darkness
A lizard blinked an eye
And time stopped in the silence
To watch the burning sky.
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

class Fenwick
{
 long long *m,*mt,N;
 public:
 Fenwick(long n);
 Fenwick(long long a[],long n);
 void add_range(long l,long long d);
 void add_range(long l,long r,long long d);
 long long sum(long r);
 long long sum(long l,long r);
};

Fenwick::Fenwick(long n)
{
 N=n;
 m=new long long[N];
 mt=new long long[N];
 for (int i=0;i<n;i++)
 m[i]=mt[i]=0;
}

void Fenwick::add_range(long r,long long d)
{
 if (r<0)return;
 for (int i=r;i>=0;i=(i&(i+1))-1){mt[i]+=d;mt[i]%=bs;}
 for (int i=r|(r+1);i<N;i|=i+1){m[i]+=d*(r-(i&(i+1))+1)%bs;m[i]%=bs;}
}

void Fenwick::add_range(long l,long r,long long d)
{
 add_range(r,d);
 add_range(l-1,-d);
}

long long Fenwick::sum(long r)
{
 if (r<0)return 0;
 long long res=0;
 for (int i=r;i>=0;i=(i&(i+1))-1){res+=m[i]+mt[i]*(i-(i&(i+1))+1);res%=bs;}
 for (int i=r|(r+1);i<N;i|=i+1){res+=mt[i]*(r-(i&(i+1))+1);res%=bs;}
 return res;
}

long long Fenwick::sum(long l,long r)
{
 return sum(r)-sum(l-1);
}

long timer,l[500000],r[500000],dep[500000];
vector<long> g[500000];
long n,q,m;

void dfs(long v)
{
 ++timer;
 l[v]=timer;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  dep[q]=dep[v]+1;
  dfs(q);
 }
 r[v]=timer;
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=2;i<=n;i++)
{
 cin>>q;
 g[q].push_back(i);
}

Fenwick f1(500000),f2(500000);

dfs(1);

cin>>m;
long long tp,v,x,k;

for (int i=1;i<=m;i++)
{
 cin>>tp;
 if (tp==2)
 {
  cin>>v;
  long long res=f1.sum(l[v],l[v]);
  res-=f2.sum(l[v],l[v])*dep[v];
  res%=bs;
  if (res<0)res+=bs;
  cout<<res<<endl;
 }
 else
 {
  cin>>v>>x>>k;
  f2.add_range(l[v],r[v],k);
  f1.add_range(l[v],r[v],(x+dep[v]*k)%bs);
 }
}

cin.get();cin.get();
return 0;}