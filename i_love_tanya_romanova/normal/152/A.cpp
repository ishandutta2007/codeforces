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
long n,m;char ar[200][200]; long fl[200],mx[200],ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    cin>>ar[i][j];
    mx[j]=max(mx[j],long(ar[i][j]));
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    if (ar[i][j]==mx[j])fl[i]=1;
}
for (int i=1;i<=n;i++)
if (fl[i])ans++;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}