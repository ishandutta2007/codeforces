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
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
long n,q,p,l,m,r,b,a;
vector <long> v;
void tryadd(long q)
{if (a%q==0&&b%q==0)v.push_back(q);
}

long find(long a)
{long l,r;l=0;r=v.size()-1;
 while (l<r)
 {m=l+r;++m;m/=2;
  if (v[m]>a)r=m-1;else l=m;
       }
  return l;
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b;
for (int q=1;q*q<=a;q++)
{if (a%q==0)
{tryadd(q);tryadd(a/q);
}
}

v.push_back(0);
sort(v.begin(),v.end());

cin>>p;
for (int i=1;i<=p;i++)
{cin>>l>>r;
 long p=find(r);
 if (v[p]>=l)cout<<v[p]<<endl;else cout<<-1<<endl;
}
cin.get();cin.get();
return 0;}