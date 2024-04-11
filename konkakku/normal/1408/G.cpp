#include <bits/stdc++.h>
#define lg(x) (x == 0 ? -1 : __lg(x))
using namespace std;

const int N = 1505;
const int MOD = 998244353, G = 3, LG = 24;;

int n, a[N][N], c[N][N], ans[N];
int cnt = 0, ed = 0, err[2], pos[N];
vector<pair<int, int>> adj[N];
vector<array<int, 3>> ve;
long long rt[LG + 1];
 
long long pw(long long u, int p) {
    long long ret = 1;
    for (int i = lg(p); i >= 0; i--) {
        (ret *= ret) %= MOD;
        if (p >> i & 1) {
            (ret *= u) %= MOD;
        }
    }
    return ret;
}

struct polynomial {
    vector<long long> f;
 
    polynomial(int _sz = 0) {
        f = vector<long long>(_sz, 0);
    }
 
    int reverse_bit(int u, int lg) {
        int ans = 0;
        for (int i = 0; i < lg; i++) {
            (ans <<= 1) ^= (u >> i & 1);
        }
        return ans;
    }
 
    polynomial ntt(int lg, bool inv = false) {
        if (inv) {
            reverse(f.begin() + 1, f.end());
        }
        int mx = (1 << lg);
        polynomial ans(mx);
        for (int i = 0; i < f.size(); i++) {
            ans.f[reverse_bit(i, lg)] = f[i];
        }
        for (int len = 1; len < mx; len += len) {
            long long r = rt[__lg(len) + 1];
            for (int i = 0; i < mx; i += 2 * len) {
                long long w = 1;
                for (int j = 0; j < len; j++) {
                    long long u = ans.f[i + j], v = ans.f[i + j + len];
                    ans.f[i + j] = (u + v * w) % MOD;
                    ans.f[i + j + len] = (u - v * w) % MOD;
                    (w *= r) %= MOD;
                }
            }
        }
        if (inv) {
            reverse(f.begin() + 1, f.end());
            long long iv = pw(1LL * mx, MOD - 2);
            for (long long &v : ans.f) {
                (v *= iv) %= MOD;
            }
        }
        return ans;
    }
 
    polynomial operator*(polynomial oth) {
        int a = (int)f.size() - 1;
        int b = (int)oth.f.size() - 1;
        int lg = __lg(a + b) + 1;
        polynomial fa = ntt(lg), fb = oth.ntt(lg);
        polynomial ans(1 << lg);
        for (int i = 0; i < 1 << lg; i++) {
            ans.f[i] = fa.f[i] * fb.f[i] % MOD;
        }
        ans = ans.ntt(lg, true);
        ans.f.resize(a + b + 1);
        return ans;
    }
 
    bool operator>(const polynomial& oth) const {
        return f.size() > oth.f.size();
    }
};

struct component {
    int in, cnt = 0;
    vector<int> mem;
    polynomial cur;

    void clear() {
        in = -1; mem.clear();
        cur.f = {};
    }

    bool valid() {
        int mx = MOD;
        for (int u : mem) {
            while (!adj[u].empty() && pos[u] == pos[adj[u].back().second]) {
                adj[u].pop_back();
            }
            if (!adj[u].empty()) {
                mx = min(mx, adj[u].back().first);
            }
        }
        return in < mx;
    }

    int size() {
        return mem.size();
    }
} com[N];

void init() {
    rt[LG - 1] = pw(G, (MOD - 1) / (1LL << (LG - 1)));
    for (int i = LG - 2; i >= 0; i--) {
        rt[i] = (rt[i + 1] * rt[i + 1]) % MOD;
    }
}

void update(component& com, int coe) {
    bool typ = (com.size() == 2);
    err[typ] += ((int)(!com.valid()) * coe);
    cnt += typ * coe;
}

void connect(int u, int v) {
    if ((u = pos[u]) == (v = pos[v])) {
        return;
    }
    if (com[u].size() < com[v].size()) {
        swap(u, v);
    }
    com[u].in = max(com[u].in, com[v].in);
    for (int x : com[u].mem) {
        for (int y : com[v].mem) {
            com[u].in = max(com[u].in, a[x][y]);
        }
    }
    for (int y : com[v].mem) {
        com[u].mem.push_back(y);
        pos[y] = u;
    }
    com[u].cur = com[u].cur * com[v].cur;
    com[v].clear();
    if (com[u].valid()) {
        com[u].cur.f[1]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pos[i] = i;
        com[i].in = -1;
        com[i].mem.push_back(i);
        com[i].cur.f = {0, 1};
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (j != i) {
                adj[i].push_back({a[i][j], j});
                ve.push_back({a[i][j], i, j});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<pair<int, int>>());
    }
    sort(ve.begin(), ve.end());
    for (auto [_, u, v] : ve) {
        connect(u, v);
    }
    polynomial ans;
    ans.f = {1};
    for (int i = 1; i <= n; i++) {
        if (!com[i].mem.empty()) {
            ans = ans * com[i].cur;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (ans.f[i] + MOD) % MOD << " ";
    }
    
}