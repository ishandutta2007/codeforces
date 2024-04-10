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
#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
#define j1 assdgsdgasghsf
#define MAXN 100000
#define tm sdfjahlfasfh
using namespace std;

long long ee,p1[200][200],p2[200][200],e,
n,sz[1000],m,k,c[200][200],ans[200][20000];

long long pw(long long a,long long b)
{
     if (b==0)return 1;
     if (b%2==1){return a*pw(a,b-1)%bs;}
     return pw(a*a%bs,b/2);
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

c[0][0]=1;
for (int i=1;i<=100;i++)
c[i][0]=1;
for (int i=1;i<=100;i++)
for (int j=1;j<=i;j++){
c[i][j]=c[i-1][j-1]+c[i-1][j];
c[i][j]%=bs;}


long a,b;
//while (cin>>a>>b){cout<<c[a][b]<<endl;}

cin>>n>>m>>k;

long long tsz=m/n+1;

for (int i=1;i<=n;i++)
{
    if (m%n>=i)sz[i]=m/n+1; else sz[i]=m/n;
}

//cout<<sz[1]<<endl;

for (int i=0;i<=100;i++)
for (int j=0;j<=i;j++)
{
    p1[i][j]=pw(c[i][j],tsz);
    p2[i][j]=pw(c[i][j],tsz-1);
}
/*
for (int i=1;i<=5;i++)
{
    for (int j=1;j<=5;j++)
    cout<<p1[i][j]<<" ";
    cout<<endl;
}*/

long long qq=m%n;

ans[0][0]=1;
for (int i=0;i<n;i++){
//cout<<i<<endl;
for (int j=0;j<=k;j++)
for (int e=0;e<=n;e++)
{ 
    if (i>=qq)ee=p2[n][e]; else ee=p1[n][e];
    //cout<<ee<<" "<<n<<" "<<e<<" "<<i<<endl;
    ans[i+1][j+e]+=ee*ans[i][j];
    ans[i+1][j+e]%=bs;
}
}
cout<<ans[n][k]<<endl;

cin.get();cin.get();
return 0;}