#include <bits/stdc++.h> 
using namespace std;
typedef long double ll;
int MOD=1e9 +7;
ll x,y,a,b;

long long ans,l,r;
set<ll> num;
int main() {
ios::sync_with_stdio(0);
cin>>x>>y>>l>>r;

a=1;
b=1;

while(a<=r)
{
b=1;
while(a+b<=r)
{
if(a+b>=l){
ll u=a+b;
num.insert(u);}



b*=y;


}

a*=x;


}
long long f=l-1;
for(set<ll>::iterator it=num.begin();it!=num.end();it++)
{

long long t=(*it);
long long d=t-f-1;
ans=max(ans,d);
f=t;

}

ans=max(ans,r-f);
cout << fixed << setprecision(0) << ans ;

 return 0; }