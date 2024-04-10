#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const long long MOD=1000000007;

long long pow(long long a,long long b)
{
    long long c=1;
    while(b)
    {
        if(b%2)
            c=(c*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return c;
}

const int MAXN=200000;
vector<int>G[MAXN];
int n,m[MAXN];
long long dp[MAXN],black[MAXN];

void dfs(int v)
{
    if(G[v].size()==0)
    {
        if(m[v])
            black[v]=1;
        else
            dp[v]=1;
        return;
    }
    dp[v]=1;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        dfs(u);
        dp[v]=(dp[v]*(dp[u]+black[u]))%MOD;
    }
    if(m[v])
    {
        black[v]=dp[v];
        dp[v]=0;
        return;
    }
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        black[v]=(black[v]+black[u]*((dp[v]*pow(dp[u]+black[u],MOD-2))%MOD))%MOD;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int par;
        cin>>par;
        G[par].push_back(i);
    }
    for(int j=0;j<n;j++)
        cin>>m[j];
    dfs(0);
    cout<<black[0]<<endl;
}