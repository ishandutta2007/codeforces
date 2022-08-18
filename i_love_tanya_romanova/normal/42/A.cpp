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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
double V,l,a[200000],b[20000],r,m,s;
long fl,n;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>V;
for (int i=1;i<=n;i++)cin>>a[i];
for (int i=1;i<=n;i++)cin>>b[i];
l=0;
r=1000000;
while (r-l>eps)
{
      m=l+r;m/=2;s=0;fl=0;
      for (int i=1;i<=n;i++)
      {
          if (m*a[i]>b[i])fl=1;
          s+=m*a[i];
      }
if (s>V||fl==1)r=m; else l=m;
//cout<<l<<" "<<r<<endl;
}
cout.precision(3);
cout<<fixed<<s<<endl;
cin.get();cin.get();
return 0;}