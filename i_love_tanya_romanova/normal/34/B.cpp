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
long n,m,ar[200000],ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=0;i<n;i++)cin>>ar[i];
sort(ar,ar+n);
for (int i=0;i<m;i++)if (ar[i]<0)ans+=ar[i];
ans=0-ans;
cout<<ans<<endl;
cin.get();cin.get();
return 0;
}