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
#define eps 1e-8
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,l,k,tp[200000];
long ps;
double answ,ans[220][220][410],p[20000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>l>>k;
for(int i=1;i<=n;i++)
{cin>>p[i];
           }
for (int i=1;i<=n;i++)
{
    cin>>tp[i];
}
ans[0][0][n]=1;

for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
for (int v=0;v<=n*2;v++)
{
    ps=v+tp[i+1];if (ps>n+n)ps=n+n;
    if (ps>=0)
    ans[i+1][j+1][ps]+=ans[i][j][v]*(p[i+1]*0.01);
    ans[i+1][j][v]+=ans[i][j][v]*(1-p[i+1]*(0.01));  
}

for (int i=l;i<=n;i++)
for (int j=n-k;j<=n+n;j++)if (j>=0)
answ+=ans[n][i][j];

cout.precision(8);

cout<<fixed<<answ<<endl;
//cout<<ans[n][0][n]<<endl;
cin.get();cin.get();
return 0;}