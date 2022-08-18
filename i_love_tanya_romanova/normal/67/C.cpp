/*
Mama, I wanna grow up to be a drunk
Sit around, watch TV and pick my feet
I wanna be pissed off and jealous of any
Whos successful and complain that I cant keep a job!
Im not human, not human, Im special
Im not human, not human, so special

I wanna be white trash
Sit around on my fat ass
So many hours in the day
To piss my life away
I wanna be white trash
Sit around on my fat ass
So many hours in the day
To piss my life away

My sister, shes got 3 babies
But she dont remember who their daddy is
She was on Girls Gone Wild showin her stuff
Now shes a porn star, were so proud of her
Shes not human, not human, shes special
Shes not human, not human, so special

I wanna be white trash
Sit around on my fat ass
So many hours in the day
To piss my life away
I wanna be white trash
Sit around on my fat ass
So many hours in the day
To piss my life away

I wanna be white trash
Sit around on my fat ass
So many hours in the day
To piss my life away
I wanna be white trash
Sit around on my fat ass
So many hours in the day
To piss my life away

What that, youre looking for a donation?
Save the whales, feed the children?
Feed the children to the whales
Im savin up for a big screen TV!
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int ti,td,tr,te,n,m;
string A,B;
int p1[5000][28],p2[5000][28];
int dp[4050][4050];

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

int prev;

cin>>ti>>td>>tr>>te;

cin>>A>>B;
n=A.size();
m=B.size();

for (int j=0;j<26;j++)
{
    prev=-1;
    for (int i=0;i<n;i++)
    {
        if (A[i]==j+'a')
            prev=i; 
        p1[i][j]=prev;
    }
}
for (int j=0;j<26;j++)
{
    prev=-1;
    for (int i=0;i<m;i++)
    {
        if (B[i]==j+'a')
            prev=i;
        p2[i][j]=prev;
    }
}

for (int i=0;i<=n;i++)
    for (int j=0;j<=m;j++)
        dp[i][j]=1e9;

for (int i=0;i<=n;i++)
    dp[i][0]=td*i;
for (int i=0;i<=m;i++)
    dp[0][i]=ti*i;

for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
        dp[i][j]=min(dp[i][j],dp[i-1][j]+td);//del
        dp[i][j]=min(dp[i][j],dp[i][j-1]+ti);//ins
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(A[i-1]==B[j-1]?0:tr));//repl
        if (A[i-1]!=B[j-1]) // del, swap to place both, ins
        {
            int prev1=p1[i-1][B[j-1]-'a'];
            int prev2=p2[j-1][A[i-1]-'a'];
            if (prev1>-1&&prev2>-1)
            {
                dp[i][j]=min(dp[i][j],td*(i-prev1-2)+te+ti*(j-prev2-2)+dp[prev1][prev2]);
            }
        }
    }

cout<<dp[n][m]<<endl;

//cin.get();cin.get();
return 0;}