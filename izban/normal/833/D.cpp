#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17;
const int MOD = 1000 * 1000 * 1000 + 7;

int bin(int a, ll n) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return bin(x, MOD - 2);
}

int n;
vector<pair<int, pair<int, int> > > e[N];
int level[N];
int sz[N];

int ans;

void dfs1(int v, int pr) {
    sz[v] = 1;
    for (auto o : e[v]) {
        int to = o.first;
        if (to == pr) continue;
        dfs1(to, v);
        ans = 1LL * ans * bin(o.second.first, 1LL * sz[to] * (n - sz[to])) % MOD;
        sz[v] += sz[to];
    }
}

void dfs2(int v, int pr) {
    sz[v] = 1;
    for (auto o : e[v]) {
        int to = o.first;
        if (to == pr) continue;
        if (level[to] != -1) continue;
        dfs2(to, v);
        sz[v] += sz[to];
    }
}

struct fenwick {
    int n;
    vector<int> f;

    fenwick(){}
    fenwick(int _n) {
        n = _n;
        f.assign(n, 1);
    }

    void mul(int x, int y) {
        for (; x < n; x |= x + 1) {
            f[x] = 1LL * f[x] * y % MOD;
        }
    }

    int get(int x) {
        int res = 1;
        for (; x >= 0; x = (x & (x + 1)) - 1) res = 1LL * res * f[x] % MOD;
        return res;
    }
};

struct fenwick2 {
    int n;
    vector<int> f;

    fenwick2(){}
    fenwick2(int _n) {
        n = _n;
        f.assign(n, 0);
    }

    void add(int x, int y) {
        for (; x < n; x |= x + 1) {
            f[x] += y;
        }
    }

    int get(int x) {
        int res = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
        return res;
    }
};

fenwick f;
fenwick2 f2;
vector<int> vct;

//template<typename T>
void dfs3(int v, int pr, int prod, int bal, const function<void(int, int)> &func) {
//void dfs3(int v, int pr, int prod, int bal, T &func) {
    //vct.push_back(bal);
    func(prod, bal);
    for (auto o : e[v]) {
        int to = o.first;
        if (to == pr || level[to] != -1) continue;
        dfs3(to, v, 1LL * prod * o.second.first % MOD, bal + o.second.second, func);
    }
}

void centroid(int v, int h) {
    dfs2(v, -1);
    int pr = -1;
    int all = sz[v];
    while (1) {
        bool f = 0;
        for (auto o : e[v]) {
            int to = o.first;
            if (level[to] != -1) continue;
            if (sz[to] * 2 >= all && to != pr) {
                pr = v;
                v = to;
                f = 1;
                break;
            }
        }
        if (!f) break;
    }
    level[v] = h;
    vct.clear();
    dfs3(v, -1, 1, 0, [&](int prod, int bal) {
        vct.push_back(bal);
    });
    sort(vct.begin(), vct.end());
    vct.resize(unique(vct.begin(), vct.end()) - vct.begin());
    f = fenwick(vct.size());
    f2 = fenwick2(vct.size());
    f2.add(lower_bound(vct.begin(), vct.end(), 0) - vct.begin(), 1);
    for (auto o : e[v]) {
        int to = o.first;
        if (level[to] != -1) continue;
        dfs3(to, -1, o.second.first, o.second.second, [&](int prod, int bal) {
            int id = lower_bound(vct.begin(), vct.end(), -bal) - vct.begin() - 1;
            int cur = f.get(id);
            int cnt = f2.get(id);
            ans = 1LL * ans * cur % MOD;
            ans = 1LL * ans * bin(prod, cnt) % MOD;
        });
        dfs3(to, -1, o.second.first, o.second.second, [&](int prod, int bal) {
            int id = lower_bound(vct.begin(), vct.end(), bal) - vct.begin();
            f.mul(id, prod);
            f2.add(id, 1);
        });
    }
    for (auto o : e[v]) {
        int to = o.first;
        if (level[to] != -1) continue;
        centroid(to, h + 1);
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v, x, c;
            scanf("%d%d%d%d", &u, &v, &x, &c);
            --u; --v;
            e[u].push_back({v, {x, c}});
            e[v].push_back({u, {x, c}});
        }
        ans = 1;
        dfs1(0, -1);

        for (int i = 0; i < n; i++) {
            for (auto &o : e[i]) {
                o.second.first = inv(o.second.first);
                if (o.second.second == 1) o.second.second = -1;
                else o.second.second = 2;
            }
        }

        for (int it = 0; it < 2; it++) {
            for (int i = 0; i < n; i++) {
                level[i] = -1;
            }
            centroid(0, 0);

            for (int i = 0; i < n; i++) {
                for (auto &o : e[i]) {
                    if (o.second.second == 2) o.second.second = -1;
                    else o.second.second = 2;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}