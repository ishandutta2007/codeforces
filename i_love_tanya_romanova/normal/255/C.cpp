/*
I thought I knew you but I was wrong
These waves of torment
Drowning me, for far too long
Inhibitions speak, it seems like now and forever

You don't, you don't have to break me
I swear next time, I'll let you know
You won't, you won't, you won't get to break me
I swear next time, I'm letting go

This fear and guilt, they've helped me down
Conscience breathing deeper, seeing light for the very first time
The tides, they turn and push me down, push me down
Confrontation speaks, seems like now, not forever
And in my mind, I'm gaining ground

You don't, you don't have to break me
I swear next time, I'll let you know
You won't, you won't, you won't get to break me
I swear next time, I'm letting go

This wasted time, my troubled mind
I'll let you know one last time
This wasted time, my troubled mind
I'll let you know one last time, one last time
One last time, one last time

This broken hold, my fragile soul
I'm letting go

For the last time, for the last time
For the last time, I'm letting go
For the last time, for the last time
For the last time, I'm letting go
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,ar[20000];
long dp[4500][4500];
long nxt[5000];
long pp,answ;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

if (n==1){cout<<1<<endl;return 0;}

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
 {
  if (ar[j]==ar[i]){nxt[i]=j;break;}
 }

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
  dp[i][j]=2;

for (int i=1;i<=n;i++)
{
 pp=nxt[i];
 for (int j=i+1;j<=n;j++)
 {
  if (pp<=j)pp=nxt[pp];
  if (pp==0)break;
  dp[j][pp]=max(dp[j][pp],dp[i][j]+1);
 }
}

answ=0;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  answ=max(answ,dp[i][j]);
 cout<<answ<<endl;
 
cin.get();cin.get();
return 0;}