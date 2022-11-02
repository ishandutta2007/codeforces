#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<long double, long double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
const int mxN=320;
const int MOD=998244353;
const ll INF=1e18;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, -1, -1, -1, 0, 1, 1, 1};
int N, M;
ll A[mxN][mxN], pre[mxN][mxN], p2[mxN][mxN];
pll dp[mxN][mxN];
int par[mxN];
ll sum(int a, int b, int c, int d)
{
    if(a>b || c>d)  return 0;
    return pre[b][d]-pre[a-1][d]-pre[b][c-1]+pre[a-1][c-1];
}
void dping(int s, int e)
{
    if(dp[s][e].fir!=-1)    return;
    if(s==e)
    {
        dp[s][e].fir=0, dp[s][e].sec=e;
        return;
    }
    for(int i=s;i<=e;i++)
    {
        if(i>s) dping(s, i-1);
        if(i<e) dping(i+1, e);
    }
    dp[s][e].fir=dp[s+1][e].fir+sum(s+1, e, 1, s)+sum(s+1, e, e+1, N), dp[s][e].sec=s;
    if(dp[s][e].fir>dp[s][e-1].fir+sum(s, e-1, 1, s-1)+sum(s, e-1, e, N))
    {
        dp[s][e].fir=dp[s][e-1].fir+sum(s, e-1, 1, s-1)+sum(s, e-1, e, N);
        dp[s][e].sec=e;
    }
    for(int i=s+1;i<e;i++)
    {
        if(dp[s][e].fir>dp[s][i-1].fir+dp[i+1][e].fir+sum(s, i-1, 1, s-1)+sum(s, i-1, i, N)+sum(i+1, e, 1, i)+sum(i+1, e, e+1, N))
        {
            dp[s][e].fir=dp[s][i-1].fir+dp[i+1][e].fir+sum(s, i-1, 1, s-1)+sum(s, i-1, i, N)+sum(i+1, e, 1, i)+sum(i+1, e, e+1, N);
            dp[s][e].sec=i;
        }
    }
    return;
}
void dfs(int s, int e, int up)
{
    par[dp[s][e].sec]=up;
    if(dp[s][e].sec!=s) dfs(s, dp[s][e].sec-1, dp[s][e].sec);
    if(dp[s][e].sec!=e) dfs(dp[s][e].sec+1, e, dp[s][e].sec);
}
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)    for(int j=1;j<=N;j++)    cin >> A[i][j];
    for(int i=1;i<=N;i++)    for(int j=1;j<=N;j++)    pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+A[i][j];
    for(int i=1;i<=N;i++)    for(int j=1;j<=N;j++)    dp[i][j].fir=-1;
    dping(1, N);
    dfs(1, N, 0);
    for(int i=1;i<=N;i++)   cout << par[i] << " ";
}