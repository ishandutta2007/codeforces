#include <bits/stdc++.h>

using namespace std;

const int N = 300333;
const int I = 1000111222;
const int L = 19;

int n, m, curt;
int used[N], sz[N], tin[N], tout[N], val[N];
int p[L][N];

long long ans;

vector<int> g[N];

void calc_sz(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p || used[to]) {
            continue;
        }
        calc_sz(to, v);
        sz[v] += sz[to];
    }
}

int get_root(int v) {
    int tot = sz[v], p = -1;
    while (true) {
        int nxt = -1;
        for (int to : g[v]) {
            if (to == p || used[to]) {
                continue;
            }
            if (2 * sz[to] > tot) {
                nxt = to;
                break;
            }
        }
        if (nxt == -1) {
            return v;
        }
        p = v;
        v = nxt;
    }
}

void calc_p(int v) {
    for (int lev = 1; lev < L; ++lev) {
        p[lev][v] = p[lev - 1][p[lev - 1][v]];
    }
}

void dfs(int v) {
    val[v] = 0;
    tin[v] = ++curt;
    for (int to : g[v]) {
        if (to == p[0][v] || used[to]) {
            continue;
        }
        p[0][to] = v;
        calc_p(to);
        dfs(to);
    }
    tout[v] = curt;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    for (int i = L - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][u], v)) {
            u = p[i][u];
        }
    }
    return p[0][u];
}

int get_v_before_lca(int v, int lc) {
    if (v == lc) {
        return -1;
    }
    for (int i = L - 1; i >= 0; --i) {
        if (!is_ancestor(p[i][v], lc)) {
            v = p[i][v];
        }
    }
    return v;
}

void push_vals(int v) {
    for (int to : g[v]) {
        if (to == p[0][v] || used[to]) {
            continue;
        }
        val[to] += val[v];
        push_vals(to);
    }
}

int cnt[3 * N];

void proc(vector<pair<int, int>> &v) {
    for (const auto &p : v) {
        cnt[p.first] = 0;
        cnt[p.second] = 0;
    }
    for (const auto &p : v) 
        ++cnt[p.first],
        ++cnt[p.second];
    sort(v.begin(), v.end());
    long long tot = 0;
    for (int i = 0; i < v.size(); ) {
        int pos = i;
        while (i < v.size() && v[i] == v[pos]) 
            ++i;
        for (int j = pos; j < i; ++j) {
            int add = v.size();
            add -= cnt[v[j].first];
            add -= cnt[v[j].second];
            add += (i - pos);
            tot += add;
        }
    }
    assert(tot % 2 == 0);
    tot /= 2;
    ans += tot;
}

void solve(int root, const vector<pair<int, int>> &paths) {
    calc_sz(root, root);
    root = get_root(root);
    p[0][root] = root;
    calc_p(root);
    curt = -1;
    dfs(root);
    int num = n;
    vector<pair<int, int>> v;
    vector<int> lcs;
    for (auto p : paths) {
        int lc = lca(p.first, p.second);
        int v1 = get_v_before_lca(p.first, lc);
        int v2 = get_v_before_lca(p.second, lc);
        lcs.push_back(lc);
        if (lc == root) {
            if (v1 == -1) {
                v1 = ++num;
            }
            if (v2 == -1) {
                v2 = ++num;
            }
            if (v1 > v2) {
                swap(v1, v2);
            }
            v.push_back({v1, v2});
        } else {
            ++val[lc];
            if (v1 != -1) {
                --val[v1];
            }
            if (v2 != -1) {
                --val[v2];
            }
        }
    }
    proc(v);
    push_vals(root);
    vector<pair<int, pair<int, int>>> npaths;
    for (int i = 0; i < lcs.size(); ++i) {
        int lc = lcs[i], v1 = paths[i].first, v2 = paths[i].second;
        if (lc == root) {
            if (v1 != root) {
                ans += val[v1];
            }
            if (v2 != root) {
                ans += val[v2];
            }
        } else {
            int nxt = get_v_before_lca(lc, root);
            npaths.push_back({nxt, paths[i]});
        }
    }
    used[root] = 1;
    sort(npaths.begin(), npaths.end());
    for (int i = 0; i < npaths.size(); ) {
        int pos = i;
        while (i < npaths.size() && npaths[pos].first == npaths[i].first) {
            ++i;
        }
        vector<pair<int, int>> ps(i - pos);
        for (int j = pos; j < i; ++j) {
            ps[j - pos] = npaths[j].second;
        }
        solve(npaths[pos].first, ps);
    }
}

const bool debug = 0;

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

int main() {
    if (debug) {
        n = 300000;
    } else {
        scanf("%d", &n);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        if (debug) {
            //u = i - 1;
            u = rnd(i);
            v = i;
        } else {
            scanf("%d%d", &u, &v);
            --u;
            --v;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (debug) {
        m = 300000;
    } else {
        scanf("%d", &m);
    }
    vector<pair<int, int>> paths(m);
    for (auto &p : paths) {
        if (debug) {
            p.first = rnd(n);
            p.second = rnd(n);
        } else {
            scanf("%d%d", &p.first, &p.second);
            --p.first;
            --p.second;
        }
    }
    solve(0, paths);
    printf("%lld\n", ans);
    return 0;
}