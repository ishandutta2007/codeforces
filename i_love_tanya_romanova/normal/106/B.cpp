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
long n,a[2000],b[2000],c[2000],d[2000],fl[2000],ansp,ansc;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
if (a[i]<a[j]&&b[i]<b[j]&&c[i]<c[j])fl[i]=1;
ansc=1000000;ansp=0;
for (int i=1;i<=n;i++) if (fl[i]==0&&d[i]<ansc)
{ansc=d[i];ansp=i;}
cout<<ansp<<endl;
cin.get();cin.get();
return 0;
}