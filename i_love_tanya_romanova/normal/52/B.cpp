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
long long n,m,ans,s1[200000],s2[20000];
char ar[2000][2000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n>>m;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    cin>>ar[i][j];
    if (ar[i][j]=='*')s1[i]++;
    if (ar[i][j]=='*')s2[j]++;
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
    if (ar[i][j]=='*')
    {
       ans+=(s1[i]-1)*(s2[j]-1);
    }
                      
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}