/*
A longing sense...
To fulfil my days of empty slumber.
The remnants of life,
Like ashes, scattered across the ground.
It all seems worthless...

From the window pane,
I gaze upon the autumn tress.
Raining leaves and gnarling mists,
Like my very essence, grey...
Travelling through nothingness.

My life is fucking empty.
To exist in fragile light...

Silence...
Cold...
Alone...

Death, with no redemption,
We're all heading towards the end.
It is with us, from the dawn,
The dawn of our miserable lives.

We all live in a delusion,
As life holds nothing but death...
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

long long dp[3][676][754],cur,nk,pw[633];
long long n,k,nxt,ans;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
pw[0]=1;
for (int i=1;i<=500;i++)
 pw[i]=pw[i-1]*2%bs;

cur=1;
dp[1][0][0]=1;
for(int i=1;i<=n;i++)
{
 nxt=1-cur;
 for (int j=0;j<=k;j++)
  for (int q=0;q<=i;q++)
   dp[nxt][j][q]=0;
   
 for (int j=0;j<=k;j++)
 {
  for (int lst=0;lst<i;lst++)
  {
   dp[nxt][j+1][i]+=(1ll*(pw[i-lst]-1)*pw[lst]%bs)*dp[cur][j][lst];
   dp[nxt][j+1][i]%=bs;
   dp[nxt][j][lst]+=1ll*dp[cur][j][lst]*pw[lst];
   dp[nxt][j][lst]%=bs;
  }
 }
 cur=nxt;
}

ans=0;
for (int lst=0;lst<=n;lst++)
 ans+=dp[cur][k][lst];
cout<<ans%bs<<endl;

cin.get();cin.get();
return 0;}