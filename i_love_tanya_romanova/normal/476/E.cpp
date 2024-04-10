/*
Mid of july, the sumer breze
Carries scent of blood along
Those times we fear
To lose a dream, to lose a nation

Our strategy, a master plan
Slowly writing history
A genius trap coming their way
Fate will not let us down today

I don't defeat the enemy
I defend what i beleive is right
My role in this war is to bring
To my country a glory to taste

Tannenberg when they lost the game
Surrounding their men
We let them no chance
Tannenberg, luck was on our side
That they never changed their mind
Tannenberg, when i chose that name
I remember the knights
Who fell in the past
Shall this victory lighten their memory
Everywhere, all the same

Togeather as one, in the fronting line
Men are ready for the fight
I know they fear
To lose a dream, to lose their reason

Falling around, one by one
Victims of fate will soon abound
But rules are clear as they see
They can only survive by killing

They don't defeat the enemy
They obey orders we have given
You soldiers of fortune know
We owe you the glory we taste

Here i stand
Watching the line
There they stand, togeather
Fall with pride 
On both sides
Men are a band of brothers

But counting thje dead is somehow
Changing the glory to waste

Tannenberg , if i had done wrong
I wouldn't live to long... a regret so strong
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