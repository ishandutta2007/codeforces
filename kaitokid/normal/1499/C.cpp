#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mn[2],sum[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n>>mn[0]>>mn[1];
        sum[0]=mn[0],sum[1]=mn[1];
    ll ans=n*mn[0]+n*mn[1];
    for(int i=2;i<n;i++)
    {
        ll x;
        cin>>x;
        sum[i%2]+=x;
        mn[i%2]=min(mn[i%2],x);
        ll res=sum[0]+sum[1]+(n-i/2-1)*mn[0]+(n-(i+1)/2)*mn[1];
        ans=min(ans,res);
    }
    cout<<ans<<endl;
    }
    return 0;
}