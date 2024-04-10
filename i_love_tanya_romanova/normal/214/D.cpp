/*
I serve my perdition
In this private hell
A thousand angers
Have kept me alive
Carve a hole in your distorted soul
I'm here to bang it
Yea

The blessing is a curse
Seduction and thirst
Feeds the hunger
That's inside

Take a little caution
When you look my way
See the emptieness in my eyes
And the evil thing
That I bring
Soulless light
Yea

Warning is come upon your heels
Feel your dreams slip away
Take a little caution
In the dead of night
Let the darkness rise again

Want the needing
Want to feel you near

Want you
Need your
Life
Want you, need your
Life
Feed it to me

Yea
Blessing is a curse
Seduction and thrist
Feeds the hunger
That's inside

Take a little caution
When you look my way
See the emptieness in my eyes

Yea
Yea
Want the needing
Want to feel you near
Want your soul

Want your
Need your
Life
Want you, need your
Life, yea
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
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long c[200][200],dp[200][200],num[200],answ,n;

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=0;i<10;i++)
cin>>num[i];

c[0][0]=1;

for (int i=0;i<=100;i++)
for (int j=0;j<=i;j++)
if (j==0)c[i][j]=1;
else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;

for (int i=0;i<=n;i++)
{
 if (i<num[9])dp[i][9]=0; else dp[i][9]=1;
 
 for (int q=9;q>=1;q--)
 for (int j=num[q];j<=i;j++)
 dp[i][q]+=dp[i-j][q+1]*c[i][j]%bs;
 
 for (int j=num[0];j<=i;j++)
 dp[i][0]+=dp[i-j][1]*c[i-1][j]%bs;
 
 for (int j=0;j<=9;j++)
 dp[i][j]%=bs;   
}

//cout<<dp[1][7]<<endl;

answ=0;
for (int i=1;i<=n;i++)
answ+=dp[i][0]%bs;
cout<<answ%bs<<endl;

cin.get();cin.get();
return 0;}