#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull n, m;
    cin >> n >> m;
    ull A, B, C;
    cin >> A >> B >> C;
    vector<vector<int>> adj;
    adj.resize(n);
    for (ull i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (auto& v : adj)
        sort(v.begin(), v.end());
    
    // all
    ull all = 0;
    for (ull i = 0; i < n; i++) {
        ull r = n - i - 1;
        ull l = i;
        // i < j < k
        all += A * i * (r * (r - 1) / 2);
        // j < i < k
        all += B * i * l * r;
        // j < k < i
        all += C * i * (l * (l - 1) / 2);
    }

    // one pair
    ull one = 0;
    for (ull i = 0; i < n; i++) {
        auto& a = adj[i];
        ull r = n - i - 1;
        ull l = i;
        // pair (i, j) or (i, k)
        // i < j < k
        auto it = upper_bound(a.begin(), a.end(), i);
        for (; it != a.end(); ++it) {
            one += A * i * (r - 1);
        }
        // j < i < k
        for (auto it = a.begin(); it != a.end(); ++it) {
            one += B * i * ((ull)*it < i ? r : l);
        }
        // j < k < i
        auto uit = upper_bound(a.begin(), a.end(), i);
        for (auto it = a.begin(); it != uit; ++it) {
            one += C * i * (l - 1);
        }
    }
    // pair (j, k)
    // i < j < k
    int edges = m;
    for (ull i = 0; i < n; i++) {
        for (int x : adj[i]) {
            if ((ull)x > i)
                edges--;
        }
        one += A * i * edges;
    }
    // j < i < k
    for (int j = 0; j < (int)n; j++) {
        for (int k : adj[j]) {
            if (k < j) continue;
            one += B * ((ull)(j + 1 + k - 1) * (ull)(k - 1 - j) / 2);
        }
    } 
    // j < k < i
    edges = m;
    for (int i = n - 1; i >= 0; i--) {
        for (int x : adj[i]) {
            if (x < i)
                edges--;
        }
        one += C * i * edges;
    }

    // two pairs 
    ull two = 0;
    // (i, j) and (i, k)
    // i < j < k
    for (ull i = 0; i < n; i++) {
        ull sz = adj[i].size();
        for (int j = 0; j < (int)sz; j++) {
            ull j_val = adj[i][j];
            if (j_val < i) continue;
            two += A * i * (sz - j - 1);
        }
    }
    // j < i < k
    for (ull i = 0; i < n; i++) {
        ull sz = adj[i].size();
        int upper = adj[i].end() - upper_bound(adj[i].begin(), adj[i].end(), i);
        for (int j = 0; j < (int)sz; j++) {
            ull j_val = adj[i][j];
            if (j_val > i) continue;
            two += B * i * upper;
        }
    }
    // j < k < i
    for (ull i = 0; i < n; i++) {
        ull sz = adj[i].size();
        for (int j = 0; j < (int)sz; j++) {
            ull j_val = adj[i][j];
            if (j_val > i) continue;
            two += C * i * j;
        }
    }
    // (i, j) and (j, k)
    // i < j < k
    for (ull j = 0; j < n; j++) {
        ull sz = adj[j].size();
        int upper = adj[j].end() - upper_bound(adj[j].begin(), adj[j].end(), j);
        for (ull i = 0; i < sz; i++) {
            ull i_val = adj[j][i];
            if (i_val > j) continue;
            two += A * i_val * upper;
        }
    }
    // j < i < k
    for (ull j = 0; j < n; j++) {
        ull sz = adj[j].size();
        for (ull i = 0; i < sz; i++) {
            ull i_val = adj[j][i];
            if (i_val < j) continue;
            two += B * i_val * (sz - i - 1);
        }
    }
    // j < k < i
    for (ull j = 0; j < n; j++) {
        ull sz = adj[j].size();
        int lower = upper_bound(adj[j].begin(), adj[j].end(), j) - adj[j].begin();
        for (int i = sz - 1; i >= 0; i--) {
            ull i_val = adj[j][i];
            if (i_val < j) continue;
            two += C * i_val * (i - lower);
        }
    }
    // (i, k) and (j, k)
    // i < j < k
    for (ull k = 0; k < n; k++) {
        ull sz = adj[k].size();
        int upper = adj[k].end() - upper_bound(adj[k].begin(), adj[k].end(), k);
        int lower = sz - upper;
        for (int i = sz - 1; i >= 0; i--) {
            ull i_val = adj[k][i];
            if (i_val > k) continue;
            two += A * i_val * (lower - i - 1);
        }
    }
    // j < i < k
    for (ull k = 0; k < n; k++) {
        ull sz = adj[k].size();
        for (int i = 0; i < (int)sz; i++) {
            ull i_val = adj[k][i];
            if (i_val > k) continue;
            two += B * i_val * i;
        }
    }
    // j < k < i
    for (ull k = 0; k < n; k++) {
        ull sz = adj[k].size();
        int upper = adj[k].end() - upper_bound(adj[k].begin(), adj[k].end(), k);
        int lower = sz - upper;
        for (int i = 0; i < (int)sz; i++) {
            ull i_val = adj[k][i];
            if (i_val < k) continue;
            two += C * i_val * lower;
        }
    }

    // three (i, j) and (i, k) and (j, k)
    ull three = 0;
    // first heavy points
    int sq = max(1, (int)sqrt(m));
    vector<int> heavy_idx(n, -1);
    vector<bitset<200'000>> heavy;
    vector<ull> heavy_back;
    for (int i = 0; i < (int)n; i++) {
        if ((int)adj[i].size() >= sq) {
            heavy_idx[i] = heavy.size();
            heavy_back.push_back(i);
            heavy.emplace_back(0);
            for (int j : adj[i])
                heavy[heavy_idx[i]][j] = 1;
        }
    }
    // j < k < i
    // last one is heavy
    // if (C != 547683) {
        for (int h = 0; h < (int)heavy.size(); h++) {
            ull i = heavy_back[h];
            auto& he = heavy[h];
            for (ull k = 0; k < i; k++) {
                if (!he[k]) continue;
                for (ull j : adj[k]) {
                    if (j > k) break;
                    if (he[j])
                        three += A * j + B * k + C * i;
                }
            }
        }
    // } else {
    //     cout << heavy.size() << '\n';
    // }
    // i is not heavy
    bitset<200'000> bs(0);
    for (ull i = 0; i < n; i++) {
        if (heavy_idx[i] >= 0) continue;
        for (ull k : adj[i]) {
            if (k > i) break;
            if (heavy_idx[k] >= 0) {
                for (ull j : adj[i]) {
                    if (j > k) break;
                    if (heavy[heavy_idx[k]][j])
                        three += A * j + B * k + C * i;
                }
            } else {
                // i and k are not heavy
                for (ull j : adj[k])
                    bs[j] = 1;

                for (ull j : adj[i]) {
                    if (j > k) break;
                    if (bs[j])
                        three += A * j + B * k + C * i;
                }

                for (ull j : adj[k])
                    bs[j] = 0;
            }
        }
    }
    
    cout << all - one + two - three << '\n';
    cerr << all << '\n';
    cerr << one << '\n';
    cerr << two << '\n';
}