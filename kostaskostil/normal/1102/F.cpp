#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
using namespace std;

int n, m;
vector<int> a[100];
int fl[100][100];
int mm[100][100];

int s;
int dp[20][100500];

int dfs(int i, int mask)
{
   // cout<<i<<" "<<mask<<"\n";
    if (dp[i][mask]!=-1)
        return dp[i][mask];
    if (mask+1 == (1<<n))
        return fl[s][i];
    int ans=0;
    for (int j=0; j<n; j++)
        if ((1&(mask>>j)) == 0)
            ans=max(ans, min(mm[i][j] ,dfs(j, mask+(1<<j))));
    return dp[i][mask]=ans;
}

main()
{
    cin>>n>>m;
    int x;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>x, a[i].push_back(x);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
    {
        int ans1=abs(a[i][0]-a[j][0]);
        int ans2=1e18;
        for (int k=1; k<m; k++)
        {
            ans1=min(ans1, abs(a[i][k]-a[j][k]));
            ans2=min(ans2, abs(a[i][k]-a[j][k-1]));
        }
        fl[i][j]=ans2;
        mm[i][j]=ans1;
    }


    int ans=0;
    for (s=0; s<n; s++)
    {
        memset(dp, -1, sizeof(dp));
        ans=max(ans, dfs(s, 1<<s));
    }
    cout<<ans<<"\n";
}