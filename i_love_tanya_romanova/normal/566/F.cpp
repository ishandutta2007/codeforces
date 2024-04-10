/*
On the endless path of war
We may be torn and beat
But we have sworn to stand as one
In victory or defeat

We are the immortals
From Hell we rise
We are the immortals
Death Metal - No compromise!

Others follow the winds of change
You came to swear allegiance
No conformity at all
We didn't come to reason

We are the immortals
From Hell we rise
We are the immortals
Death Metal - No compromise!
We are the immortals
From Hell we rise
We are the immortals
Death Metal - No compromise!
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
#define bsize 512

using namespace std;

int n,q,have[1<<20],dp[1<<20];

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    have[q]=1;
    dp[q]=1;
}

for (int i=1;i<=1000000;i++)
    if (have[i])
        for (int j=i*2;j<=1000000;j+=i)
            if (have[j])
                dp[j]=max(dp[j],dp[i]+1);

int ans=0;
for (int i=1;i<=1000000;i++)
    if (have[i])
        ans=max(ans,dp[i]);
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}