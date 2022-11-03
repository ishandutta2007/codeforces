#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<vector<pii>> g;
vector<int> p, sz, p_c, del, h;
vector<vector<int>> anc, anc_c;

void dfs(int v, int prv = -1){
    sz[v] = 1;
    for(auto pr: g[v]){
        int u = pr.second;
        int e = pr.first;
        if(u == prv || del[e]){
            continue;
        }
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int find_centroid(int v){
    dfs(v, -1);
    int total_size = sz[v];
    int prv = -1;
    while(1) {
        int max_subtree = 0;
        int max_subtree_idx = -1;
        int sum_subtrees = 0;
        for (auto pr: g[v]) {
            int u = pr.second;
            int e = pr.first;
            if (u == prv || del[e]) {
                continue;
            }
            if (max_subtree < sz[u] && sz[u] * 2 > total_size) {
                max_subtree = sz[u];
                max_subtree_idx = u;
            }
            sum_subtrees += sz[u];
        }
        if(max_subtree_idx == -1 && (total_size - sum_subtrees - 1) * 2 <= total_size){
            return v;
        }
        prv = v;
        v = max_subtree_idx;
    }
}
vector<int> ans;
// In main.cpp: c_d(anything, -1)
void centroid_decomposition(int v, int prv = -1, char ch = 'A') {
    int c = find_centroid(v);
    ans[c] = ch;
    for(auto pr: g[c]){
        int e = pr.first;
        int u = pr.second;
        if(del[e]){
            continue;
        }
        del[e] = 1;
        centroid_decomposition(u, c, ch + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    p.resize(n, -1);
    sz.resize(n);
    del.resize(n - 1, 0);
    h.resize(n, 0);
    anc.resize(n);
    anc_c.resize(n);
    ans.resize(n);
    for(int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].emplace_back(i, b);
        g[b].emplace_back(i, a);
    }
    centroid_decomposition(0);
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << char(ans[i]);
    }
    cout << endl;
}