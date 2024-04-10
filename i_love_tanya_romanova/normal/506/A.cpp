/*
This decision will be your final breath

I tried to find a distraction to take my mind off how much I wanna find you
Reel you in with a face that you know, while I write this deception
I'd love to say it's only gonna equal that which you did to me
But the truth is my grudge has manifested
Turned into something I don't even recognize

But one thing I know is that when I find you it's gonna hurt, it's gonna hurt
But one thing I know is that when I find you it's gonna hurt, my god this will hurt

And all the people that you love are in as much trouble as you are

This is not a threat, this is not a threat
This is the one and only chance you will ever get
To make it up to me before I let it out
The demon called Revenge
My revenge

Wake up and smell the roses  they're on your grave
Use this hindsight to make peace with all the mistakes that you've made
Self-mutilation. You'd sever your arm to avoid a handshake
Well this is now, no turning 'round

I know the water that flows between our bridge is red
But this could be a cleansing or a drowning
Pretend to contemplate to feed your own denial
But make no mistake this next decision will be your final breath

This is not a threat, this is not a threat
This is the one and only chance you will ever get
To make it up to me before I let it out
The demon called Revenge
My revenge

But one thing I know is that when I find you it's gonna hurt, it's gonna hurt
But one thing I know is that when I find you it's gonna hurt, my god this will hurt

And all the people that you love are in as much trouble as you are

This is not a threat, this is not a threat
This is the one and only chance you will ever get
To make it up to me before I let it out
The demon called Revenge
My revenge
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