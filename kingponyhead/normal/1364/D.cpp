// Screw this ..
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, q, m, k, M[N], H[N], B[N], P[N];
vector < int > Adj[N];
void DFS(int v)
{
    M[v] = 1;
    for (int u : Adj[v])
    {
        if (M[u] == 2 || u == P[v])
            continue;
        if (M[u] == 1)
        {
            if (!B[v] || H[B[v]] < H[u])
                B[v] = u;
            continue;
        }
        P[u] = v;
        H[u] = H[v] + 1;
        DFS(u);
    }
    M[v] = 2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    DFS(1);
    for (int i = 1; i <= n; i ++)
        if (B[i] && (H[i] - H[B[i]] + 1) <= k)
        {
            int v = i;
            printf("2\n%d\n", H[i] - H[B[i]] + 1);
            for (int j = 0; j < H[i] - H[B[i]] + 1; j ++)
                printf("%d ", v), v = P[v];
            printf("\n");
            return 0;
        }
    if (m >= n)
        for (int i = 1; i <= n; i ++)
            if (B[i])
            {
                printf("1\n");
                int v = i;
                for (int j = 0; j < (k + 1) / 2; j ++)
                    printf("%d ", v), v = P[P[v]];
                printf("\n");
                return 0;
            }
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (H[i] & 1)
            cnt ++;
    int w = 0;
    if (cnt >= (k + 1) / 2)
        w = 1;
    int j = (k + 1) / 2;
    printf("1\n");
    for (int i = 1; i <= n && j; i ++)
        if (H[i] % 2 == w)
            printf("%d ", i), j --;
    printf("\n");
    return 0;
}