/*
Wish I were with you but I couldn't stay
Every direction leads me away
Pray for tomorrow but for today
All I want is to be home

Stand in the mirror, you look the same
Just lookin' for shelter from the cold and the pain
Someone to cover, safe from the rain
And all I want is to be home

Echoes and silence, patience and grace
All of these moments I'll never replace
No fear of my heart, absence of faith
And all I want is to be home

All I want is to be home

People I've loved, I have no regrets
Some I remember, some I forget
Some of them living, some of them dead
And all I want is to be home
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
#define N 120000

using namespace std;

long n,q,deg[200000];
long g[200000];
vector<pair<long, long> > c;
long used[200000];
long nd;
long cycls;

void dfs(long v)
{
 used[v]=1;
 nd=v;
 if (used[g[v]]==0)dfs(g[v]);
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 deg[q]++;
 g[i]=q;
}

for (int i=1;i<=n;i++)
 if(deg[i]==0&&used[i]==0)
 {
  dfs(i);
  c.push_back(make_pair(i,nd));
 }

for(int i=1;i<=n;i++)
 if (used[i]==0)
 {
  dfs(i);
  cycls++;
  c.push_back(make_pair(i,nd));
 }

if (cycls==c.size()&&c.size()==1) cout<<0<<endl;
else
{
 cout<<c.size()<<endl;
 for (int i=0;i<c.size();i++)
 {
  cout<<c[i].second<<" "<<c[(i+1)%c.size()].first<<endl;
 }
}
cin.get();cin.get();
return 0;}