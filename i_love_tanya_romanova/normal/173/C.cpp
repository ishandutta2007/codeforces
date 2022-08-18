#pragma comment(linker, "/STACK:214777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long n,m; long ar[1200][1200]; long long
ts[1200][1200],p,ans,s[1200][1200][3],tss,tss1;

long long gs(long long x1,long long y1, long long x2,long long y2)
{
 return ts[x2][y2]-ts[x2][y1-1]-ts[x1-1][y2]+ts[x1-1][y1-1];     
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{{
  scanf("%d",&ar[i][j]);
// cout<<-1<<" ";
}
//cout<<endl;
}
/*
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)cout<<ar[i][j]<<" ";
    cout<<endl;}
*/
ans=-1000000;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
ts[i][j]=ts[i-1][j]+ts[i][j-1]-ts[i-1][j-1]+ar[i][j];

//cout<<gs(1,2,3,4)<<endl;
p=min(n,m);

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{//ans=max(ans,1ll*ar[i][j]);
s[i][j][0]=ar[i][j];
}

for (int k=3;k<=p;k+=2)
{
 for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  tss=gs(i,j,i+k-1,j+k-1);
  tss1=gs(i+1,j+1,i+k-2,j+k-2);
  
  s[i][j][k/2%2]=tss1-s[i+1][j+1][(k/2-1)%2]+tss-tss1-ar[i+1][j];    
  if (i+k<=n+1&&j+k<=m+1)ans=max(ans,s[i][j][k/2%2]);
 // cout<<i<<" "<<j<<" "<<k<<" "<<s[i][j][k/2%2]<<endl;
 }   
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}