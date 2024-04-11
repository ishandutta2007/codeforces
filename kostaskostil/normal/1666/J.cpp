#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=210;

int c[N][N];
int in[N][N];
int pref[N];
pair<int,int> dp[N][N];
int ans[N];

void dfs(int l,int r,int p)
{
    if(l>r)
        return;
    if(l==r)
    {
        ans[l]=p;
        return;
    }
    int m=dp[l][r].second;
    ans[m]=p;
    dfs(l,m-1,m);
    dfs(m+1,r,m);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>c[i][j];
    for(int l=1;l<=n;l++)
    {
        int cur=in[l][l]=0;
        for(int r=l+1;r<=n;r++)
        {
            for(int i=l;i<=r-1;i++)
                cur+=c[i][r];
            in[l][r]=cur;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            pref[i]+=c[i][j];
    for(int i=2;i<=n;i++)
        pref[i]+=pref[i-1];
    auto get=[](int l,int r)->int
    {
        if(l>r)
            return 0;
        return pref[r]-pref[l-1]-in[l][r]*2;
    };
    for(int len=2;len<=n;len++)
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            auto&res=dp[l][r]={1e18,-1};
            for(int m=l;m<=r;m++)
                res=min(res,{dp[l][m-1].first+dp[m+1][r].first+get(l,m-1)+get(m+1,r),m});
        }
    dfs(1,n,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}