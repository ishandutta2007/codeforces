/*
Death to my vision
Blind I shall serve
Give rise to god war
Watch the civils fall

Hateful seed inside me
Scald my mind of all but truth
I concede; I am the chosen one
Open wide the gate
Stain the world with the blood of man

Affliction
Forced unto all
Human Vexation
Transcend with blood on my hands

Spirits of the grave remember
Rise up O powers from the land of Til
Plague and madness spread thru this world
Burn in me - I suffer your will
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long long c[1100][1100],dp[1100][1100][2][2],ans[1100],n,k;

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<=1000;i++)
for (int j=0;j<=i;j++)
if (i==j||j==0)c[i][j]=1;
else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;

cin>>n>>k;

dp[0][0][0][0]=1;
for (int i=0;i<n;i++)
for (int j=0;j<=n;j++)
for (int cur=0;cur<=1;cur++)
for (int next=0;next<=1;next++)
{
    dp[i+1][j][next][0]+=dp[i][j][cur][next];
    if (dp[i+1][j][next][0]>=bs)
    dp[i+1][j][next][0]-=bs;
    if (cur==0&&i>0)
    {
     dp[i+1][j+1][next][0]+=dp[i][j][cur][next];
     if (dp[i+1][j+1][next][0]>=bs)
     dp[i+1][j+1][next][0]-=bs;
    }
    if (i!=n-1)
    {
     dp[i+1][j+1][next][1]+=dp[i][j][cur][next];
     if (dp[i+1][j+1][next][1]>=bs)
     dp[i+1][j+1][next][1]-=bs;
    }
}

for (int i=0;i<=n;i++)
{
    ans[i]=dp[n][i][1][0]+dp[n][i][0][0];
    ans[i]%=bs;
    
    for (int j=1;j<=n-i;j++)
    ans[i]=ans[i]*j%bs;
    
}

for (int i=n;i+1;--i)
for (int j=i+1;j<=n;j++)
    {
     ans[i]-=(c[j][i]*ans[j])%bs;
     if (ans[i]<0)ans[i]+=bs;
    }
    
cout<<ans[k]%bs<<endl;

cin.get();cin.get();
return 0;}