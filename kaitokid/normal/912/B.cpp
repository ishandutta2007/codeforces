#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;

int main()
{
ios::sync_with_stdio(0);
ll n,k;
cin>>n>>k;
if(k==1){cout<<n;return 0;}
//long long x=floor(log(n)/log(2))+1;
ll ans=0,l=1;
//cout<<x<<" ";
ll x=0;

while(n!=0){x++;n/=2;}
for(int i=0;i<x;i++){ans+=l;l*=2;}
cout<<ans<<endl;




return 0;}