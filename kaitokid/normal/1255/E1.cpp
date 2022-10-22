#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,u;
vector<ll>pr,a;
ll go(ll x)
{
    ll res=0;
    for(int i=0;i<u;i+=x)
    {
ll mid=a[(2*i+x-1)/2];

    for(int j=i;j<i+x;j++)
        res+=abs(a[j]-mid);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
cin>>n;
    ll x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==1)a.push_back(i);
    }
     u=a.size();
    if(u==1){cout<<-1;return 0;}
    for(int i=2;i<=u;i++)
    {
        if(u<2)break;
        if(u%i==0)pr.push_back(i);
    while(u%i==0)u/=i;
    }
    u=a.size();
    ll ans=1e18;
    ll s=pr.size();
    for(int i=0;i<s;i++)
    {
        ans=min(ans,go(pr[i]));
    }
    cout<<ans;
    return 0;
}