/*
Survive

You cannot understand a single word I say
But you manage to hear every word anyway
Your eyes they always seem to be fixed on me
But not for love but for misery

You say nothing yet still I hear
I am the thing that you most fear
I cause the pain deep in your heart
Oh, how I love to tear your world apart
Well, I feel your pain and I survive
And I survive

I see your anger, I can hardly wait
How it feels so good to cause you such hate
Tried to ignore me, thought I'd go away
But I'm back for good, I'm here to stay

You say nothing yet still I hear
I am the thing that you most fear
I cause the pain deep in your heart
Oh, how I love to tear your world apart
Well, I feel your pain and I survive

You say nothing yet still I hear
I am the thing that you most fear
I cause the pain deep in your heart
Oh, how I love to tear your world apart
Well, I feel your pain and I survive
And I survive, survive

You thought that you could get the best of me
To put me down it seemed so easily
I take such pride in the work I do
You hoped I'd fail but I'm not like you

You say nothing yet still I hear
I am the thing that you most fear
I cause the pain deep in your heart
Oh, how I love to tear your world apart
Well, I feel your pain and I survive

I feel your pain so I survive
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
#define MAG 10000

using namespace std;

long n,m,ar[1<<11][1<<11];
string st;
long er;
long long ans;
long dp[1<<11][1<<11][3];
long mem[1<<11][1<<11];
long s1[1<<11][1<<11];
long s2[1<<11][1<<11];

void rotate()
{
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   mem[i][j]=ar[i][j];
 for (int i=1;i<=m;i++)
  for (int j=1;j<=n;j++)
   ar[i][j]=mem[n-j+1][i];
  swap(n,m);
}

void show()
{
 for (int i=1;i<=n;i++)
 {
  for (int j=1;j<=m;j++)
   cout<<ar[i][j];
  cout<<endl;
 }
}


int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
 {
  if (st[j-1]=='.')
   ar[i][j]=0;
  else ar[i][j]=1;
//  ar[i][j]=0;
 }
}

// line
for (int i=2;i<n;i++)
{
 er=0;
 for (int j=1;j<=m;j++)
  er+=ar[i][j];
 if (er==0)
  ans++;
}
for (int j=2;j<m;j++)
{
 er=0;
 for (int i=1;i<=n;i++)
  er+=ar[i][j];
 if (er==0)
  ans++;
}

//cout<<ans<<endl;
// single

for (int iter=1;iter<=4;iter++)
{

for (int i=1;i<=max(n,m)+1;i++)
{
 for (int j=1;j<=max(n,m)+1;j++)
  dp[i][j][0]=dp[i][j][1]=0;
}

for (int i=2;i<n;i++)
 dp[i][1][0]=1-ar[i][1];

for (int i=1;i<=n;i++)
{
    for (int j=2;j<=m;j++)
    {
//     cout<<i<<"   "<<j<<" "<<dp[i][j][0]<<" "<<ar[i][j]<<endl;
     if (ar[i][j])continue;
     dp[i][j][0]+=dp[i][j-1][0];
     dp[i][j][1]+=dp[i-1][j][1]+dp[i-1][j][0];
    }
}

/*
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
  cout<<dp[i][j][1]<<" ";
  cout<<endl;
}*/

for (int j=2;j<m;j++)
 ans+=dp[n][j][1];

rotate();
//show();
}

//cout<<ans<<endl;
// some shit

long long tans=0;

for (int iter=1;iter<=4;iter++)
{

for (int i=1;i<=max(n,m)+1;i++)
{
 for (int j=1;j<=max(n,m)+1;j++)
  dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=0;
}

for (int i=2;i<n;i++)
 dp[i][1][0]=1-ar[i][1];

for (int i=2;i<n;i++)
{
    for (int j=2;j<=m;j++)
    {
    // cout<<iter<<"  "<<i<<" "<<j<<" "<<ar[i][j]<<" "<<dp[i][j][0]<<endl;
     if (ar[i][j])continue;
     dp[i][j][0]+=dp[i][j-1][0];
     if (j<m)dp[i][j][1]+=dp[i-1][j][1]+dp[i-1][j][0];
     dp[i][j][2]+=dp[i][j-1][1]+dp[i][j-1][2];
    }
}
/*
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
  cout<<dp[i][j][1]<<" ";
  cout<<endl;
}*/
for (int i=2;i<n;i++)
 tans+=dp[i][m][2];

rotate();
//show();
}

ans+=tans/2;

tans=0;

for (int iter=1;iter<=4;iter++)
{

for (int i=1;i<=max(n,m)+1;i++)
{
 for (int j=1;j<=max(n,m)+1;j++)
  dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=0;
}

for (int i=2;i<n;i++)
 dp[i][1][0]=1-ar[i][1];

for (int j=2;j<=m;j++)

for (int i=n-1;i+1;i--)
{    {
    // cout<<iter<<"  "<<i<<" "<<j<<" "<<ar[i][j]<<" "<<dp[i][j][0]<<endl;
     if (ar[i][j])continue;
     dp[i][j][0]+=dp[i][j-1][0];
     if (j<m)dp[i][j][1]+=dp[i+1][j][1]+dp[i+1][j][0];
     dp[i][j][2]+=dp[i][j-1][1]+dp[i][j-1][2];
    }
}
/*
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
  cout<<dp[i][j][2]<<" ";
  cout<<endl;
}*/
for (int i=2;i<n;i++)
 tans+=dp[i][m][2];

rotate();
//show();
}
ans+=tans/2;

//cout<<ans<<endl;
//cout<<"%%"<<endl;
// pure shit

for (int iter=1;iter<=4;iter++)
{

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  s1[i][j]=s1[i-1][j]+ar[i][j];
  s2[i][j]=s2[i][j-1]+ar[i][j];
 }

for (int i=1;i<=max(n,m)+1;i++)
 for (int j=1;j<=max(n,m)+1;j++)
  dp[i][j][0]=dp[i][j][1]=0;
  
for (int i=2;i<n;i++)
 for (int j=2;j<m;j++)
 {
  if (s1[i][j]==0&&ar[i][j-1]==0)
   ans+=dp[i][j-2][1];
  /*if (s1[i][j]==0&&ar[i][j-1]==0)
   cout<<i<<"  "<<j<<" "<<dp[i][j-2][1]<<endl;
   */
  dp[i][j][1]=dp[i][j-1][1]+(s1[i][j]==0);
  if (ar[i][j])
   dp[i][j][1]=0; 
 }
 
rotate();
//show();
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}