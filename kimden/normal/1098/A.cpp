#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<int> p, s;
ll ans = 0;
vector<vector<int>> g;

void dfs(int v, int prevsum = 0) {
    if (s[v] == -1) {
        int minsum = 1001001001;
        for (auto u: g[v]) {
            minsum = min(minsum, s[u]);
        }
        if (1001001001 == minsum) {
            s[v] = prevsum;
            return;
        }
        if (minsum < prevsum) {
            cout << -1 << endl;
            exit(0);
        }
        s[v] = minsum;
    }
    ans += s[v] - prevsum;
    for (auto u: g[v]) {
        dfs(u, s[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    p.resize(n, -1);
    s.resize(n, 0);
    g.resize(n);
    for(int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        g[p[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    dfs(0);
    cout << ans << endl;
}