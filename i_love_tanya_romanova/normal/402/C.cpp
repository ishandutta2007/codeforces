/*
I tear your heart out from behind
Remorse survives as mine
You're unaffected still unaware
Of the damage done

The shame it takes me
The pain it breaks me
What have I done?

How do I have to
For all is gone now?

I feel the ice-cold dagger
Make its way between my ribs again
I stand before disaster
Defiantly I lie then suffocate

I'm running on empty
I'm chasing a dead dream
I'm all out of time

Clutching the will
Only to feel
No way to heal

I tried to mend it to build it back
But the wound's become a scar
You're lying face down and you're veiled in red
The sight won't leave my head

The shame it takes me
The pain it breaks me
What have I done?

How do I have to
For all is gone now?

I feel the ice-cold dagger
Make its way between my ribs again
I stand before disaster
Defiantly I lie then suffocate

I'm running on empty
I'm chasing a dead dream
I'm all out of time

Clutching the will
Only to feel
No way to heal

No way to heal

I stand before disaster
Defiantly I lie then suffocate

I'm running on empty
I'm chasing a dead dream
I'm all out of time
I'm all out of time

Clutching the will
Only to feel
No way to heal

Running on empty
Chasing a dead dream
I'm all out of time

Clutching the will
Only to feel
There's no way to heal
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