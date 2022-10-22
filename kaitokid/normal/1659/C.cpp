#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pr[200009],suf[200009];
ll x[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)pr[i]=pr[i-1]+x[i];
        suf[n]=x[n];
        for(int i=n-1;i>0;i--)suf[i]=suf[i+1]+x[i];
        ll ans=b*pr[n];
        for(int i=1;i<n;i++)
        {
            ll tmp=(b+a)*x[i]+b*(suf[i+1]-(n-i)*x[i]);
            ans=min(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}