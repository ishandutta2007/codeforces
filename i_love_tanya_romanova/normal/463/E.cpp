/*
Tonight, I don't wanna be me
I live in a dreamworld
It seems to be inevitable
Expect more things to fail
Next gasp of breath, next perfect way
To prevail...
I shall be reborn in this moment
Don't wanna die in vain...

If I could find chivalry
In those moments when I crack and fall
Rise and stand against the wall
And no one knows I can see it all
So many times I've seen it break
Tonight, I carry the cape of fear
Since love's the only thing that can't hate
Hate is the last shadow I wear

Tonight, I ease my restless soul
While my body lies in flaming torment
It's a long way to turn around
When death is just another door
...Just another door...

I keep those things safe in my head
That should not be
Tonight, I leave them under lock and key
Killing of time begins
My mind wanders, my soul aches
Shall I be afraid?
Should I stand my ground and stay?
Leave the weak behind and survive

Tonight, I ease my restless soul
While my body lies in flaming torment
It's a long way to turn around
When death is just another door
...Just another door...

I close yet another door
In every struggle I feel insecure
Close my mind to stay awake
In the last eye of the storm
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
#define rmost agasdgasdg

using namespace std;

long prime[1<<21];
vector<long> divs[1<<21];
long n,tests,ar[1<<21];
long a,b,tp;
vector<long> g[1<<21];
long ans[1<<21];
vector<long> cur[1<<21];
long ans1[1<<21];
long dep[1<<21];

void solve(long v,long par=-1)
{
 ans[v]=-1;
 ans1[v]=-1;
 for (int i=0;i<divs[ar[v]].size();i++)
 {
  long q=divs[ar[v]][i];
  if (cur[q].size()>0)
  {
   long t=cur[q].back();
   if (dep[t]>ans1[v]){
   ans[v]=cur[q].back();
   ans1[v]=dep[t];}
  }
  cur[q].push_back(v);
 }
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (q==par)continue;
  dep[q]=dep[v]+1;
  solve(q,v);
 }
 for (int i=0;i<divs[ar[v]].size();i++)
 {
  long q=divs[ar[v]][i];
  cur[q].pop_back();
 }
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

prime[1]=1;
for (int i=2;i<=2000000;i++)
 if (prime[i]==0)
 {
  for (int j=i;j<=2000000;j+=i)
  {
   divs[j].push_back(i);
   prime[j]=1;
  }
 }

cin>>n>>tests;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

solve(1);
for (;tests;--tests)
{
 cin>>tp;
 if (tp==2){cin>>a>>b;ar[a]=b;solve(1);}
 else 
 {
      cin>>a;
      cout<<ans[a]<<endl;
  }
}

cin.get();cin.get();
return 0;}