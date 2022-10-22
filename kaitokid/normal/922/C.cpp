#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
ll ans=1; 
int main() 
{ ios::sync_with_stdio(0); 
ll x,y; 
cin>>x>>y; 
if(y>1000){cout<<"No";return 0;} 
for(ll i=2;i<=y;i++){ll t=__gcd(ans,i);
ans=(ans*i)/t;}
 x++; if(x%ans==0){cout<<"Yes";return 0;} cout<<"No"; return 0 ;}