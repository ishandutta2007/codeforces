#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,ll> >dp[200009];
int s[200009];
vector<int>ch[200009];
ll cl(int x,int y)
{
    for(int i=0;i<dp[x].size();i++)
        if(dp[x][i].first==y)return dp[x][i].second;
    return -1;
}
ll go(int x,int y)
{
    if(y==0)return 0;
    ll u=cl(x,y);
    if(u!=-1)return u;
    ll res=y*1LL*s[x];
    if(ch[x].empty())
    {
        dp[x].push_back({y,res});
        return res;
    }
    int g=ch[x].size();
    ll f=y/g;
    ll ff=(y+g-1)/g;
    vector<ll>rr;
    for(int i=0;i<g;i++)
    {
        ll h=go(ch[x][i],f);
        res+=h;
        ll d=go(ch[x][i],ff)-h;
        rr.push_back(d);
    }
    sort(rr.begin(),rr.end());
    int z=y%g;
    for(int i=g-z;i<g;i++)
        res+=rr[i];
    dp[x].push_back({y,res});
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=n;i++)
        {
            dp[i].clear();
            ch[i].clear();
        }
        for(int i=2;i<=n;i++)
        {
            int x;
            cin>>x;
            ch[x].push_back(i);
        }
        for(int i=1;i<=n;i++)cin>>s[i];
        ll ans=go(1,k);
        cout<<ans<<endl;
    }
    return 0;
}