#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
vector<int>ed[200009];
ll v[200009],dp[200009],ans,sz[200009];
int n;
void rem(int x,int y)
{
    dp[x]+=dp[y];
    dp[x]-=(sz[y]*v[x])%mod;
    dp[x]=(dp[x]+mod)%mod;
    sz[x]-=sz[y];
}
void add(int x,int y)
{
    dp[x]-=dp[y];
    dp[x]=(dp[x]+mod)%mod;
    dp[x]+=(v[x]*sz[y])%mod;
    dp[x]%=mod;
    sz[x]+=sz[y];
}
void fuck(int x,int p)
{
    ans=(ans+dp[x])%mod;
    for(int i=0;i<ed[x].size();i++)
    {
        ll u=ed[x][i];
        if(u==p)continue;
        rem(x,u);
        add(u,x);
        fuck(u,x);
        rem(u,x);
        add(x,u);
    }
}

void go(int x,int p)
{
    sz[x]=1;
    dp[x]=v[x];
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)
            {go(ed[x][i],x);
        add(x,ed[x][i]);}

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){cin>>v[i];v[i]=(v[i]+mod)%mod;}
    memset(dp,-1,sizeof dp);
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    go(1,0);
    fuck(1,0);
    cout<<ans;
    return 0;
}