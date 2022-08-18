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
long n,m,cl[20000],fl;char ar[200][220];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
cl[0]=-1;
for (int i=1;i<=n;i++)
{for (int j=1;j<=m;j++)
{cin>>ar[i][j];
 if (j==1)cl[i]=ar[i][j];
 if (cl[i]==cl[i-1])fl++;
 if (ar[i][j]!=cl[i])fl++;}
}
if (fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;
}