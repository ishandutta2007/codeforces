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

void add(int &a,int &b)
{
    a+=b;
    if (a>=bs)
        a-=bs;
}

int dp[20][1000][1000];
int n,m;

string st;
char board[1000][1000];
int len;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=m;j++)
    {
        board[i][j]=st[j-1];
    }
}

len=n+m-1;
if (len%2==1)
{
    for (int i=1;i<=n;i++)
    {
        int j=len/2+2-i;
        if (j>=1&&j<=m)
            dp[1][i][i]=1;
    }
}
else
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (i+j-1==len/2)
            {
                if (j+1<=m&&board[i][j+1]==board[i][j])
                    dp[2][i][i]=1;
                if (i+1<=n&&board[i+1][j]==board[i][j])
                    dp[2][i][i+1]=1;
            }
        }
    }
}

int rl,L,R;
int tj1,tj2;

for (int span=1;span<=len;span++)
{
    if (span%2!=len%2)
        continue;
    
    rl=len-span;
    rl/=2;
    L=rl+2;
    R=n+m-rl;
        
    //cout<<L<<" "<<R<<endl;
    
    for (int j=0;j<=n;j++)
        for (int q=0;q<=n;q++)
            dp[(span+2)%8][j][q]=0;
        
    for (int lline=1;lline<=n;lline++)
        for (int rline=1;rline<=n;rline++)
        {
            if (dp[span%8][lline][rline]==0)
                continue;
            tj1=L-lline;
            tj2=R-rline;
            if (lline>1&&rline<n&&board[lline-1][tj1]==board[rline+1][tj2])
                add(dp[(span+2)%8][lline-1][rline+1],dp[span%8][lline][rline]);
            if (lline>1&&tj2<m&&board[lline-1][tj1]==board[rline][tj2+1])
                add(dp[(span+2)%8][lline-1][rline],dp[span%8][lline][rline]);
            if (tj1>1&&rline<n&&board[lline][tj1-1]==board[rline+1][tj2])
                add(dp[(span+2)%8][lline][rline+1],dp[span%8][lline][rline]);
            if (tj1>1&&tj2<m&&board[lline][tj1-1]==board[rline][tj2+1])
                add(dp[(span+2)%8][lline][rline],dp[span%8][lline][rline]);
        }
}

cout<<dp[len%8][1][n]<<endl;

//cin.get();cin.get();
return 0;}