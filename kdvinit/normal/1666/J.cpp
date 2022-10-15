/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 200+10;
int c[N][N];
int dp[N][N];
int root[N][N];
int sum[N][N];
int par[N];

int calc(int l, int r)
{
    if(dp[l][r]!=-1) return dp[l][r];

    dp[l][r]=1e18;

    for(int k=l; k<=r; k++)
    {
        int tmp = calc(l, k-1) + calc(k+1, r);
        tmp += (sum[l][k-1] + sum[k+1][r]);

        if(tmp<dp[l][r])
        {
            dp[l][r]=tmp;
            root[l][r]=k;
        }
    }

    return dp[l][r];
}

void ap(int l, int r)
{
    if(l>=r) return;

    int rt = root[l][r];
    int cl = root[l][rt-1];
    int cr = root[rt+1][r];

    if(cl!=-1) { par[cl]=rt; ap(l, rt-1); }
    if(cr!=-1) { par[cr]=rt; ap(rt+1, r); }
}

void solve()
{
    int n;
    cin>>n;

    int c[n+1][n+1];
    int pre[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        pre[i][0]=0;
        for(int j=1; j<=n; j++)
        {
            cin>>c[i][j];
            pre[i][j]=pre[i][j-1]+c[i][j];
        }
    }

    for(int i=0; i<=n+1; i++)
    {
        par[i]=0;
        dp[i][i]=0;
        root[i][i]=i;
        for(int j=0; j<=n+1; j++)
        {
            sum[i][j]=0;
            dp[i][j]=-1;
            root[i][j]=-1;
            if(i>j) dp[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            for(int k=i; k<=j; k++)
            {
                int cur = (pre[k][n] - pre[k][j]) + pre[k][i-1];
                sum[i][j] += cur;
            }
        }
    }

    calc(1, n);
    ap(1, n);

    for(int i=1; i<=n; i++) cout<<par[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}