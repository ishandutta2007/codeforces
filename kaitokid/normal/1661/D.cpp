#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[600009],pr[300009],n,k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


        cin>>n>>k;
        ll x;
        for(int i=1;i<=n;i++)cin>>a[i];
        ll p=0,s=0,ans=0;
        for(ll i=n;i>=1;i--)
        {

            s-=p;
            p-=pr[i];
            a[i]-=s;
            if(a[i]<=0)continue;
            ll v=min(i,k);
            ll u=(a[i]+v-1)/v;
            ans+=u;
            pr[max(0LL,i-k)]+=u;
            p+=u;
            s+=u*v;

        }


cout<<ans;


    return 0;
}