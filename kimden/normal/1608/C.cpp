#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<vector<int>> g, gt;
vector<int> order;
vector<int> mkd;

struct player {
    int a;
    int b;
    int idx;
};

void dfs(int v) {
    mkd[v] = 1;
    for (int u: g[v]) {
        if (!mkd[u]) {
            dfs(u);
        }
    }
    mkd[v] = 2;
    order.push_back(v);
}
void dfs2(int v) {
    mkd[v] = 1;
    for (int u: gt[v]) {
        if (!mkd[u]) {
            dfs2(u);
        }
    }
    mkd[v] = 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.clear();
        order.clear();
        gt.clear();
        gt.resize(n);
        g.resize(n);
        mkd.clear();
        mkd.resize(n, 0);
        vector<player> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i].a;
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i].b;
        }
        for (int i = 0; i < n; ++i) {
            p[i].idx = i;
        }
        sort(p.begin(), p.end(), [](const player& a, const player& b) -> bool {
           return a.a < b.a;
        });
        for (int i = 0; i + 1 < n; ++i) {
            g[p[i + 1].idx].push_back(p[i].idx);
            gt[p[i].idx].push_back(p[i + 1].idx);
        }
        sort(p.begin(), p.end(), [](const player& a, const player& b) -> bool {
            return a.b < b.b;
        });
        for (int i = 0; i + 1 < n; ++i) {
            g[p[i + 1].idx].push_back(p[i].idx);
            gt[p[i].idx].push_back(p[i + 1].idx);
        }
        dfs(p.back().idx);
        fill(mkd.begin(), mkd.end(), 0);
        dfs2(order.back());
        for (int i = 0; i < n; ++i) {
            cout << (mkd[i] ? 1 : 0);
        }
        cout << "\n";
    }

}