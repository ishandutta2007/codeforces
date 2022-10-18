#include "bits/stdc++.h"
using namespace std;

int n, m;

/* struct S { */
/*     int a, b, c; */
/*     int min() { */
/*         return min({a, b, c}); */
/*     } */
/* }; */

/* vector<S> dp; */

/* void dfs(int v) { */
/*     if (adj3[v].size()) { */
/*         for (int u : adj3[v]) { */
/*             dfs(u); */
/*         } */
/*         // this one is */
/*         int t1 = 1; */
/*         for (int u : adj3[v]) { */
/*             t1 = min(INF, t1 + dp[u].min()); */
/*         } */
/*         // there are all of the children */
/*         int t2 = 0; */
/*         for (int u : adj3[v]) { */
/*             t2 = min(INF, t2 + dp[u].a); */
/*         } */
/*         // there are not all of the children */
/*         int t3 = 0; */
/*         for (int u : adj3[v]) { */
/*             t3 = min(INF, t3 + min(dp[u].a, dp[u].b)); */
/*         } */
/*         dp[v] = {t1, t2, t3}; */
/*     } else { */
/*         // this one is, there are all of the children, there are none of the child */
/*         dp[v] = {1, INF, 0}; */
/*     } */
/* } */

using Path = array<int, 3>;

void solve() {
    cin >> n >> m;
    vector<vector<int>> adj, adj2;
    adj.resize(n);
    adj2.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<Path> paths;
    vector<vector<int>> path_indices(n);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            for (int k : adj[j]) {
                int idx = paths.size();
                paths.push_back({i, j, k});
                path_indices[i].push_back(idx);
                path_indices[j].push_back(idx);
                path_indices[k].push_back(idx);
            }
        }
    }

    vector<int> rem(n);
    for (int i = 0; i < n; i++) {
        rem[i] = adj2[i].size();
    }
    vector<int> max_dist(n, 0);

    vector<int> result;
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (rem[i] == 0)
            Q.push(i);
    }

    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        if (max_dist[v] == 2) {
            result.push_back(v);
            for (int u : adj[v]) {
                max_dist[u] = max(max_dist[u], 0);
                rem[u]--;
                if (rem[u] == 0)
                    Q.push(u);
            }
        } else {
            for (int u : adj[v]) {
                max_dist[u] = max(max_dist[u], max_dist[v] + 1);
                rem[u]--;
                if (rem[u] == 0)
                    Q.push(u);
            }
        }
    }

    int ma = 4*n/7;
    if (result.size() <= ma) {
        cout << result.size() << '\n';
        for (int x : result) 
            cout << x + 1 << " ";
        cout << '\n';
    } else {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::random_device rd;
        std::mt19937 rng(rd());
        while (true) {
            shuffle(paths.begin(), paths.end(), rng);
            uniform_int_distribution<int> uni(0, 2); 
            vector<bool> to_delete(n, false);
            int cnt = 0;
            for (auto p : paths) {
                if (to_delete[p[0]] || to_delete[p[1]] || to_delete[p[2]])
                    continue;
                int idx = uni(rng);
                /* cout << "123" << idx << '\n'; */
                to_delete[p[idx]] = true;
                cnt += 1;
            }
            if (cnt <= ma) {
                cout << cnt << '\n';
                for (int i = 0; i < n; i++) {
                    if (to_delete[i])
                        cout << i + 1 << " ";
                }
                cout << '\n';
                break;
            }
        }
    }

    /* set<pair<int, int>> s; // -number, node */
    /* for (int i = 0; i < n; i++) { */
    /*     s.insert({-(int)path_indices[i].size(), i}); */
    /* } */

    /* while (s.size()) { */
    /*     auto [negnumb, v] = *s.begin(); */
    /*     int numb = -negnumb; */

    /* } */
    
    /* vector<bool> todelete(n, false); */
    /* for (int i = 0; i < n; i++) { */
    /*     if (adj2[i].size() > 1) { */
    /*         todelete[i] = true; */
    /*     } */
    /* } */

    /* adj3.clear(); */
    /* adj3.resize(n); */
    /* adj2.clear(); */
    /* adj2.resize(n); */
    /* for (int i = 0; i < n; i++) { */
    /*     if (todelete[i]) */
    /*         continue; */
    /*     for (int j : adj[i]) { */
    /*         if (todelete[j]) */
    /*             continue; */
    /*         adj3[i].push_back(j); */
    /*         adj2[j].push_back(i); */
    /*     } */
    /* } */
    /* for (int i = 0; i < n; i++) { */
    /*     if (adj[ */
    /* } */

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}