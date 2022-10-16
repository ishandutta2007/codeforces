#include <bits/stdc++.h>

#define DMAX 100009

using namespace std;

vector <pair<long long, long long> > v[DMAX];
long long ans, n, val[DMAX], dp[DMAX], p, c, use[DMAX];

void dfs(long long x)
{
    use[x]=1;
    ans++;
    for(long long i=0;i<v[x].size();i++)
    {
        if(use[v[x][i].first]) continue;
        if(dp[x]+v[x][i].second <= val[v[x][i].first])
        {
            dp[v[x][i].first]=max(dp[x]+v[x][i].second, 0LL);
            dfs(v[x][i].first);
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

cin>>n;

for(long long i=1;i<=n;i++)
    cin>>val[i];

for(long long i=2;i<=n;i++)
{
    cin>>p>>c;
    v[p].push_back({i, c});
    v[i].push_back({p, c});
}
if(val[1]<0)
{
    cout<<n<<'\n';
    return 0;
}
dp[1]=0;
dfs(1);

cout<<n-ans<<'\n';

    return 0;
}