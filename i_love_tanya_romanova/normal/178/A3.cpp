//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long n,q,ar[200000],ans[200000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];

for (int i=0;i<n-1;i++)
{
    q=1;while (i+q*2<n)q*=2;
    ar[i+q]+=ar[i];
    if (i)ans[i]=ans[i-1];ans[i]+=ar[i];
    ar[i]=0;
}
for (int i=0;i<n-1;i++)
cout<<ans[i]<<endl;
cin.get();cin.get();
return 0;}