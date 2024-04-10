#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
struct Edge{
    int u, v;
    int get(int x) {
        return u ^ v ^ x;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<Edge> e(m);
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < m; i += 1) {
            cin >> e[i].u >> e[i].v;
            G[e[i].u].push_back(i);
            G[e[i].v].push_back(i);
        }
        vector<int> p(n + 1), pi(n + 1, -1), dep(n + 1);
        vector<int> non;
        function<void(int)> DFS = [&](int u) {
            for (int i : G[u]) if (i != pi[u]) {
                int v = e[i].get(u);
                if (dep[v]) {
                    if (dep[v] < dep[u]) non.push_back(i);
                    continue;
                }
                dep[v] = dep[u] + 1;
                p[v] = u;
                pi[v] = i;
                DFS(v);
            }
        };
        DFS(dep[1] = 1);
        set<int> s;
        for (int i : non) {
            s.insert(e[i].u);
            s.insert(e[i].v);
        }
        if (non.size() <= 2 or s.size() > 3) {
            for (int i = 0; i < m; i += 1)
                if (ranges::count(non, i)) cout << 0;
                else cout << 1;
            cout << "\n";
            continue;
        }
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end(), [&](int x, int y){
            return dep[x] > dep[y];
        });
        string ans(m, '0');
        for (int i : non)
            if ((e[i].u ^ e[i].v) == (v[0] ^ v.back()))
                ans[i] = '1';
        ans[pi[v[0]]] = ans[pi[v[1]]] = '1';
        cout << ans << "\n";
    }
}