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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long a,b,n,hh,diff,ts[10000],h[1000],ans[300][110000][2],answ;

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
cin>>a>>b;
for (int i=1;i<=n;i++)
cin>>h[i];


for (int i=0;i<=n;i++)
for (int j=0;j<=100000;j++)
ans[i][j][0]=ans[i][j][1]=1000000000;


ans[0][0][0]=ans[0][0][1]=0;

for (int i=1;i<=n;i++)
ts[i]=ts[i-1]+h[i];

for (int i=0;i<=n;i++)
for (int j=0;j<=a;j++)
{
    diff=min(h[i],h[i+1]);
    hh=h[i+1];
    ans[i+1][j+hh][0]=min(ans[i+1][j+hh][0],ans[i][j][1]+diff);
    ans[i+1][j+hh][0]=min(ans[i+1][j+hh][0],ans[i][j][0]);

    ans[i+1][j][1]=min(ans[i+1][j][1],ans[i][j][1]);
    ans[i+1][j][1]=min(ans[i+1][j][1],ans[i][j][0]+diff);
  //  cout<<ans[i][j][0]<<" "<<ans[i][j][1]<<" "<<i<<" "<<j<<endl;
}

answ=1000000000;


for (int i=0;i<=a;i++)
{if (ts[n]-i<=b){answ=min(answ,ans[n][i][1]);
 answ=min(answ,ans[n][i][0]);
}}
if (answ>=100000000)answ=-1;

cout<<answ<<endl;
cin.get();cin.get();
return 0;}