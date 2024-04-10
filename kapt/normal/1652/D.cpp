#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5 + 100, MOD = 998244353;
vector<array<int, 3>> g[MAXN];
int cnt[MAXN], ans[MAXN];

int sum = 0, val = 1;

int inv(int x) {
    int n = MOD - 2, res= 1;
    while (n){
        if (n % 2 == 0) {
            n /= 2;
            x = (x * x) % MOD;
        } else {
            res = (res * x) % MOD;
            n--;
        }
    }
    return res;
}

int binpow(int x, int n) {
    int res = 1;
    while(n){
        if (n % 2 == 0) {
            x= (x * x) % MOD;
            n /= 2;
        } else {
            res = (res * x) % MOD;
            n--;
        }
    }
    return res;
}
vector<int> factor[MAXN];

void dfs(int v, int p = -1) {
    sum += val;
    sum %=MOD;
    int val1 = val;
    for (auto e : g[v]) {
        int u = e[0], x = e[1], y= e[2];
        if (u == p) continue;
        val = (val * y) % MOD;
        val = (val * inv(x)) % MOD;
        for (int i : factor[y]) {
            cnt[i]--;
        }
        for (int i : factor[x]) {
            cnt[i]++;
            ans[i] = max(ans[i], cnt[i]);
        }
        dfs(u, v);
        val = val1;
        for (int i :factor[y]) {
            cnt[i]++;
        }
        for (int i :factor[x]) {
            cnt[i]--;
        }
    }
}


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin>> tst;
    for (int i = 1; i < MAXN; ++i) {
        int j = i;
        for (int k = 2; k * k <= j; ++k) {
            while (j % k == 0) {
                j /= k;
                factor[i].push_back(k);
            }
        }
        if (j != 1) {
            factor[i].push_back(j);
        }
    }
    while (tst--) {
        int n;
        cin >>n;
        for (int i = 0; i <=n; ++i) {
            g[i].clear();
            cnt[i] = 0; ans[i] = 0;
        }
        sum = 0; val = 1;
        for(int i = 0; i < n - 1; ++i) {
            int u, v, x, y;
            cin >> u >> v>> x >>y;
            u--; v--;
            g[u].push_back({v, x, y});
            g[v].push_back({u, y, x});
        }
        dfs(0);
        int res = sum;
        for (int i = 2;i <= n; ++i) {
            res = (res * binpow(i, ans[i])) % MOD;
        }
        cout<<res <<'\n';
    }
    return 0;
}