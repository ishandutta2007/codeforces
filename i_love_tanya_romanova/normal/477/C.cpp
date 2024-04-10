/*
Young and dumb, truth and justice fantasy.
Fresh out of the academy.
Five time loser bust his head, make your day.
Unless you're paid off to look away.
Do you think this corruption will ever stop?
What makes a person wanna be a cop?
Ran a red light, storm the house and bust the guy.
Do you like to see his children cry?
Pick-up a hooker, take her for a little ride.
But get sucked off on the side.
Sworn to serve and protect, forget the killing,
Badge wearing fascist villain.
Pissed in the street, you bust the guy.
Do you like to see his children cry?

The badge means you suck, a child lays there dead.
As you look back, what goes through your head?

Some still call him pig.
Some still call him pig.

Young and tough, truth and justice fantasy.
Fresh out of the academy.
Five time loser, bust his head, make your day.
Unlesss you're paid off then you look away.
He burned a flag, storm the house and bust the guy.
Do you like to see his children cry?
Ran a red light, take her for a little ride,
But get sucked off on the side.

The badge means you suck, a child lays there dead.
As you look back, what goes through your head?

Talk to them, you can work it out.
You better not even try it.
You make a play for his gun.
They'll kill you: say it was a riot. Riot!!!

What's behind the badge?
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

string st;
string pat;
long bend[1<<12][1<<12];
long fen[1<<12];
long n,m;
long dp[1<<12][1<<12];
long span;
long ans[1<<12];

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/rai06.in","r",stdin);
//freopen("C:/rai06.out","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>pat;

n=st.size();
m=pat.size();

for (int i=0;i<=n;i++)
 for (int j=0;j<=m;j++)
  bend[i][j]=1e9;

for (int i=0;i<=n;i++)
 bend[i][m]=i-1;

for (int i=n-1;i+1;--i)
{
 for (int j=m-1;j+1;--j)
 {
  bend[i][j]=bend[i+1][j];
  if (st[i]==pat[j])
  bend[i][j]=min(bend[i][j],bend[i+1][j+1]);
 } 
}

for (int i=0;i<=n;i++)
{
 fen[i]=bend[i][0];
}
/*
for (int i=0;i<n;i++)
 cout<<fen[i]<<" ";
cout<<endl;
*/

for (int i=0;i<=n;i++)
 for (int j=0;j<=n;j++)
 {
  dp[i][j]=1e9;
 }

dp[0][0]=0;
for (int i=0;i<=n;i++)
{
 for (int j=0;j<=n;j++)
 {
  dp[i+1][j]=min(dp[i+1][j],dp[i][j]);// del char|sp
  if (fen[i]<=100000)
  {
   span=fen[i]-i+1;
   span-=pat.size();
   dp[fen[i]+1][j+1]=min(dp[fen[i]+1][j+1],dp[i][j]+span);
  }
 }
}
/*
for (int i=0;i<=n;i++)
{
 for (int j=0;j<=n;j++)
 cout<<dp[i][j]<<" ";
 cout<<endl;
}*/

for (int i=0;i<=n;i++)
if (dp[n][i]<1e8)
{
 for (int j=dp[n][i];j+i*pat.size()<=n;j++)
  ans[j]=i;
}

for (int i=0;i<=n;i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}

cout<<endl;
cin.get();cin.get();
return 0;}