// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, dp[N];
vector < int > Adj[N];
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++)
            Adj[i].clear(), dp[i] = 0;
        for (int i = 1; i <= m; i ++)
        {
            int v, u;
            scanf("%d%d", &v, &u);
            Adj[v].push_back(u);
        }
        vector < int > vc;
        for (int i = 1; i <= n; i ++)
        {
            if (dp[i] == 2)
                dp[i] = -1, vc.push_back(i);
            for (int u : Adj[i])
                dp[u] = max(dp[u], dp[i] + 1);
        }
        printf("%d\n", (int)vc.size());
        for (int i : vc)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}