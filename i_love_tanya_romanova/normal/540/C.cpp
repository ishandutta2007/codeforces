/*
Arisen in vain to a life,
Bleeding inner to suffer with time.
Endlessly lost and still searching
For something, someday.

Obsession & deceit
To burn a mark for a lifetime.
Boundaries to brake,
Reached from the edge of time.
To rebuild the past
For something that will everlast.
Just searching for to find itself
In still-motion.

For to hope,
Whenever to find a closure,
Find itself in still-motion..

Get closer,
Closer to your own faith.

Serve the frail mind,
Escape through the lifetime
To glance for your dismal youth.

Get closer,
Closer to your own faith.
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,ar[1000][1000];
string st;
long x1,y1,x2,y2;

bool found;
long used[1000][1000];

bool can(long a,long b)
{
     return (a>=1&&a<=n&&b>=1&&b<=m);
}
long tr;

long gnei(long a,long b)
{
    long res=0;
    if (can(a-1,b)==1&&ar[a-1][b]==0)++res;
    if (can(a+1,b)==1&&ar[a+1][b]==0)++res;
    if (can(a,b-1)==1&&ar[a][b-1]==0)++res;
    if (can(a,b+1)==1&&ar[a][b+1]==0)++res;
    return res;
}
void dfs(long a,long b)
{
    //cout<<a<<" "<<b<<endl;
    used[a][b]=1;
    if (a==x2&&b==y2)
    {found =1;return ;}
    if (ar[a][b]==1&&(a!=x1||b!=y1)) return ;   
    if (can(a-1,b)==1&&used[a-1][b]==0)
     dfs(a-1,b);
    if (can(a+1,b)==1&&used[a+1][b]==0)
     dfs(a+1,b);
    if (can(a,b-1)==1&&used[a][b-1]==0)
     dfs(a,b-1);
    if (can(a,b+1)==1&&used[a][b+1]==0)
     dfs(a,b+1);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=m;j++)
    {
        if (st[j-1]=='X')
         ar[i][j]=1;
        else ar[i][j]=0;
    }
}

cin>>x1>>y1;
cin>>x2>>y2;

if (n*m==1)
{
    cout<<"NO"<<endl;
    return 0;
}

dfs(x1,y1);

if (found==0)
{
    cout<<"NO"<<endl;
    return 0;
}

ar[x1][y1]=0;
int tt=gnei(x2,y2);

if (x1==x2&&y1==y2)
 tr=1;
else if (ar[x2][y2]==1)
 tr=0;
else tr=2;
if (tt>=tr)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}