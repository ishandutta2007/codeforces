#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll g(ll x,ll y)
{
    if(y>x)return 0;
    ll ans=1;
    for(ll i=x;i>x-y;i--)ans=(ans*i)%mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);

    int n,x,p,ls=0,gr=0;
cin>>n>>x>>p;
int l=0,r=n;
while(l<r)
{
    int mid=(l+r)/2;
    if(mid<=p){ls++;l=mid+1;}
    else {gr++;r=mid;}
}
//cout<<ls<<" "<<gr<<endl;
ls--;
ll ans=(g(n-x,gr)*g(x-1,ls))%mod;
n-=ls+gr+1;
ans=(ans*g(n,n))%mod;
cout<<ans;
return 0;
}