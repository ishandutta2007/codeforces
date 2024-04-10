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
#define bs 1000000007
//#define szz 400
using namespace std;
long long n,m,p,ans,e;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
if (m==1||n==1)ans=max(m,n);
else if (m==2||n==2)
{p=max(m,n);e=p/4;ans=4*e;p%=4;if (p<3)ans+=2*p; else ans+=4;
 }
else ans=(m*n+1)/2;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}