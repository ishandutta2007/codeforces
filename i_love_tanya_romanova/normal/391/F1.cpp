/*
Leave the lie, you find a way
And ask yourself why and give yourself a reason to stay
Leave the lie, have I beggin' in vain?
We're all left to fight with why, you're not the same

Left behind we are stranded not free
In silence I cry what went wrong was it me?
Led to believe in a truth that was false
Truth built on greed and the faith of the weak

Waking up blind and blind you must be
Stupid of me to believe in your hypocrisy
Gave it all up for the life in a dream
So foolish of me to not stop your infidelity

Unfaithful
Unfaithful
Unfaithful to life
Unfaithful to life

Left behind we are stranded not free
In silence I cry what went wrong was it me?
Led to believe in a truth that was false
Truth built on greed and the faith of the weak

Waking up blind and blind you must be
The stupid of me to believe in your hypocrisy
Gave it all up for the life in a dream
Foolish of me to not stop your infidelity

Unfaithful
Unfaithful
Unfaithful to life
Unfaithful to life
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

long long n,k,p,answ,dp[4100][2220][2];
long long c[20000];

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;

for (int i=0;i<=n;i++)
 for (int j=0;j<=k;j++)
  dp[i][j][0]=dp[i][j][1]=-1e18;

dp[0][0][0]=0;
for (int i=1;i<=n;i++)
{
 cin>>c[i];
}
for (int i=1;i<=n;i++)
 for (int j=0;j<=k;j++)
 {
  dp[i][j][1]=max(dp[i-1][j][1],dp[i][j][1]);
  dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]);
  dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][0]-c[i]);
  dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][1]+c[i]);
 }

answ=0;
for (int i=0;i<=k;i++)
answ=max(answ,max(dp[n][i][0],dp[n][i][1]));
cout<<answ<<endl;
 
cin.get();cin.get();
return 0;}