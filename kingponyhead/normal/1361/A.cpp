// P-Pied!
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int n, m, q, A[N], P[N], M[N];
vector < int > Adj[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        cin >> v >> u;
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i ++)
        cin >> A[i];
    for (int i = 1; i <= n; i ++)
        for (int u : Adj[i])
            if (A[i] == A[u])
                return cout << "-1", 0;
    iota(P, P + n + 1, 0);
    sort(P + 1, P + n + 1, [&](int i, int j){return (A[i] < A[j]);});
    for (int i = 1; i <= n; i ++)
    {
        M[P[i]] = 1;
        set < int > ST;
        for (int u : Adj[P[i]])
            if (M[u]) ST.insert(A[u]);
        if (ST.size() != A[P[i]] - 1)
            return cout << "-1", 0;
    }
    for (int i = 1; i <= n; i ++)
        printf("%d ", P[i]);
    printf("\n");
    return 0;
}