/*
Lost in the storming of the north
someone warm up his own beloved
a feeble flower of the north

No one can hear their sos
but could someone ever care less,
of those two flowers grown in frozen grass?

She was brighter than a star
he loved to watch the rain
and just like a trick of life
they departed in winter

Two frozen hearts sleep in the dust
bonded by time in tears and rust
in the darkest hall of winter lust

No one could hear their sos
and no-one could ever care less,
about two creatures laid to rest
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,p,tests,deg[2000],m;
vector<pair<long, long> > g;
vector<pair<long,pair<long, long> > > v;
long ar[200][200];

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>n>>p;
 g.clear();
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
  {
   ar[i][j]=0; 
  }
  for (int i=1;i<=n;i++)
  deg[i]=0;
  
  for (int iter=1;iter<=n*2+p;iter++)
  {
   v.clear();
   for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
     if (ar[i][j]==0&&i!=j)
     {
      v.push_back(make_pair(deg[i]+deg[j],make_pair(i,j)));
     }
    }
    sort(v.begin(),v.end());
    ar[v[0].second.first][v[0].second.second]=ar[v[0].second.second][v[0].second.first]=1;
    g.push_back(make_pair(v[0].second.first,v[0].second.second));
    deg[v[0].second.first]++;
    deg[v[0].second.second]++;
  }
  for (int i=0;i<g.size();i++)
  cout<<g[i].first<<" "<<g[i].second<<endl;
}

cin.get();cin.get();
return 0;}