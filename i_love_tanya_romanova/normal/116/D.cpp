/*
Moving in and out of the shadows.
It's no easy mission,
Holding on to how I picture you.
Showing only bits and pieces,
Till the tide betrays you,
And your empty allocution.
Searching your eyes for a hint or a trace of humility.
Searching your eyes for the saint is an act of futility.
Searching your eyes for a hint or a trace of it.
Searching your eyes for humility.
Searching your eyes for a hint or a trace,
I'm still searching, searching.
Showing only bits and pieces,
Till the light betrays you,
And your empty allocution.
Rode the Piper by and down the river.
Carcass crippled underneath,
The pounding waves of adoration.
Pied Piper float on down the river.
Bloated carcass, crippled knee,
The weight of adoration.
Moving in and out of the shadows.
It's no easy mission,
Holding on to how I picture you.
*/

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