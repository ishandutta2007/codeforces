/*
Do you believe what some might say
Can't be could be reality
Let seven be the one for me, six chapters
Of life laced with mystery

Awaiting discovery

Immune you become
A war to be won
The soul of a voice
Let the voice of the soul be free

For most it does not come easily
For some it comes with pain
From a thought to a living sight
For some it's a life, for some a game

There are things in life worth fighting for
And some things are better off, let go
A dream secured long ago or yesterday
Close to the top, there's no looking down

When you believe
When you believe
If you believe
You must believe

If I was paid for disappointments
I would be a wealthy man
The magic lives in sincerity, in truth
Behind the thoughts I choose to stand

Awaiting discovery

Immune you become
A war to be won
The soul of a voice
Let the voice of the soul be free

For most it does not come easily
For some it comes with pain
From a thought to a living sight
For some it's a life, for some a game

There are things in life worth fighting for
And some things are better off, let go
A dream secured long ago or yesterday
Close to the top, there's no looking down

When you believe
You must believe
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

long long fib[1000];
int tests;
int dig[1000];
long long dp[200][4][4];

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fib[1]=1;
fib[2]=2;
for (int i=3;i<=90;i++)
{
    fib[i]=fib[i-1]+fib[i-2];
}
/*
for (int i=1;i<=90;i++)
    cout<<i<<" "<<fib[i]<<" "<<log10(fib[i])<<endl;
*/  
cin>>tests;

for (;tests;--tests)
{
    long long n;
    cin>>n;
    for (int i=90;i;--i)
    {
        if (n>=fib[i])
        {
            dig[i]=1;
            n-=fib[i];
        }
        else
            dig[i]=0;
    }
    
    for (int i=90;i;--i)
        for (int a=0;a<=3;a++)
            for (int b=0;b<=3;b++)
                dp[i][a][b]=0;
    
    dp[89][dig[90]][dig[89]]=1;
    for (int i=89;i>1;--i)
    {
        for (int val1=0;val1<=3;val1++)
            for (int val2=0;val2<=3;val2++)
            {
                if (val1<=1)
                {
                    dp[i-1][val2][dig[i-1]]+=dp[i][val1][val2];
                }
                if (val1>=1&&val1<=2)
                    dp[i-1][val2+1][dig[i-1]+1]+=dp[i][val1][val2];
            }
    }
    long long ans=0;
    for (int i=0;i<=1;i++)
        for (int j=0;j<=1;j++)
            ans+=dp[1][i][j];
    cout<<ans<<endl;
}

//cin.get();cin.get();
return 0;}