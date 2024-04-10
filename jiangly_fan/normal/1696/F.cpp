#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector s(n, vector<string>(n));
        for (int i = 0; i < n; i += 1)
            for (int j = i + 1; j < n; j += 1) {
                cin >> s[i][j];
                s[j][i] = s[i][j];
            }
        for (int i = 0; i < n; i += 1)
            s[i][i] = string(n, '1');
        vector<int> p(n), f(n);
        for (int i = 1; i < n; i += 1)
            p[i] = i;
        function<int(int)> fp = [&](int u) {
            return p[u] == u ? u : p[u] = fp(p[u]);  
        };
        for (int i = 1; i < n; i += 1)
            for (int j = i + 1; j < n; j += 1)
                if (s[i][j][0] == '1')
                    p[fp(j)] = fp(i);
        vector d(n, vector<int>(n));
        int ok = 0;
        for (int i = 1; i < n; i += 1)
            if (1 || p[i] == i) {
                vector<int> f(n, -1);
                function<void(int u)> DFS = [&](int u) {
                    for (int v = 0; v < n; v += 1)
                        if (v != f[u] and f[v] == -1 and s[v][f[u]][u] == '1') {
                            f[v] = u;
                            DFS(v);
                        }
                };
                for (int j = 1; j < n; j += 1)
                    if (fp(j) == i) {
                        f[j] = 0;
                        DFS(j);
                    }
                vector<vector<int>> G(n);
                int pok = 1;
                for (int i = 1; i < n and pok; i += 1) {
                    if (f[i] == -1) {
                        pok = 0;
                        break;
                    }
                    G[f[i]].push_back(i);
                    G[i].push_back(f[i]);
                }
                if (not pok) continue;
                vector d(n, vector<int>(n, -1));
                for (int i = 0; i < n; i += 1) {
                    function<void(int u)> DFS = [&](int u) {
                        for (int v : G[u])
                            if (d[i][v] == -1) {
                                d[i][v] = d[i][u] + 1;
                                DFS(v);
                            }
                    };
                    d[i][i] = 0;
                    DFS(i);
                }
                for (int i = 0; i < n and pok; i += 1)
                    for (int j = i + 1; j < n and pok; j += 1)
                        for (int k = 0; k < n and pok; k += 1)
                            pok = (d[i][k] == d[j][k]) ^ (s[i][j][k] == '0');
                if (pok) {
                    ok = 1;
                    cout << "Yes\n";
                    for (int i = 1; i < n; i += 1)
                        cout << i + 1 << " " << f[i] + 1 << "\n";
                    break;
                }
            }
        if (not ok) cout << "No\n";
    }
    return 0;
}