/*
Never felt - alive for one day
Then you might know how it feels
Misty days-the sun never shines
For the ones who are too blind to see

The greatest gift
Is the power within
The river flows
Inside your veins

When everything falls apart
You're looking for something
There's no beginning there's no end
Find another dimension

Don't you wait for this moment to come
Your heart is solid like stone
Are you ready? Take the chance
Revolution in silence

The greatest gift
is the power within
The river flows
Inside your veins

When everything falls apart
You're looking for something
There's no beginning, there's no end
To Find another dimension

When everything falls apart
You're looking for something
There's no beginning there's no end
Find another dimension
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

long long n,k,d,dp[500][500];

void ad(long long &a,long long b)
{a+=b;
if (a>=bs)a-=bs;}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>d;
dp[0][0]=1;
for (int i=0;i<=100;i++)
 for (int j=1;j<=k;j++)
 for (int t=0;t<=1;t++)
 {
  ad(dp[i+j][t==1||j>=d],dp[i][t]);
 }
cout<<dp[n][1]<<endl;

cin.get();cin.get();
return 0;}