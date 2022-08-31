/*
If you had the time to lose
An open mind and time to choose
Would you care to take a look
Or can you read me like a book?

Time is always on my side
Time is always on my side

Can I tempt you, come with me
Be Devil may care, fulfill your dream
If I said I'd take you there
Would you go, would you be scared?

Time is always on my side
Time is always on my side

Don't be afraid, you're safe with me
Safe as any soul can be honestly
Just let yourself go

Caught somewhere in time
Caught somewhere in time
Caught somewhere in time, ohh

Caught somewhere in time
Caught somewhere in time
Caught somewhere in time, ohh

Like a wolf in sheep's clothing
You try to hide your deepest sins
Of all the things that you've done wrong
And I know where you belong

Time is always on my side
Time is always on my side

Make you an offer you can't refuse
You've only got your soul to lose
Eternally let yourself go

Caught somewhere in time
Caught somewhere in time
Caught somewhere in time, ohh

Caught somewhere in time
Caught somewhere in time
Caught now in two minds, ohh
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
#define bsize 512

using namespace std;

long n,h,ar[1<<12];
long long dp[1<<12][1<<12];
long long ans;

void add(long long&a,long long b)
{
 a=a+b;
 a%=bs;
}

int main(){
//freopen("optimize.in","r",stdin);
//freopen("optimize.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>h;
for (int i=1;i<=n;i++)
 cin>>ar[i];

dp[0][0]=1;
for (int i=1;i<=n;i++)
{
    for(int j=0;j<=n;j++)
    {
     // opn&close
     if (j+ar[i]+1==h)add(dp[i][j],dp[i-1][j]);
     // close prev, opn new
     if (j+ar[i]+1==h)add(dp[i][j],dp[i-1][j]*j);
     // close prev, no opn
     if (j+ar[i]+1==h)add(dp[i][j],dp[i-1][j+1]*(j+1));
     // opn new
     if (j>0&&j+ar[i]==h)add(dp[i][j],dp[i-1][j-1]);
     // nothing
     if (j+ar[i]==h)add(dp[i][j],dp[i-1][j]);
    }
/*    for (int j=0;j<=n;j++)
     cout<<dp[i][j]<<" &";
     cout<<endl;*/
}

cout<<dp[n][0]<<endl;

cin.get();cin.get();
return 0;}