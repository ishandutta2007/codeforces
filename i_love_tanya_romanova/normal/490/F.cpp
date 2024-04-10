/*
I am impatient, hard to please
No sense of serenity, habitual neurosis
Transcends into thoughts of suicide

And when this body lays lifeless
Don't patronize me by
Insisting this was all done because of you

I am beyond redemption
Even in death I will not speak
I am beyond redemption
Even in death I will not sleep

With abandonment of trust and self
Hope is void of longevity, a shelterless recluse
I survive without reason

And when this body lays lifeless
Don't patronize me by
Insisting this was all done because of you

I am beyond redemption
Even in death I will not speak
I am beyond redemption
Even in death I will not sleep

I am beyond redemption
Even in death I will not speak
I am beyond redemption
Even in death I will not sleep

I sacrifice myself to the lonely other
For she will not rest until
Death's arms embrace me

I am beyond redemption
Even in death I will not speak
I am beyond redemption
Even in death I will not sleep

I am beyond redemption
Even in death I will not speak
I am beyond redemption
Even in death I will not sleep
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

long n,r[1<<20];
vector<pair<long, long> > order;
long a,b;
vector<long > g[1<<20];
long ans[6060][6060];
long id,used[1<<20];
long bst;
long answ;

void dfs(long v)
{
 if (r[v]<r[id])bst=max(bst,ans[v][v]);
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
     long ii=g[v][i];
     if (used[ii])continue;
     if (r[v]<r[id])
      bst=max(bst,ans[ii][v]);
     dfs(ii);
 }
}

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>r[i];

for (int i=1;i<=n;i++)
{
    order.push_back(make_pair(r[i],i));
}
sort(order.begin(),order.end());

for (int i=1;i<n;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);   
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  ans[i][j]=-1e9;

for (int i=1;i<=n;i++)
 ans[i][i]=1;

for (int i=0;i<order.size();i++)
{
 id=order[i].second;
 for (int q=0;q<g[id].size();q++)
 {
 
 for (int j=1;j<=n;j++)
  used[j]=0;
 used[id]=1;
 long t=g[id][q];
 bst=0;
 dfs(t);
 
 ans[t][id]=max(ans[t][id],bst+1);
 }
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  answ=max(answ,ans[i][j]);

cout<<answ<<endl;

cin.get();cin.get();
return 0;}