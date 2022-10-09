// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int node[400005], nodes;
int parent[1200005]; // Always a tree, roots point at themselves
int color[1200005]; // Only applies to roots
set<pair<int, int>> mp; // Contains pairs (color[x], x) for all roots x

int mknode(int c) {
    int x = nodes++;
    parent[x] = x;
    mp.emplace(c, x);
    color[x] = c;
    return x;
}

int ep(int x) {
    if (x == parent[x]) {
        return x;
    }

    return parent[x] = ep(parent[x]);
}

void range_color(int l, int r, int c) {
    int root = mknode(c);
    auto it = mp.lower_bound({l, -1});
    while (it != mp.end() && it->first <= r) {
        auto [ic, ix] = *it;
        it = mp.erase(it);
        parent[ix] = root;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(1, n+1)) {
        int c;
        cin >> c;
        node[i] = mknode(c);
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, w;
            cin >> k >> w;
            node[k] = mknode(w);
        } else if (t == 2) {
            int k;
            cin >> k;
            int root = ep(node[k]);
            
            cout << color[root] << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            int m = (l+r) / 2;
            range_color(l, m, l-1);
            range_color(m+1, r, r+1);
        }
    }
}