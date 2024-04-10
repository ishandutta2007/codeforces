#include <iostream>
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
using namespace std;
long long a,b,mod,q,p,ans,fl;
void showw(long long ans)
{vector <long> v;
for (int i=1;i<=9;i++){v.push_back(ans%10);ans/=10;}
for (int i=v.size()-1;i+1;--i)cout<<v[i];
cout<<endl;
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b>>mod;
q=10;
for (int i=1;i<=8;i++)q*=10;
ans=1000000001;

for (long long i=0;i<=min(a,3*mod);i++)
{p=i;
 p=p*q%mod;
// cout<<p<<" "<<b<<" "<<mod<<" "<<ans<<endl;
 fl=0;
 if (p==0)fl=1;
 if (mod-p<=b)fl=1;
if (fl==0)ans=min(ans,i);
}
//cout<<ans<<endl;
if (ans>1000000000)
{cout<<2<<endl;}
else {cout<<1<<" ";
showw(ans);}
cin.get();cin.get();
return 0;
}