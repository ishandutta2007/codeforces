/*
How can you act like you know
When all you know is to lie?
Another truth to expose,
Freedom will capture their eyes.
We find this truth
We fight. You lose.

Your times up now.
Thats enough now.
Shut up, get out!
Truth called you out.

I know this language of yours -
I used to speak it so well.
A fire meant to be pure
Is now the fire of Hell.
It is written
Long before you.

Your times up now.
Thats enough now.
Shut up, get out!
Truth called you out.

I hear your claims,
And I know your name;
I hear your claims,
And I know your name:

Liar.
Liar.

Your times up now.
Thats enough now.
Shut up, get out!
Truth called you out.

Your times up now.
Thats enough now.
Shut up, get out!
Truth called you out.
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

long r,g,dp[3][300000];
long tans,ans;
long ttl;

void add(long &a,long &b)
{
     a+=b;
     if (a>=bs)a-=bs; 
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>r>>g;

dp[0][0]=1;

for (int i=1;i<=1000;i++)
{
 ttl+=i;
 for (int j=0;j<=r;j++)
 {
  dp[i%2][j]=0;
 }
 for (int j=0;j<=r;j++)
 {
  if (ttl-j<=g)
   add(dp[i%2][j],dp[1-i%2][j]);// g
  if (j>=i)
   add(dp[i%2][j],dp[1-i%2][j-i]);// r
 }
 tans=0;
 for (int j=0;j<=r;j++)
  add(tans,dp[i%2][j]);
 if (tans>0)ans=tans;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}