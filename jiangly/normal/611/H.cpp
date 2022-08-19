#include <bits/stdc++.h>
using namespace std;
class Flow {
public:
    int n;
    vector<pair<int, int>> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    bool bfs(int s, int t) {
        h.assign(n, -1);
        queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) {
                int v, c;
                tie(v, c) = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i];
            int v, c;
            tie(v, c) = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, min(r, c));
                e[j].second -= a;
                e[j ^ 1].second += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
public:
    Flow(int n) : n(n) {g.resize(n);}
    void addEdge(int u, int v, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    int maxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, 1E9);
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int k = to_string(n).length();
    if (k == 1) {
        for (int i = 2; i <= n; ++i)
            cout << 1 << " " << i << "\n";
        return 0;
    }
    vector<int> cnt(k);
    cnt.back() = n;
    for (int i = 0; i < k - 1; ++i) {
        cnt[i] = i == 0 ? 9 : cnt[i - 1] * 10;
        cnt.back() -= cnt[i];
    }
    vector<vector<int>> e(k, vector<int>(k));
    for (int i = 0; i < n - 1; ++i) {
        string s;
        int u, v;
        cin >> s;
        u = s.length() - 1;
        cin >> s;
        v = s.length() - 1;
        ++e[u][v];
    }
    vector<int> a(k - 2);
    auto check = [&]() {
        set<int> h;
        vector<int> lst(k, -1);
        for (int i = 0; i < k - 2; ++i)
            lst[a[i]] = i;
        for (int i = 0; i < k; ++i)
            if (lst[i] == -1)
                h.insert(i);
        vector<pair<int, int>> edges;
        for (int i = 0; i < k - 2; ++i){
            int u = a[i];
            int v = *h.begin();
            if (lst[u] == i)
                h.insert(u);
            h.erase(v);
            if (e[u][v] + e[v][u] == 0)
                return;
            if (e[u][v] == 0)
                swap(u, v);
            edges.emplace_back(u, v);
        }
        int u = *h.begin(), v = *h.rbegin();
        if (e[u][v] + e[v][u] == 0)
            return;
        if (e[u][v] == 0)
            swap(u, v);
        edges.emplace_back(u, v);
        for (auto ed : edges) {
            tie(u, v) = ed;
            --e[u][v];
        }
        Flow flow(2 + k * (k + 1));
        const int s = k, t = s + 1;
        for (int i = 0; i < k; ++i)
            flow.addEdge(i, t, cnt[i] - 1);
        int c = k + 2;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                flow.addEdge(s, c, e[i][j]);
                flow.addEdge(c, i, e[i][j]);
                flow.addEdge(c, j, e[i][j]);
                ++c;
            }
        }
        if (flow.maxFlow(s, t) == n - k) {
            vector<int> ver(k), cur;
            for (int i = 0; i < k; ++i)
                ver[i] = i == 0 ? 1 : 10 * ver[i - 1];
            for (auto ed : edges) {
                tie(u, v) = ed;
                cout << ver[u] << " " << ver[v] << "\n";
            }
            cur = ver;
            c = k + 2;
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j) {
                    for (int l : flow.g[c]) {
                        int v, x;
                        tie(v, x) = flow.e[l];
                        if (v == i) {
                            for (int t = 0; t < e[i][j] - x; ++t)
                                cout << ++cur[i] << " " << ver[j] << "\n";
                        } else {
                            for (int t = 0; t < e[i][j] - x; ++t)
                                cout << ver[i] << " " << ++cur[j] << "\n";
                        }
                    }
                    ++c;
                }
            }
            exit(0);
        }
        for (auto ed : edges) {
            tie(u, v) = ed;
            ++e[u][v];
        }
    };
    function<void(int)> dfs = [&](int x) {
        if (x == k - 2) {
            check();
            return;
        }
        for (int i = 0; i < k; ++i) {
            a[x] = i;
            dfs(x + 1);
        }
    };
    dfs(0);
    cout << -1 << "\n";
    return 0;
}