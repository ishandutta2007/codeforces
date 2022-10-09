// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct tree_topology {
    int n;
    vector<int> p, d, l, r;
    vector<vector<int>> e;

    void dfs(int x, int& t) {
        l[x] = t++;
        for (int y : e[x]) {
            if (y == p[x]) continue;
            d[y] = d[x] + 1;
            p[y] = x;
            dfs(y, t);
        }
        r[x] = t;
    }

    tree_topology(const vector<pair<int, int>>& b) {
        n = b.size() + 1;
        p.resize(n);
        e.resize(n);
        d = l = r = p;
        for (auto l : b) {
            int x, y;
            tie(x, y) = l;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        p[0] = -1;
        int t = 0;
        dfs(0, t);
    }

    bool above(int x, int y) {
        return l[x] <= l[y] && r[y] <= r[x];
    }

    int size(int x) {
        return r[x] - l[x];
    }
};

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

struct euler_tour {
    struct edge { list<int>::iterator p, q; int u, v; };
    vector<list<int>> e;
    vector<edge> f;
    euler_tour(int n) : e(n) {}
    void add_edge(int x, int y) {
        int i = f.size();
        e[x].push_back(i);
        e[y].push_back(i);
        f.push_back({--e[x].end(), --e[y].end(), x, y});
    }

    list<int> dfs(int x) {
        list<int> q;
        while (e[x].size()) {
            auto& l = f[e[x].back()];
            q.push_back(x);
            x ^= l.u ^ l.v;
            e[l.u].erase(l.p);
            e[l.v].erase(l.q);
        }
        for (auto it = q.begin(); it != q.end(); ++it) q.splice(it, dfs(*it));
        return q;
    }

    vector<int> operator()(int x) {
        auto q = dfs(x);
        return vector<int>(begin(q), end(q));
    }
};

int n, m;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;

    union_find d(n);
    vector<pair<int, int>> b;
    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (!d(x, y)) {
            d.join(x, y);
            b.emplace_back(x, y);
        }
    }

    tree_topology tt(b);

    int q;
    cin >> q;
    vector<pair<int, int>> up(q);
    vector<vector<int>> sols(q);
    map<pair<int, int>, vector<int>> mp;
    vector deg(n, 0);
    for (int i : ra(0, q)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        up[i] = {x, y};
        deg[x]++;
        deg[y]++;
        mp[minmax(x, y)].push_back(i);
    }

    int k = R::count(deg, 1, [](int x) { return x % 2; });
    if (k) {
        cout << "NO\n" << k/2 << '\n';
        return 0;
    }

    euler_tour et(n);
    for (auto [x, y] : up) {
        et.add_edge(x, y);
    }

    auto go = [&](int x, int y) {
        int x0 = x;
        auto& id = mp[minmax(x, y)];
        int i = id.back();
        id.pop_back();

        vector<int> walk = {x};
        while (!tt.above(x, y)) {
            x = tt.p[x];
            walk.push_back(x);
        }

        vector<int> desc;
        while (x != y) {
            desc.push_back(y);
            y = tt.p[y];
        }

        R::copy(walk, back_inserter(sols[i]));
        R::copy(R::reverse_view(desc), back_inserter(sols[i]));

        if (up[i].second == x0) {
            R::reverse(sols[i]);
        }

        return false;
    };

    for (int i : ra(0, n)) {
        auto v = et(i);
        if (v.empty()) continue;
        v.push_back(v[0]);
        R::adjacent_find(v, go);
    }

    cout << "YES\n";
    for (int i : ra(0, q)) {
        cout << sols[i].size() << '\n';
        for (int x : sols[i]) cout << x+1 << ' ';
        cout << '\n';
    }
}