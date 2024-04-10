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
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
long long n,m,t,ans,c[300][200];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m>>t;

for (int i=0;i<=60;i++)c[i][0]=1;

for (int i=1;i<=60;i++)
for (int j=1;j<=60;j++)c[i][j]=c[i-1][j-1]+c[i-1][j];

//cout<<c[6][3]<<endl;
for (int i=4;i<=t-1;i++)
if (t-i<=m)ans+=c[n][i]*c[m][t-i];
cout<<ans<<endl;
cin.get();cin.get();
return 0;}