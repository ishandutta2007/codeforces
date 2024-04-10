#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const bool HARD = true;

using i64 = long long;

const char col[] = "wygbro";
const int mod = 1e9 + 7;

struct DP {
    int va[6];

    DP() { memset(va, 0, sizeof(va)); }
};

DP operator + (DP a, DP b) {
    DP ans;
    rep(c, 6) {
        rep(ca, 6) rep(cb, 6) {
            if (ca != c && ca != (c ^ 1) && cb != c && cb != (c ^ 1)) {
                ans.va[c] = (ans.va[c] + 1LL * a.va[ca] * b.va[cb]) % mod;
            }
        }
    }
    return ans;
}

DP proc(DP a, int lim) {
    DP ans = a;
    rep(c, 6) if (c != lim) {
        ans.va[c] = 0;
    }
    return ans;
}

std::set <i64> nodes;
std::map <i64, int> limits;
DP dpn[60];

i64 bound;

DP dfs(i64 u) {
    if (nodes.find(u) != nodes.end()) {
        DP ans;
        if (u < bound) ans = dfs(u << 1) + dfs(u << 1 | 1);
        else rep(c, 6) ans.va[c] = 1;
        if (limits.find(u) != limits.end())
            ans = proc(ans, limits[u]);
        return ans;
    } else {
        int lvl = 0;
        for (i64 x = u; x < bound; x <<= 1, ++ lvl);
        return dpn[lvl];
    }
}

inline void insert(i64 u) {
    nodes.insert(u);
}

void Main() {
    int K;
    scanf("%d", &K);
    bound = 1LL << (K - 1);
    nodes.clear();
    limits.clear();
    insert(1);
    if (HARD) {
        int n;
        scanf("%d", &n);
        rep(i, n) {
            i64 u;
            char s[15];
            scanf("%lld %s", &u, s);
            limits[u] = strchr(col, s[0]) - col;
            for (; u > 1; u >>= 1) insert(u);
        }
    }
    rep(c, 6) dpn[0].va[c] = 1;
    rep(i, K) if (i) dpn[i] = dpn[i - 1] + dpn[i - 1];
    DP ans = dfs(1);
    int sum = 0;
    rep(c, 6) sum = (sum + ans.va[c]) % mod;
    printf("%d\n", sum);
}

int main() {
    int T; T = 1;
    while (T --) Main();
    return 0;
}