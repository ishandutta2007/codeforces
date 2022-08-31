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
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long long n,l,a,q,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;l=0;a=-13;
for (int i=1;i<=n;i++)
{cin>>q;if (q!=a){ans+=l*(l+1)/2;l=1;a=q;}else ++l;}
ans+=l*(l+1)/2;cout<<ans<<endl;
cin.get();cin.get();
return 0;
}