/*
Taught and raised the ways of the new world
Right from wrong - It's only influential
Generations pass - Provides no balance
Safety in numbers - Not afraid of the challenge
Face the change in everyday life
Evolution for all to be insane
Timeless wave it programs my soul
Beyond circumstances and despair
The chain of life to be insane
Revolves around my ways
The wrong and right in black and white
Useless lives will fade away
Reanimated yet segregated
Only to break the night by the day
The chain of life to be insane
Revolves around around my ways
Safety in numbers
Face the change in everyday life
Evolution for all to be insane
Timeless wave it programs my soul
Beyond circumstances and despair
The chain of life to be insane
Revolves around around my ways
Taught and raised the ways of the new world
Right from wrong - It's only influential
Generations pass - Provides no balance
Safety in numbers - Not afraid of the challenge
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

int ans;
int n,m,board[505][505];
int valid[505][505][11][17];
int s[505][505];
string st;

bool check(int a,int b,int mask,int lev)
{
    if (a>n||b>m)return true;
    if (mask>=0)
        return !valid[a][b][lev][mask];
    int sum=s[a+(1<<lev)-1][b+(1<<lev)-1]-s[a-1][b+(1<<lev)-1]-s[a+(1<<lev)-1][b-1]+s[a-1][b-1];
    return (sum!=(1<<(lev+lev)));
}

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
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
        board[i][j]=(st[j-1]=='*');     
    }
}

for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
        for (int mask=0;mask<16;mask++)
        {
            valid[i][j][0][mask]=(board[i][j]==0);
//          if (mask==0)
//              valid[i][j][0][mask]=(board[i][j]==1);
        }

for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+board[i][j];

for (int lev=1;lev<=10;lev++)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int mask=0;mask<16;mask++)
            {
                int er=0;
                if (mask&1)
                    er|=check(i,j,mask,lev-1);
                    else
                    er|=check(i,j,-1,lev-1);
                if (mask&2)
                    er|=check(i,j+(1<<lev)/2,mask,lev-1);
                    else
                    er|=check(i,j+(1<<lev)/2,-1,lev-1);
                if (mask&4)
                    er|=check(i+(1<<lev)/2,j,mask,lev-1);
                    else
                    er|=check(i+(1<<lev)/2,j,-1,lev-1);
                if (mask&8)
                    er|=check(i+(1<<lev)/2,j+(1<<lev)/2,mask,lev-1);
                    else
                    er|=check(i+(1<<lev)/2,j+(1<<lev)/2,-1,lev-1);
                if (er==0)
                    {
                    //cout<<i<<" "<<j<<" "<<mask<<" "<<lev<<endl;
                    valid[i][j][lev][mask]=1;
                    if (lev>1)++ans;
                    }
            }
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}