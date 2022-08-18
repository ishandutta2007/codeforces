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
#define bs 1000000007
using namespace std;
long n,m,ans;
char ar[200][200];
int main(){
//freopen("intput.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)cin>>ar[i][j];
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (ar[i][j]=='W')
if (ar[i-1][j]=='P'||ar[i+1][j]=='P'||ar[i][j-1]=='P'||ar[i][j+1]=='P')ans++;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}