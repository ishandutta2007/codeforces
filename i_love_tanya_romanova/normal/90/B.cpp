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
long n,m,arp[200][200],v[200][3000],g[200][300];
char ar[300][300];
string vv;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n>>m;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    cin>>ar[i][j];
}

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=m;j++)
 {
     v[i][ar[i][j]]++;
     g[j][ar[i][j]]++;
 }   
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (v[i][ar[i][j]]>1||g[j][ar[i][j]]>1)
arp[i][j]=1;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (arp[i][j]==0)vv.push_back(ar[i][j]);
cout<<vv<<endl;
cin.get();cin.get();
return 0;}