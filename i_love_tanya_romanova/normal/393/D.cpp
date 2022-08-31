/*
The sun is gone and the flowers rot
Words are spaces between us
And I should've been drown in the rivers I've found of token lost
And I should've been down when you made me insecure

So break me down if it makes you feel right
And hate me now if it keeps you alright
You can break me down if it takes all your might
'cause I'm so much more than meets the eye

And I'm the one you can never trust
'cause wounds are ways to reveal us
And yeah I could have tried and devoted my life to both of us
But what a waste of my time when the world we have is yours

So break me down if it makes you feel right
And hate me now if it keeps you alright
You can break me down if it takes all your might
'cause I'm so much more than all your lies

Hate me, break me down
So break me down
So break me down
So break me down if it makes you feel right
And hate me now if it keeps you alright
You can break me down if it takes all your might
'cause I'm so much more than meets the eye
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

long long cost[200][200],dp[100][10][10],n,rem;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<3;i++)
 for (int j=0;j<3;j++)
  cin>>cost[i][j];

cin>>n;

for (int k=1;k<=n;k++)
for (int i=0;i<3;i++)
 for (int j=0;j<3;j++)
  if (i-j)
  {
   rem=(3^i^j);
   dp[k][i][j]=min(dp[k-1][i][rem]+cost[i][j]+dp[k-1][rem][j],
   dp[k-1][i][j]+cost[i][rem]+dp[k-1][j][i]+cost[rem][j]+dp[k-1][i][j]);
  }
 
cout<<dp[n][0][2]<<endl;

cin.get();cin.get();
return 0;}