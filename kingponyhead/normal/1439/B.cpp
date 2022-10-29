#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 77;
int n, m, k, M[N], D[N];
vector < int > Adj[N];
set < pair < int , int > > S;
bool Edge(int a, int b)
{
    if (Adj[a].size() < Adj[b].size())
        swap(a, b);
    int lb = lower_bound(Adj[b].begin(), Adj[b].end(), a) - Adj[b].begin();
    if (lb < (int)Adj[b].size() && Adj[b][lb] == a)
        return 1;
    return 0;
}
void Test()
{
    S.clear();
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++)
        Adj[i].clear(), D[i] = M[i] = 0;
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        scanf("%d%d" ,&v, &u);
        Adj[v].push_back(u);
        Adj[u].push_back(v);
        D[v] ++; D[u] ++;
    }
    if (k * (k - 1) / 2 > m)
    {
        printf("-1\n");
        return ;
    }
    for (int i = 1; i <= n; i ++)
        sort(Adj[i].begin(), Adj[i].end());
    for (int i = 1; i <= n; i ++)
        S.insert({D[i], i});
    while ((int)S.size() && S.begin()->first < k - 1)
    {
        int v = S.begin()->second;
        S.erase(S.begin());
        M[v] = 1;
        for (int u : Adj[v])
            if (!M[u])
            {
                S.erase({D[u], u});
                D[u] --;
                S.insert({D[u], u});
            }
    }
    while ((int)S.size() && S.begin()->first <= k - 1)
    {
        int v = S.begin()->second;
        int d = S.begin()->first;
        S.erase(S.begin());
        if (d == k - 1)
        {
            assert(d == k - 1);
            vector < int > V;
            for (int u : Adj[v])
                if (!M[u])
                    V.push_back(u);
            assert(V.size() == d);
            bool fail = 0;
            for (int i = 0; i < d; i ++)
            {
                for (int j = i + 1; j < d; j ++)
                    if (!Edge(V[i], V[j]))
                    {
                        fail = 1;
                        break;
                    }
                if (fail)
                    break;
            }
            if (!fail)
            {
                printf("2\n");
                for (int i : V)
                    printf("%d ", i);
                printf("%d\n", v);
                return ;
            }
        }
        M[v] = 1;
        for (int u : Adj[v])
            if (!M[u])
            {
                S.erase({D[u], u});
                D[u] --;
                S.insert({D[u], u});
            }
        continue;
    }

    if (S.size())
    {
        printf("1 %d\n", (int)S.size());
        for (auto i : S)
            printf("%d ", i.second);
        printf("\n");
        return ;
    }
    printf("-1\n");
    return ;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T --)
        Test();
    return 0;
}