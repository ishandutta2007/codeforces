#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> vector<T> sort_unique(vector<T> vec) {
    sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};


void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> to(N);
    for (int i = 0; i < N; i++) to[i] = {i};
    while (M--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        to[l].push_back(r), to[r].push_back(l);
    }
    for (auto &vec : to) vec = sort_unique(vec);

    vector<int> conn(N, -1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < int(to[i].size()); j++) {
            if (to[i][j] != j) {
                conn[i] = j;
                break;
            }
        }
        if (conn[i] < 0 and int(to[i].size()) < N) {
            conn[i] = to[i].size();
        }
    }

    //  to[i]: i  deg[i]: 
    to.assign(N, {});
    vector<int> deg(N);
    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        int j = conn[i];
        if (j >= 0 and uf.unite(i, j)) {
            to[i].push_back(j);
            to[j].push_back(i);
            deg[i]++, deg[j]++;
        }
    }

    vector<int> belong(N, -1);
    int ngrp = 0;
    for (int i = 0; i < N; i++) if (deg[i] == 0) belong[i] = ngrp++;

    vector<int> is_center(N);
    auto reduce_deg_adj_i = [&](int i) -> void {
        for (auto j : to[i]) deg[j]--;
    };

    vector<int> leaves;
    for (int i = 0; i < N; i++) if (deg[i] == 1) leaves.push_back(i);
    while (leaves.size()) {
        for (auto i : leaves) belong[i] = -2;
        for (auto i : leaves) if (belong[i] == -2) {
            for (auto j : to[i]) {
                if (belong[j] == -2) {
                    belong[i] = belong[j] = ngrp++;
                    reduce_deg_adj_i(i), reduce_deg_adj_i(j);
                    break;
                }
            }
        }
        vector<int> tmp;
        for (auto i : leaves) if (belong[i] == -2) tmp.push_back(i);
        leaves = tmp;

        unordered_map<int, vector<int>> mp;
        for (auto i : leaves) {
            int r = -3;
            for (auto j : to[i]) {
                if (belong[j] == -1) {
                    r = j;
                    break;
                }
            }
            mp[r].push_back(i);
        }

        for (auto [r, ii] : mp) {
            if (r == -3) {
                for (auto i : ii) {
                    if (to[i].size()) belong[i] = belong[to[i][0]];
                }
            } else {
                for (auto i : ii) belong[i] = ngrp, reduce_deg_adj_i(i);
                belong[r] = ngrp, reduce_deg_adj_i(r);
                is_center[r] = 1;
                ngrp++;
            }
        }

        leaves.clear();
        for (auto [r, _] : mp) {
            if (r < 0) continue;
            for (auto i : to[r]) {
                if (belong[i] < 0 and deg[i] <= 1) leaves.push_back(i);
            }
        }
    }

    vector<vector<int>> grps(ngrp);
    for (int i = 0; i < N; i++) grps[belong[i]].push_back(i);
    int cnt = 1;
    vector<int> ret1(N), ret2(N);
    for (auto is : grps) {
        if (is.size() == 1) ret1[is[0]] = ret2[is[0]] = cnt++;
        else {
            int r = is[0];
            for (auto i : is) if (is_center[i]) r = i;
            is.erase(find(is.begin(), is.end(), r));
            ret1[r] = cnt;
            ret2[r] = cnt + int(is.size());
            for (int j = 0; j < int(is.size()); j++) {
                ret1[is[j]] = cnt + j + 1;
                ret2[is[j]] = cnt + j;
            }
            cnt += is.size() + 1;
        }
    }
    for (auto x : ret1) cout << x << ' ';
    cout << '\n';
    for (auto x : ret2) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
}