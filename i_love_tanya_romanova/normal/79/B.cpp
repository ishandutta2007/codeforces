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
vector <string> ans;
long x[2000],y[2000],n,m,k,t,p,a[20000],b[20000];
long issone(long g,long h)
{for (int i=1;i<=k;i++)
if (a[i]==g&&b[i]==h)return 1;
return 0;
}

long gettnm(long g,long h)
{return g*m-m+h;
}

long gettbd(long g, long h)
{long ans=0;for (int i=1;i<=k;i++)
 {
     if (gettnm(a[i],b[i])<gettnm(g,h))ans++;
 }
 return ans;
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m>>k>>t;
for (int i=1;i<=k;i++)
{cin>>a[i]>>b[i];}

for (int i=1;i<=t;i++)
{cin>>x[i]>>y[i];
 if (issone(x[i],y[i]))ans.push_back("Waste");
 else
 {
     p=gettnm(x[i],y[i])-gettbd(x[i],y[i]);
    // cout<<p<<endl;
     if (p%3==0)ans.push_back("Grapes");
     else if (p%3==2)ans.push_back("Kiwis");
     else ans.push_back("Carrots");}
 }
for (int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;
cin.get();cin.get();
return 0;}