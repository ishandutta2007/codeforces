#include <bits/stdc++.h>

using namespace std;

class Solver {
   private:
    static const int N = 4e5 + 5;

    int n, m;

    class Node {
       public:
        int fail = 0;
        int next[26] = {};
    };

    Node t[N];
    int tot_node = 1;
    vector<pair<int, int>> g[N], query[N];
    vector<int> f[N];
    int ans[N];
    int tm = 0;
    int in[N], out[N];
    int a[N] = {};

    void dfs(int u) {
        in[u] = ++tm;
        for (int v : f[u]) {
            dfs(v);
        }
        out[u] = tm;
    }

    void add(int x, int y) {
        while (x <= tot_node) {
            a[x] += y;
            x += x & -x;
        }
    }

    int sum(int x) {
        int y = 0;
        while (x > 0) {
            y += a[x];
            x -= x & -x;
        }
        return y;
    }

    int rangeSum(int l, int r) { return sum(r) - sum(l - 1); }

    void work(int u, int p) {
        add(in[p], 1);
        for (auto [x, p] : query[u]) {
            ans[x] = rangeSum(in[p], out[p]);
        }
        for (auto [v, c] : g[u]) {
            work(v, t[p].next[c]);
        }
        add(in[p], -1);
    }

   public:
    void solve() {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int op;
            cin >> op;
            if (op == 1) {
                char c;
                cin >> c;
                g[0].emplace_back(i, c - 'a');
            } else {
                int p;
                char c;
                cin >> p >> c;
                g[p].emplace_back(i, c - 'a');
            }
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string s;
            int x;
            cin >> x >> s;
            int p = 1;
            for (char c : s) {
                if (t[p].next[c - 'a'] == 0) {
                    t[p].next[c - 'a'] = ++tot_node;
                }
                p = t[p].next[c - 'a'];
            }
            query[x].emplace_back(i, p);
        }
        queue<int> que;
        for (int i = 0; i < 26; ++i) {
            t[0].next[i] = 1;
        }
        que.push(1);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i = 0; i < 26; ++i) {
                if (t[u].next[i] > 0) {
                    t[t[u].next[i]].fail = t[t[u].fail].next[i];
                    que.push(t[u].next[i]);
                } else {
                    t[u].next[i] = t[t[u].fail].next[i];
                }
            }
        }
        for (int i = 2; i <= tot_node; ++i) {
            f[t[i].fail].push_back(i);
        }
        dfs(1);
        work(0, 1);
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Solver().solve();
    return 0;
}