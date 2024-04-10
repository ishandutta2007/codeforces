#include <iostream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
long a,b,q,r,i,fl,ans;
long gcd(long a,long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;}

int main()
{cin>>a>>b;
q=gcd(a,b);
a/=q;b/=q;
if (a>b){swap(a,b);fl=1;}
long r=0;
for (int i=1;i<=b;i++)
{r+=a;if (r<b&&i>1)ans=1;if (r>b)r-=b;}
if (ans==0)cout<<"Equal"<<endl;
else {if (fl)cout<<"Masha"<<endl; else cout<<"Dasha"<<endl;}

cin.get();cin.get();
return 0;
}