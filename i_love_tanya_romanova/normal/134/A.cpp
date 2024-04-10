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
//#define bs 1000000007
//#define szz 400
using namespace std;
long long n,fl,ar[300000],ans,s;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];
 s+=ar[i];
}
for (int i=1;i<=n;i++)
{if (ar[i]*n==s)ans++;
}
cout<<ans<<endl;
for (int i=1;i<=n;i++)
{if (ar[i]*(n-1)==s-ar[i])
{if (fl)cout<<" ";fl=1;cout<<i;}}
cout<<endl;
cin.get();cin.get();
return 0;}