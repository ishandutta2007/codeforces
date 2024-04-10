/*
Welcome to an empty fortress
A mighty wreck that once was proud
Ate alive by oxidation
Abandoned by a crew of cowards
Navigation systems failed
Computers crashed and they all fall down

Possibly I've seen too much
Hangar 18 I know too much

All the guilty paid the price
Suspended by their broken necks
No one survived to tell the story
When foreign life forms resurrect
And military intelligence is
Still two words that can't make sense

Possibly I've seen too much
Hangar 18 I know too much
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long a[2000],b[2000],t1,t2,n,dp[2000][4][4];

int main(){
//freopen("unionday.in","r",stdin);
//freopen("unionday.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>a[i]>>b[i];

for (int i=0;i<=n;i++)
dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=10000000;
dp[0][0][0]=0;
for (int i=1;i<=n;i++)
 for(int l1=0;l1<=1;l1++)
  for (int l2=0;l2<=1;l2++)
  {
   t1=l1+a[i];
   t2=l2+b[i];
   t1%=2;
   t2%=2;
   dp[i][t1][t2]=min(dp[i][t1][t2],dp[i-1][l1][l2]);
   t1=l1+b[i];
   t2=l2+a[i];
   t1%=2;
   t2%=2;
   dp[i][t1][t2]=min(dp[i][t1][t2],dp[i-1][l1][l2]+1); 
  }
  if (dp[n][0][0]>n)cout<<-1<<endl;
  else cout<<dp[n][0][0]<<endl;
cin.get();cin.get();
return 0;}