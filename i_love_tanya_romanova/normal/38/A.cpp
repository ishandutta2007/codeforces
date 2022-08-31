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
long n,l,r,ans,ar[20000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=2;i<=n;i++)cin>>ar[i];
cin>>l>>r;
for (int i=l+1;i<=r;i++)ans+=ar[i];
cout<<ans<<endl;
cin.get();cin.get();
return 0;
}