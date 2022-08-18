/*
Cast to the fire
Banned by the light
Worship and listen to me
Condemned in his mind
In his evil place
Your fate is all that you'll see

I am the one to show you the path
Salvation is in the fields
Listen up children, follow me
Or I'll let you pay the price of Malachi

Disciples of the watch
(Obey or I'll burn you to that cross)

Holding the mass
The demon is cast
To resurrect your soul
Calling to him is like an evil sin
A Prophet is what they're told

Taking the land under command
Killing friend or foe
Feel the might of his evil wrath
Desecrate your soul

Disciples of the watch
(Obey or I'll burn you to that cross)
Disciples of the watch
Disciples of the watch
(Watch)

Obey

Cast to the fire, banned by the light
Worship and listen to me
Condemned in his mind
In his evil place
Your fate is all that you'll see

I am the one to show you the path
Salvation is in the fields
Listen up children, follow me
Or I'll let you pay the price of Malachi

Disciples of the watch
(Obey or I'll burn you to that cross)
Disciples of the watch
Disciples of the watch
(Disciples of the watch)
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

long long c[200][200],dp[100][100][100],nop,ncl,ans,n,k;
long long sub2,temp;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

c[0][0]=1;
for (int i=1;i<=100;i++)
 for (int j=0;j<=i;j++)
 {
   if (j==i||j==0)c[i][j]=1;
   else c[i][j]=c[i-1][j-1]+c[i-1][j];
   c[i][j]%=bs;
 }
 
cin>>n>>k;
dp[1][0][0]=1;
for (int i=2;i<=n;i++)
{
 for (int sub1=1;sub1<i;sub1++)
 {
  sub2=i-sub1-1;
  for (int op1=0;op1<=n;op1++)
   for (int cl1=0;cl1<=n;cl1++)
   {
    if (dp[sub1][op1][cl1]==0)continue;
    for (int op2=0;op2<=n;op2++)
     for (int cl2=0;cl2<=n;cl2++)
     {
      if (dp[sub2][op2][cl2]==0)continue;
      nop=max(op1,cl1)+max(op2,cl2);
      ncl=max(op1+cl2,cl1+op2)+1;
      temp=1ll*dp[sub1][op1][cl1]*dp[sub2][op2][cl2]%bs;
      temp*=c[i-2][sub1-1]%bs;
      temp%=bs;
      temp*=sub1*sub2;
      dp[i][nop][ncl]+=temp;
      dp[i][nop][ncl]%=bs;
     }
   }
 }
 for (int op1=0;op1<=n;op1++)
  for (int cl1=0;cl1<=n;cl1++)
  {
   nop=cl1;
   ncl=op1+1;
   dp[i][nop][ncl]+=dp[i-1][op1][cl1]*(i-1);
   dp[i][nop][ncl]%=bs;
  }
}

ans=0;
for (int i=0;i<=k;i++)
 for (int j=0;j<=k;j++)
  if (i==k||j==k)ans=(ans+dp[n][i][j])%bs;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}