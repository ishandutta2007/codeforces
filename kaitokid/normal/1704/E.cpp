#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll a[1009],b[1009];
vector<int>v[1009],h[1009];
ll dp[1009];
ll go(ll x)
{
    if(dp[x]!=-1)return dp[x];
    dp[x]=(a[x]%mod);
    for(int i=0;i<h[x].size();i++)
        {dp[x]+=go(h[x][i]);dp[x]%=mod;}
    return dp[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){v[i].clear();h[i].clear();dp[i]=-1;}
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            h[y].push_back(x);
        }
        int ans=0;
        for(int qq=0;qq<1009;qq++)
        {
            ll p=0;
            for(int i=1;i<=n;i++){b[i]=a[i];p=max(p,a[i]);}
            if(p==0)break;
            ans++;
            for(int i=1;i<=n;i++)
            {
                if(b[i]==0)continue;
                a[i]--;
                for(int j=0;j<v[i].size();j++)a[v[i][j]]++;
            }
        }
        int d=-1;
        for(int i=1;i<=n;i++)if(v[i].empty())d=i;
        ans+=go(d);
        ans%=mod;
        cout<<ans<<endl;
    }

    return 0;

}