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
#define EPS 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,ans[3000][3000],q,answ,a,b;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
cin>>n>>m;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
ans[i][j]=1000000;

cin>>q;

for (int i=1;i<=q;i++)
{cin>>a>>b;
 for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 ans[i][j]=min(ans[i][j],abs(i-a)+abs(j-b));
}

answ=0;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
answ=max(answ,ans[i][j]);

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (ans[i][j]==answ){a=i;b=j;}
cout<<a<<" "<<b<<endl;

cin.get();cin.get();
return 0;}