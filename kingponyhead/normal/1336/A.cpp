// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 19, Mod = 1e9 + 7;
int n, m, q, k, A[N], SZ[N];
vector < int > Adj[N];
void DFS(int v, int p, int h = 0)
{
    SZ[v] = 1;
    for (int u : Adj[v])
        if (u != p)
            DFS(u, v, h + 1), SZ[v] += SZ[u];
    A[v] = h - SZ[v] + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i ++)
    {
        int v, u;
        cin >> v >> u;
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    DFS(1, 0);
    sort(A + 1, A + n + 1);
    reverse(A + 1, A + n + 1);
    long long SM = 0;
    for (int i = 1; i <= k; i ++)
        SM += A[i];
    printf("%lld\n", SM);
    return 0;
}