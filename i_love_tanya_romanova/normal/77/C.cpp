/*
Just one more high
This life is all I know
Hide in myself
I'm condemned by myself

I'll decay before my time
Choking upon this guilty deed of mine
Home on the floor, you can hit me once more
Will power is dead and gone

Confined
This guilty deed of mine
My life, I'll decay before my time
Confined

Just sit back and watch it all
I can't be what you want from me
Regret has set
And sank its teeth in me

Into the skin, not knowing when I will win
Bruised body is all I hold
It's not my choice, I have no grip on this
Blinded by light, always losing my fight
Just crumble and lose it all

Confined
This guilty deed of mine
My life, I'll decay before my time
Confined
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

long long n,ar[1<<20],a,b,ans[1<<20];
long long rem[1<<20];
long long used[1<<20];
vector<long long> g[1<<20];
long root;

void solve(long v)
{
 used[v]=1;
 ans[v]=1;

 if (v!=root)--ar[v];
 vector<pair<long long, long long> > sons;
 for (int i=0;i<g[v].size();i++)
 {
     long id=g[v][i];
     if (used[id])continue;
     solve(id);
     sons.push_back(make_pair(ans[id],id));
 }
 sort(sons.begin(),sons.end());
 reverse(sons.begin(),sons.end());
 for (int i=0;i<sons.size();i++)
 {
  if (ar[v]==0)break;
  --ar[v];
  ans[v]+=sons[i].first+1;
 }
 long long rrem=0;
 for (int i=0;i<sons.size();i++)
 {
  rrem+=rem[sons[i].second];
 }
 rrem=min(rrem,ar[v]);
 ar[v]-=rrem;
 rem[v]=ar[v];
 ans[v]+=2*rrem;
}

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=1;i<n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

//long root;

cin>>root;
solve(root);
cout<<ans[root]-1<<endl;

/*for  (int i=1;i<=n;i++)
cout<<ans[i]<<"  "<<rem[i]<<endl;
*/

cin.get();cin.get();
return 0;}