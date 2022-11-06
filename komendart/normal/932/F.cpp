#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

using ll = long long;

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct Hull : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (long double) (x->b - y->b)*(z->m - y->m) >= (long double) (y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

const int maxn = 1e5 + 5;

int n;
vector<int> graph[maxn];
int a[maxn];
int b[maxn];
int ans[maxn];
Hull hull[maxn];
set< pair<int, int> > lines[maxn];
int id[maxn];

int dfs1(int v, int p) {
    for (auto &to: graph[v]) {
        if (to == p) {
            swap(to, graph[v].back());
            break;
        }
    }
    if (v != 1) graph[v].pop_back();
    int k = 1;
    int best = 0;
    for (auto &to: graph[v]) {
        int tmp = dfs1(to, v);
        k += tmp;
        if (tmp > best) {
            best = tmp;
            swap(graph[v][0], to);
        }
    }
    return k;
}

void dfs2(int v) {
    if (graph[v].empty()) {
        ans[v] = 0;
        hull[v].insert_line(-b[v], -ans[v]);
        lines[v].insert({-b[v], -ans[v]});
        id[v] = v;
        return;
    }
    for (auto to: graph[v]) {
        dfs2(to);
    }
    id[v] = id[graph[v][0]];
    for (auto to: graph[v]) {
        if (to == graph[v][0]) continue;
        for (auto line: lines[id[to]]) {
            hull[id[v]].insert_line(line.first, line.second);
            lines[id[v]].insert(line);
        }
        //lines[id[to]].clear();
    }
    ans[v] = -hull[id[v]].eval(a[v]);
    hull[id[v]].insert_line(-b[v], -ans[v]);
    lines[id[v]].insert({-b[v], -ans[v]});
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}