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
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 100000000
//#define szz 400
using namespace std;
long n1,n2,k1,k2,q,ans[240][200][3];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n1>>n2>>k1>>k2;
ans[0][0][1]=ans[0][0][2]=1;
for (int i=0;i<n1+n2;i++)
for (int j=0;j<=n1;j++)
{
    ans[i][j][1]%=bs;ans[i][j][2]%=bs;
    for (q=1;q<=n1+n2;++q)
    {
        if (q<=k1&&q<=n1-j)ans[i+q][j+q][2]+=ans[i][j][1];
        if (q<=k2&&q<=n2-i+j)ans[i+q][j][1]+=ans[i][j][2];
        }
}
cout<<(ans[n1+n2][n1][1]+ans[n1+n2][n1][2])%bs<<endl;

cin.get();cin.get();
return 0;}