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
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,m;
string st;
char ar[200][200];

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
cin>>st;
for (int i=1;i<=n;i++)
ar[0][i]=st[i-1];

for (int i=1;i<=m;i++)
{for (int j=1;j<=n;j++)
 ar[i][j]=ar[i-1][j];
 for (int j=1;j<n;j++)
 if (ar[i-1][j]=='B'&&ar[i-1][j+1]=='G')swap(ar[i][j],ar[i][j+1]);
}
for (int i=1;i<=n;i++)
cout<<ar[m][i];
cout<<endl;

cin.get();cin.get();
return 0;}