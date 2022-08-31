/*
Two packs of cigarettes a day
The strongest whiskey Kentucky can make
That's a recipe to put a vagabond
On his hands and knees

I watched it all up close
I knew him more than most
I saw a side of him he never showed
Full of sympathy for a world that wouldn't let him be

That's the man he was
Have you heard enough?

What a shame, what a shame
To judge a life that you can't change
The choir sings, the church bells ring
So won't you give this man his wings?
What a shame to have to beg you to
See we're not all the same, what a shame

There's a hard life for every silver spoon
There's a touch of gray for every shade of blue
That's the way that I see life
If there was nothing wrong then there'd be nothing right

And for this working man
They say could barely stand
There's gotta be a better place to land
Some kind of remedy for a world that wouldn't let him be

That's the man he was
Have you heard enough?

What a shame, what a shame
To judge a life that you can't change
The choir sings, the church bells ring
So won't you give this man his wings?
What a shame to have to beg you to
See we're not all the same, what a shame

God forgive the hands that laid you down
They never knew how
But your broken heart can break the sound
And change the seasons

Now the leaves are falling faster
Happily ever after
You gave me hope through your endeavors
And now you will live forever

What a shame, what a shame
To judge a life that you can't change
The choir sings, the church bells ring
So won't you give this man his wings?
What a shame to have to beg you to
See we're not all the same, what a shame

What a shame, what a shame
'Cause we're not all the same
What a shame, what a shame
'Cause we're not all the same
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

using namespace std;

long long n[10];
vector<long long> g[10][2000];
long long a,b;
long long arp[200][2000];
long long subdist[200][2000];
long long dst[4][2000][2000];
long long tcost[2000];
long long tans;
long long ans;

void read()
{
 cin>>n[1]>>n[2]>>n[3];
 for (int i=1;i<=3;i++)
 {
  for (int j=1;j<n[i];j++)
  {
   cin>>a>>b;
   g[i][a].push_back(b);
   g[i][b].push_back(a);
  }
 }
}

void dfs(long tr,long v)
{
 for (int i=0;i<g[tr][v].size();i++)
 {
  long q=g[tr][v][i];
  if (arp[tr][q])continue;
  arp[tr][q]=arp[tr][v]+1;
  dfs(tr,q);
 }
}

void calcsubd()
{
 for (int i=1;i<=3;i++)
 {
  for (int tv=1;tv<=n[i];tv++)
   {for (int j=1;j<=n[i];j++)
     arp[i][j]=0;
     
     arp[i][tv]=1;
     dfs(i,tv);
    
    for (int j=1;j<=n[i];j++)
     subdist[i][tv]+=arp[i][j]-1;
    for (int j=1;j<=n[i];j++)
     dst[i][tv][j]=arp[i][j]-1;
    tcost[i]+=subdist[i][tv];
   }
 }
}

void solve(long ltree,long cntr, long rtree)
{
 long long bls,brs;
 bls=brs=0;
 for (int i=1;i<=n[ltree];i++)
  bls=max(bls,subdist[ltree][i]);
 for (int i=1;i<=n[rtree];i++)
  brs=max(brs,subdist[rtree][i]);
 tans=0;
 tans+=tcost[1]+tcost[2]+tcost[3];
 
 for (int i=1;i<=n[cntr];i++)
  for (int j=1;j<=n[cntr];j++)
  {
  long long qtans=tans;
   tans+=subdist[cntr][i]*n[ltree]+bls*n[cntr]+n[ltree]*n[cntr];
   tans+=subdist[cntr][j]*n[rtree]+brs*n[cntr]+n[rtree]*n[cntr];
   tans+=2*n[ltree]*n[rtree]+dst[cntr][i][j]*n[ltree]*n[rtree]+
   bls*n[rtree]+brs*n[ltree];
  ans=max(ans,tans);
  tans=qtans;
  }
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

read();
calcsubd();
ans=0;
 
 for (int i=1;i<=3;i++)
  tcost[i]/=2;
  
solve(1,2,3);
solve(1,3,2);
solve(2,1,3);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}