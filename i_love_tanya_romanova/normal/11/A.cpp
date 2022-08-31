#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long n,m,ar[20000],ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)cin>>ar[i];
for (int i=2;i<=n;i++)
{long q=ar[i-1]-ar[i]+1;
if (q<0)continue; 
else {long t=q/m+(q%m>0);ar[i]+=t*m;ans+=t;}}
cout<<ans<<endl;
cin.get();cin.get();
return 0;
}