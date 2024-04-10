/*
Besiege me not for what I am
a man with intent in the Devil's den
for I know not what to believe
yet mad I am not in trust I deceive
Radical alterations in my temper
grows worse day by day
I will offer you extreme opposition

Savage curtain closes in on you
but I do grieve the evident
behind this illusion

The fury of demons possessing me
my fiendish corruption will fill my need
every reason to fulfill my deed.
Have we not a perpetual inclination
to violate that witch is law merely
because we know it is to be?

Savage curtain closes in on you
but I do grieve the evident
behind this illusion

Savage curtain closes in on you
but I do grieve the evident
behind this illusion
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

int n,m;
string st;
int dp[200][200];
int s[200][200];
int board[200][200];
int have[200][200];
int found,ans;
int ai,aj;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
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
        if (st[j-1]=='B')
            board[i][j]=1;
            else board[i][j]=-1;
    }
}

while (true)
{
    found=0;
    ai=aj=0;
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
        if (board[i][j]!=have[i][j])
            found=1,
            ai=i,
            aj=j;
    if (found==0)break;
    int change=board[ai][aj]-have[ai][aj];
    for (int i=1;i<=ai;i++)
        for (int j=1;j<=aj;j++)
            have[i][j]+=change;
    ++ans;
}

cout<<ans<<endl;
//cin.get();cin.get();
return 0;}