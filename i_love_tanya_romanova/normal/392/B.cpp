/*
Premeditation will kill the trust
They'll never know if you fear me
With every second collecting dust
I feel so bloated and weary
'cause she belongs to heaven

She's comin' over like a suicide
And it's the same old trip
The same old trip as before
Another complicating suicide
And it's the same old trip
The same old trip as before

Burn...

She'll cut you down with a single thrust
She's taken over too quickly
No medication can cure the lust
So say a prayer for the sickly
'cause she belongs to heaven

She's comin' over like a suicide
And it's the same old trip
The same old trip as before
Another complicating suicide
And it's the same old trip
The same old trip as before... as before...

You set me up to fucking fail this time [x8]

She's comin' over like a suicide
And it's the same old trip
The same old trip as before
Another overbearing suicide
And it's the same old trip
The same old trip
She's coming over wearing genocide
And it's the same old trip
The same old trip as before
Another complicating suicide
And it's the same old trip
The same old trip as before... as before...
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