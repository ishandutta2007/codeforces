#include <bits/stdc++.h>
using namespace std;

const int maxn = 500007;

struct info {
    int idx, val;
    friend bool operator<(info u, info v) {
        return u.val == v.val ? u.idx < v.idx : u.val < v.val;
    }
};

struct stars {
    int rt;
    vector<int> leaves;
};
set<int> rv;       // remained vertices
set<int> g[maxn];  // original graph
set<int> t[maxn];  // dfs tree
set<info> d;
int deg[maxn];
int n, m;
int perm1[maxn], perm2[maxn];
vector<stars> res;

void dfs(int u) {
    rv.erase(u);
    int crt = 0;
    while (1) {
        auto iter = rv.upper_bound(crt);
        if (iter == rv.end()) break;
        int v = *iter;
        crt = v;
        if (g[u].find(v) != g[u].end()) continue;
        t[u].insert(v), t[v].insert(u);
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) g[i].clear(), t[i].clear();
        rv.clear(), res.clear(), d.clear();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].insert(v), g[v].insert(u);
        }
        for (int i = 1; i <= n; ++i) rv.insert(i);
        while (rv.size() > 0) {
            int u = *(rv.begin());
            dfs(u);
        }
        int rem = n;
        for (int i = 1; i <= n; ++i) {
            deg[i] = t[i].size();
            if (deg[i]) {
                d.insert((info){i, deg[i]});
            } else {
                perm1[i] = perm2[i] = rem;
                rem--;
            }
        }
        while (d.size()) {
            int idx = (*(d.begin())).idx;
            int f = *(t[idx].begin());
            vector<int> leaves;
            leaves.clear();
            d.erase((info){f, deg[f]});
            for (auto c : t[f]) {
                d.erase((info){c, deg[c]});
                if (deg[c] == 1)
                    leaves.push_back(c);
                else
                    deg[c]--, d.insert((info){c, deg[c]}), t[c].erase(f);
            }
            res.push_back((stars){f, leaves});
        }
        int l = 0, r = 0;
        for (auto c : res) {
            perm1[c.rt] = ++l;
            for (auto ls : c.leaves) {
                perm1[ls] = ++l;
                perm2[ls] = ++r;
            }
            perm2[c.rt] = ++r;
        }
        for (int i = 1; i <= n; ++i) cout << perm1[i] << " ";
        cout << "\n";
        for (int i = 1; i <= n; ++i) cout << perm2[i] << " ";
        cout << "\n";
    }
}