#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
ll n,k,a,b,ans;
int main() 
{ 
ios::sync_with_stdio(0);
cin>>n>>k>>a>>b;
if(k==1){cout<<(n-1)*a;return 0;}
while(n!=1)
{
if(n<k){ans+=(n-1)*a;break;}
ans+=(n%k)*a;
n-=(n%k);
ll r=n/k;
ans+=min(b,a*(n-r));
n/=k;



}
cout<<ans;
return 0 ;}