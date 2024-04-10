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
#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long n,m,minx,maxx,miny,maxy;
char ar[250][250];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
minx=10000;
miny=10000;
for (long i=1;i<=n;i++)
for (long j=1;j<=m;j++)
{cin>>ar[i][j];if (ar[i][j]=='*')
{minx=min(minx,i);
 miny=min(miny,j);
 maxx=max(maxx,i);
 maxy=max(maxy,j);}}

for (int i=minx;i<=maxx;i++)
{for (int j=miny;j<=maxy;j++)
 cout<<ar[i][j];cout<<endl;
}
cin.get();cin.get();
return 0;
}