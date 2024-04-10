#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1e9 + 7;

inline int qpow(int x, int n) {
    int ans = 1;
    for (; n; n >>= 1, x = 1LL * x * x % mod)
        if (n & 1) ans = 1LL * ans * x % mod;
    return ans;
}

int n_s, n_t, tot_s, tot_t;
std::vector <int> adj_s[2005], adj_t[35];
int fac[35], ifac[35];

namespace FindG_T {
    int sz[35];
    int mn, mnu;

    void dfs(int u, int p) {
        int mx = 0;
        sz[u] = 1;
        for (int v : adj_t[u]) {
            if (v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
            mx = std::max(mx, sz[v]);
        }
        mx = std::max(mx, tot_t - sz[u]);
        if (mx < mn) mn = mx, mnu = u;
    }

    int find_g_t() {
        mn = tot_t, mnu = -1;
        dfs(0, -1);
        return mnu;
    }
}

int cnt_hsh;
std::map <std::vector <int>, int> map_hsh;
int id_hsh[35];

std::map <std::pair <int, int>, int> rem;

int solve(int u_s, int p_s, int u_t, int p_t) {
    int id_s = u_s * (tot_s + 1) + p_s + 1, id_t = u_t * (tot_t + 1) + p_t + 1;
    if (rem.find({id_s, id_t}) != rem.end()) return rem[{id_s, id_t}];
    int &ans = rem[{id_s, id_t}];
    std::vector <int> son_s, son_t;
    for (int v : adj_s[u_s]) if (v != p_s) son_s.push_back(v);
    for (int v : adj_t[u_t]) if (v != p_t) son_t.push_back(v);
    std::vector <std::vector <int> > ways(son_s.size());
    rep(i, son_s.size()) {
        int v_s = son_s[i];
        for (int v_t : son_t) {
            ways[i].push_back(solve(v_s, u_s, v_t, u_t));
        }
    }
    static int dp[1 << 12];
    rep(mask, 1 << son_t.size()) dp[mask] = 0;
    dp[0] = 1;
    rep(i, son_s.size()) {
        bool have = false;
        rep(j, son_t.size()) have |= ways[i][j];
        if (have) {
            static int ndp[1 << 12];
            rep(mask, 1 << son_t.size()) ndp[mask] = dp[mask];
            rep(j, son_t.size()) if (ways[i][j])
                rep(mask, 1 << son_t.size()) if (!(mask >> j & 1))
                    ndp[mask | 1 << j] = (ndp[mask | 1 << j] + 1LL * dp[mask] * ways[i][j]) % mod;
            rep(mask, 1 << son_t.size()) dp[mask] = ndp[mask];
        }
    }
    return ans = dp[(1 << son_t.size()) - 1];
}

int calc_iso_t(int u, int p) {
    int ans = 1;
    std::vector <int> vec;
    std::map <int, int> cnt;
    for (int v : adj_t[u]) {
        if (v == p) continue;
        ans = 1LL * ans * calc_iso_t(v, u) % mod;
        vec.push_back(id_hsh[v]);
        cnt[id_hsh[v]] += 1;
    }
    for (auto pr : cnt) ans = 1LL * ans * fac[pr.second] % mod;
    vec.push_back(0);
    std::sort(vec.begin(), vec.end());
    if (map_hsh.find(vec) == map_hsh.end()) map_hsh[vec] = ++ cnt_hsh;
    id_hsh[u] = map_hsh[vec];
    return ans;
}

int main() {
    rep(i, 35) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
    ifac[35 - 1] = qpow(fac[35 - 1], mod - 2);
    for (int i = 35 - 1; i; -- i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
    scanf("%d", &n_s), tot_s = n_s;
    rep(i, n_s - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        adj_s[u].push_back(tot_s), adj_s[tot_s].push_back(u);
        adj_s[v].push_back(tot_s), adj_s[tot_s].push_back(v);
        ++ tot_s;
    }
    scanf("%d", &n_t), tot_t = n_t;
    rep(i, n_t - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        adj_t[u].push_back(tot_t), adj_t[tot_t].push_back(u);
        adj_t[v].push_back(tot_t), adj_t[tot_t].push_back(v);
        ++ tot_t;
    }
    int g_t = FindG_T::find_g_t();
    int ans = 0;
    rep(i, tot_s) {
        if ((i < n_s) != (g_t < n_t)) continue;
        ans = (ans + solve(i, -1, g_t, -1)) % mod;
    }
    int iso = calc_iso_t(g_t, -1);
    ans = 1LL * ans * qpow(iso, mod - 2) % mod;
    printf("%d\n", ans);
    return 0;
}