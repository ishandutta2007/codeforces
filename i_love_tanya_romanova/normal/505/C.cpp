/*
Told you can never be free
Whoever told you can't seek out that dream
Whoever told you can never be free
Whoever told you that is your enemy you see

My life is mine, my right is mine
'Cause it's my life, you see, not your life
My life is mine, my right is mine
Sometimes you have to lose your mind

No hope, no fear

I won't wait for the next life
The time is now, the time is right
Follow my heart, I'll get through
If you're not now you never were

So lose yourself to find yourself
Don't need to act like nobody else
Sometimes it feels as if the road is blocked
I'll find a way, I'll move those rocks

No hope, no fear

Freedom
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,d,cost[1<<20],q,dp[30100][1050];
long actual;
long ans;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);


cin>>n>>d;
for (int i=1;i<=n;i++)
{
 cin>>q;
 cost[q]++;
}

for (int i=0;i<=30000;i++)
 for (int j=0;j<=1005;j++)
  dp[i][j]=-1000000000;

dp[d][500]=cost[d];

for (int i=d;i<=30000;i++)
{
 for (int last=1;last<=1000;last++)
 {
  ans=max(ans,dp[i][last]);
  actual=d+(last-500);
  if (actual>1&&i+actual-1<=30000)
   dp[i+actual-1][last-1]=max(dp[i+actual-1][last-1],dp[i][last]+cost[i+actual-1]);
  if (actual>0&&i+actual<=30000)
   dp[i+actual][last]=max(dp[i+actual][last],dp[i][last]+cost[i+actual]);
  if (actual>0&&i+actual+1<=30000)
   dp[i+actual+1][last+1]=max(dp[i+actual+1][last],dp[i][last]+cost[i+actual+1]);
 }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}