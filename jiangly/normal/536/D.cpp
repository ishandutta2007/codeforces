#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 1E18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    --s;
    --t;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    auto dijkstra = [&](int s) {
        vector<long long> dis(n, 1E18);
        priority_queue<pair<long long, int>> q;
        dis[s] = 0;
        q.emplace(0, s);
        while (!q.empty()) {
            long long d;
            int u;
            tie(d, u) = q.top();
            q.pop();
            d = -d;
            if (d != dis[u])
                continue;
            for (auto ed : e[u]) {
                int v, w;
                tie(v, w) = ed;
                if (dis[v] > d + w) {
                    dis[v] = d + w;
                    q.emplace(-dis[v], v);
                }
            }
        }
        auto values = dis;
        sort(values.begin(), values.end());
        for (int i = 0; i < n; ++i)
            dis[i] = lower_bound(values.begin(), values.end(), dis[i]) - values.begin();
        return vector<int>(dis.begin(), dis.end());
    };
    auto ds = dijkstra(s), dt = dijkstra(t);
    vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
    vector<vector<long long>> sum(n + 1, vector<long long>(n + 1));
    for (int i = 0; i < n; ++i) {
        ++cnt[ds[i]][dt[i]];
        sum[ds[i]][dt[i]] += p[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
            sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
        }
    }
    vector<vector<long long>> dpa(n + 1, vector<long long>(n + 1)), dpb(n + 1, vector<long long>(n + 1));
    vector<vector<pair<long long, int>>> qa(n + 1, {{}, {}}), qb(n + 1, {{}, {}});
    auto update = [&](auto x, auto &f) {
        if (x < f[0])
            swap(x, f[0]);
        if (x.second == f[0].second)
            return;
        f[1] = min(f[1], x);
    };
    for (int i = n; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if (cnt[i][j] == 0)
                continue;
            dpa[i][j] = sum[i][j] - (cnt[i][j] == qa[j][0].second ? qa[j][1] : qa[j][0]).first;
            dpb[i][j] = sum[i][j] - (cnt[i][j] == qb[i][0].second ? qb[i][1] : qb[i][0]).first;
            update(make_pair(dpa[i][j], cnt[i][j]), qb[i]);
            update(make_pair(dpb[i][j], cnt[i][j]), qa[j]);
        }
    }
    long long x = dpa[0][0], y = sum[0][0] - x;
    if (x < y)
        cout << "Cry\n";
    else if (x > y)
        cout << "Break a heart\n";
    else
        cout << "Flowers\n";
    return 0;
}