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
//#define bs 1000000007
//#define szz 400
using namespace std;
long long n,m,k,d[200000],s,r,c;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m>>k;
for (int i=1;i<=m;i++)
d[i]=1000000;
for (int i=1;i<=n;i++)
{
    cin>>r>>c;d[r]=min(d[r],c);
}

s=0;

for (int i=1;i<=m;i++)
{   
    s+=d[i];
}
s=min(s,k);
cout<<s<<endl;
cin.get();cin.get();
return 0;}