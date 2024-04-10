/*
K.D. Vinit  /,,/
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 5000;

int lc[N], rc[N], sz[N];
int a[N], dp[N][N];
int n, m;

void maxa(int& x1, int& x2)
{
    if(x1<x2) x1=x2;
}

void DFS(int chi)
{
    sz[chi]=1;
    int l = lc[chi], r = rc[chi];

    if(l!=-1)
    {
        DFS(l);
        int mn1 = min(sz[chi], m);
        int mn2 = min(sz[l], m);

        for(int i=mn1; i>=0; i--)
        {
            for(int j=0; j<=mn2; j++)
            {
                int x = dp[chi][i] + dp[l][j] + (a[l]-a[chi])*j*(m-j);
                maxa(dp[chi][i+j], x);
            }
        }

        sz[chi]+=sz[l];
    }

    if(r!=-1)
    {
        DFS(r);
        int mn1 = min(sz[chi], m);
        int mn2 = min(sz[r], m);

        for(int i=mn1; i>=0; i--)
        {
            for(int j=0; j<=mn2; j++)
            {
                int x = dp[chi][i] + dp[r][j] + (a[r]-a[chi])*j*(m-j);
                maxa(dp[chi][i+j], x);
            }
        }

        sz[chi]+=sz[r];
    }
}

int build_tree(int l, int r)
{
    if(l==r) return l;
    if(l>r) return -1;

    int mni=l;
    for(int i=l; i<=r; i++) if(a[i]<a[mni]) mni=i;

    lc[mni] = build_tree(l, mni-1);
    rc[mni] = build_tree(mni+1, r);

    return mni;
}

void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++) { lc[i]=-1; rc[i]=-1; }
    for(int i=1; i<=n; i++) cin>>a[i];

    int root = build_tree(1, n);
    memset(dp, 0, sizeof(dp));
    DFS(root);

    int ans = dp[root][m];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}