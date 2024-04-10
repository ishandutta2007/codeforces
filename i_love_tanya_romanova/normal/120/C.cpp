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
#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long n,k,w,p,ans;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
cin>>n>>k;
for (int i=1;i<=n;i++)
{cin>>p; w=p/k;
 if (w<3)ans+=p%k; else ans+=p-3*k;}
cout<<ans<<endl;
cin.get();cin.get();
return 0;
}