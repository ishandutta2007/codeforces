// Hydro submission #62c6d5f4c3a9fda5622b1ec3@1657198069373
#include <bits/stdc++.h>
typedef long long ll;
#define f first
#define s second

using namespace std;

struct RollbackDSU {
    int n;
    vector<int> link, sz;
    vector<array<int, 4>> updates;

    RollbackDSU() {};
 
    RollbackDSU(int n): n(n), link(n), sz(n) {
        for(int i = 0; i < n; i++) {
            link[i] = i;
            sz[i] = 1;
        }
    }
 
    int f(int x) {
        return (x == link[x] ? x : f(link[x]));
    }
 
    void unite(int x, int y) {
        x = f(x), y = f(y);
        if(sz[x] < sz[y]) {
            swap(x, y);
        }
        updates.push_back({x, y, sz[x], link[y]});
        sz[x] += sz[y], link[y] = x;
    }

    void go_back() {
        if(updates.empty()) {
            return;
        }
        array<int, 4> upd = updates.back();
        updates.pop_back();
        sz[upd[0]] = upd[2], link[upd[1]] = upd[3];
    }

    int get_size(int x) {
        return sz[f(x)];
    }
} d;

int n;
ll ans;
vector<pair<int, int>> edges[500000], updates[2000000];

void upd(int lo, int hi, pair<int, int> edge, int lb = 0, int ub = n - 1, int ind = 0) {
    if(lo > hi) {
        return;
    }
    if(lo <= lb && ub <= hi) {
        updates[ind].push_back(edge);
        return;
    }
    int mid = (lb + ub) >> 1;
    if(lo <= mid) {
        upd(lo, hi, edge, lb, mid, 2 * ind + 1);
    }
    if(mid < hi) {
        upd(lo, hi, edge, mid + 1, ub, 2 * ind + 2);
    }
}

void dfs(int lo, int hi, int ind) {
    for(pair<int, int> u: updates[ind]) {
        d.unite(u.f, u.s);
    }
    if(lo == hi) {
        for(pair<int, int> e: edges[lo]) {
            ans += 1LL * d.get_size(e.f) * d.get_size(e.s);
        }
    } else {
        int mid = (lo + hi) >> 1;
        dfs(lo, mid, 2 * ind + 1);
        dfs(mid + 1, hi, 2 * ind + 2);
    }
    for(int i = 0; i < updates[ind].size(); i++) {
        d.go_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n;
    d = RollbackDSU(n);
    for(int i = 0, u, v, x; i < n - 1; i++) {
        cin >> u >> v >> x;
        upd(0, x - 2, {u - 1, v - 1}), upd(x, n - 1, {u - 1, v - 1});
        edges[x - 1].push_back({u - 1, v - 1});
    }
    dfs(0, n - 1, 0);
    cout << ans << endl;
}