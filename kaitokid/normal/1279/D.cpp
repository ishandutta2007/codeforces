#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=998244353;
ll num[2000009],a[2000009],b[2000009];
ll n,x,k,ans;
ll pw(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2)return (a*pw(a,b-1))%mod;
    ll q=pw(a,b/2);
    return (q*q)%mod;
}
ll g(ll a,ll b)
{
    return ((a%mod)*pw(b%mod,mod-2))%mod;
}
int main()
{
   ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>k;
    for(int j=0;j<k;j++)
    {
        cin>>x;
        num[x]++;
        a[x]+=g(1,n*k);
        a[x]%=mod;

    }

}
for(int i=1;i<1000001;i++){ans+=(a[i]*g(num[i],n))%mod;ans%=mod;}
cout<<ans;
    return 0;
}