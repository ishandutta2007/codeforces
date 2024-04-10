#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>ed[200009];
int dp[200009],in[200009],out[200009];
int go(int x)
{
    if(dp[x]!=0)return dp[x];
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(in[u]==1)continue;
        dp[x]=max(dp[x],go(u));
    }
    dp[x]++;
    return dp[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        out[x]++;
        in[y]++;
        ed[x].push_back(y);

    }
    for(int i=1;i<=n;i++)
        if(out[i]<=1)dp[i]=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    ans=max(ans,go(i));
    cout<<ans;
    return 0;
}