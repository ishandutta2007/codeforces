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
//#define pb push_back
using namespace std;
long long n,m,k,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m>>k;
if (k==1||k>n)
{ans=1;for (int i=1;i<=n;i++)
{ans=ans*m%bs;
 }
 cout<<ans<<endl;
}
else
if (k==n)
{ans=1;for (int i=1;i*2<=n+1;i++)
{ans=ans*m%bs;}
cout<<ans<<endl;
}
else
if (k%2==1)
{if (n==1)ans=m; else ans=m*m;
cout<<ans<<endl;
           }
else cout<<m<<endl;
cin.get();cin.get();
return 0;}