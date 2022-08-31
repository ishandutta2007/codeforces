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
#define eps 1e-6 
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long n,a,b,c,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>a>>b>>c;
ans=0;

for (int i=0;i<=4000;i++)
for (int j=0;j<=4000;j++)
{
    if (n>=i*a+j*b&&((n-i*a-j*b)%c==0))
    {
     ans=max(ans,i+j+(n-i*a-j*b)/c);
     }

}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}