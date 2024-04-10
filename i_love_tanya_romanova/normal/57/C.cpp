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
#define bs 1000000007
//#define szz 400
using namespace std;
long n,q,pr[300000],nm[400000],c[300000],e;
vector <long> p;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
q=n*2-1;
pr[1]=1;
for (int i=2;i<=200000;i++)
if (pr[i]==0)
for (int j=i*2;j<=200000;j+=i)
{pr[j]=1;
}

for (int i=2;i<=200000;i++)
{if (pr[i]==0)p.push_back(i);nm[i]=p.size()-1;}

for (int i=1;i<=n;i++)
{e=i;for (int j=0;j<p.size()&&e>=p[j];j++)
{//if (pr[e]!=1||p[j]!=e)
while (e%p[j]==0){c[j]--;e/=p[j];}
}
}
for (int i=q;i>=q-n+1;i--)
{e=i;for (int j=0;j<p.size()&&e>=p[j]
;j++)
{while (e%p[j]==0){c[j]++;e/=p[j];}
}
}
//for (int i=0;i<3;i++)
//cout<<c[i]<<endl;
long long answ=1;
for (int i=0;i<p.size();i++)
{for (int j=1;j<=c[i];j++)
 answ=answ*p[i]%bs;}
answ=answ+2*bs;
answ*=2;
answ-=n;
answ%=bs;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}