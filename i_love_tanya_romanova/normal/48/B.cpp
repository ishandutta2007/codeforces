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
#define INF 1000000000
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
long n,m,ans,x,y,s[200][200],ar[200][200];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{cin>>ar[i][j];s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+ar[i][j];}

cin>>x>>y;
ans=1000000;

for (int i=x;i<=n;i++)
for (int j=y;j<=m;j++)
ans=min(ans,s[i][j]-s[i-x][j]-s[i][j-y]+s[i-x][j-y]);
swap(x,y);
for (int i=x;i<=n;i++)
for (int j=y;j<=m;j++)
ans=min(ans,s[i][j]-s[i-x][j]-s[i][j-y]+s[i-x][j-y]);
cout<<ans<<endl;
cin.get();cin.get();
return 0;}