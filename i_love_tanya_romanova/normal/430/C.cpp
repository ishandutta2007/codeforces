/*
Scorched by winters wrath
I lay still in the night
This winter choking embrace
Leaves me with no will to fight

Timeless winter
Timeless winter

My heart decayed and dead end
By this ravenous winter
For see this end is frozen
Begins this timeless winter

Forever crimson
Warmth shrouds my body and soul
As two worlds collide
My being dwells within this empty black hole

Death embraces me
Destroying my sanity
Reaching for the light
Fading to darkness
This feeling of emptiness
My physical perish sight

My heart decayed and dead end
By this ravenous winter
For see this end is frozen
Begins this timeless winter

Seamless never ending time
As I begin to quiver
I lay still with this crystals of cold
This lifeless body begins to wither

Timeless winter
Timeless winter

My heart decayed and dead end
By this ravenous winter
For see this end is frozen
Begins this timeless winter
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;
 
 long n,a,b,ar1[200000],ar2[200000];
 vector<long> g[200000];
 vector<long> ans;
 long used[200000];
 
void solve (long v,long cur, long prev)
{
 used[v]=1;
 long temp=ar1[v];
 temp^=cur;
 if (temp!=ar2[v])
 {
  ans.push_back(v);
  cur^=1;
 }
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
   solve(q,prev,cur);
 }
}
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n;
for (int i=1;i<n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);   
}
for (int i=1;i<=n;i++)
cin>>ar1[i];
for (int i=1;i<=n;i++)
cin>>ar2[i];
solve(1,0,0);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}