#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()
#define int long long

template<class T> struct sparse_min{
    vector<vector<T> > sp;
    vector<int> H;
    T get(int l, int r)
    {
        int h = H[r - l + 1];
        return min(sp[h][l], sp[h][r - (1 << h) + 1]);
    }
    sparse_min(vector<T> a)
    {
        int n = a.size();
        H = vector<int>(n + 1);
        for (int i = 3; i < n + 1; i++)
        {
            H[i] = H[i - 1] + (((i - 1) & (i - 2)) == 0);
        }
        int s = 0;
        while ((1 << s) < n) s++;
        sp = vector<vector<T>>(s, vector<T>(n));
        for (int i = 0; i < n; i++)
        {
            sp[0][i] = a[i];
        }
        for (int j = 1; j < s; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                sp[j][i] = get(i, i + (1 << j) - 1);
            }
        }
    }
};

int n, q;
vector<int> graph[500000];
int dist[500000];
int L[500000], R[500000];
int tm;
vector<pair<int, int> > V;

void dfs(int v, int p, int d)
{
    L[v] = tm;
    R[v] = tm;
    dist[v] = d;
    V.push_back({dist[v], v});
    tm++;
    for (auto u : graph[v])
    {
        if (u != p)
        {
            dfs(u, v, d + 1);
            R[v] = tm;
            V.push_back({dist[v], v});
            tm++;
        }
    }
}

int LCA(int v, int u, sparse_min<pair<int, int> > &tlca)
{
    pair<int, int> k = tlca.get(min(L[v], L[u]), max(R[v], R[u]));
    return k.second;
}

int dista(int v, int u, sparse_min<pair<int, int> > &tlca)
{
    return dist[v] + dist[u] - 2 * dist[LCA(v, u, tlca)];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u, v--, u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    dfs(0, -1, 0);
    sparse_min<pair<int, int> > tlca(V);
    cin >> q;
    while (q--)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--, y--, a--, b--;
        int len = dista(x, y, tlca) + 1;
        int path = dista(a, b, tlca);
        if (path % 2 == k % 2 && path <= k)
        {
            cout << "YES\n";
            continue;
        }
        if (len % 2 == 0 && k % 2 != path % 2)
        {
            cout << "NO\n";
            continue;
        }
        int path2 = dista(a, x, tlca) + 1 + dista(y, b, tlca);
        int path3 = dista(a, y, tlca) + 1 + dista(x, b, tlca);
        if (path2 <= k && path2 % 2 == k % 2)
        {
            cout << "YES\n";
            continue;
        }
        if (path3 <= k && path3 % 2 == k % 2)
        {
            cout << "YES\n";
            continue;
        }
        path2 += len, path3 += len;
        int path4 = dista(a, x, tlca) + dista(b, x, tlca) + len;
        int path5 = dista(a, y, tlca) + dista(b, y, tlca) + len;
        if (path2 <= k || path3 <= k || path4 <= k || path5 <= k)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}