#include <iostream>
//#include <fstream>
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
#define szz 400
using namespace std;
long long n,q,ar[200],ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++){cin>>q;ar[10+q]++;}
for (int j=-10;j<=10;++j)
{if (j==0)ans+=ar[j+10]*(ar[j+10]-1);
 else ans+=ar[j+10]*ar[-j+10];
}
cout<<ans/2<<endl;
cin.get();cin.get();
return 0;}