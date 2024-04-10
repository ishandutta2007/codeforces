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
long long n,m,a[20000],b[200000],q,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>m>>n;
for (int i=1;i<=n;i++)cin>>a[i]>>b[i];
for (int i=1;i<=n;i++)
for (int j=i+1;j<=n;j++)
{if (b[j]>b[i]){swap(a[i],a[j]);swap(b[i],b[j]);}}
for (int i=1;i<=n;i++)
{q=min(m,a[i]);
 ans+=b[i]*q;m-=q;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}