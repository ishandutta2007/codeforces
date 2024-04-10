#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <fstream>
#include <map>
#include <queue>
#include <algorithm>
#define y1 sgjkdf
using namespace std;
long n,m,ps,qx,l[20000],r[20000],ans;
string st;
int main(){
   // freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
cin>>n>>m;
qx=1;

for (long i=1;i<=n;i++)
{l[i]=1000;r[i]=0;}

for (long i=1;i<=n;i++)
{cin>>st;
for (long j=0;j<m;j++)
 {if (st[j]=='W'){
     l[i]=min(l[i],j+1);
     r[i]=max(r[i],j+1);
 }
}}

ps=n;
while (r[ps]==0&&ps>1)--ps;
ans=ps-1;
/*for (int i=1;i<=n;i++)
{cout<<l[i]<<" "<<r[i]<<endl;
}*/
//cout<<ans<<endl;
for (int i=1;i<=ps;i++)
{

if (i%2==0)if (r[i]!=0)
{if (qx>r[i])ans+=qx-l[i];
 else ans+=r[i]-qx+r[i]-l[i];
 qx=l[i];
}

if (i%2==1)if (l[i]!=1000)
{if (qx<l[i])ans+=r[i]-qx;
 else ans+=qx-l[i]+r[i]-l[i];
 qx=r[i];
}
//cout<<ans<<" "<<qx<<endl;
}
cout<<ans<<endl;
cin.get();cin.get();cin.get();
return 0;
}