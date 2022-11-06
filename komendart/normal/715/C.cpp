#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

int power[maxn];
int inv[maxn];

int n, M;
vector< pair<int, int> > graph[maxn];
int ans = 0;
char used[maxn];
int size[maxn];

void dfs_size(int v, int p=-1) {
    size[v] = 1;
    for (auto e: graph[v]) {
        int u = e.first;
        if (!used[u] && u != p) {
            dfs_size(u, v);
            size[v] += size[u];
        }
    }
}

void dfs_centroid(int v, int p, int k, int &ans) {
    for (auto e: graph[v]) {
        int u = e.first;
        if (!used[u] && u != p) {
            dfs_centroid(u, v, k, ans);
        }
    }
    bool flag = 2 * (k - size[v]) <= k;
    for (auto e: graph[v]) {
        int u = e.first;
        if (!used[u] && u != p) {
            flag &= 2 * size[u] <= k;
        }
    }
    if (flag) ans = v;
}

void dfs1(int v, int p, int h, int mod, unordered_map<int, int> &d, bool flag) {
    mod %= M;
    if (mod < 0) mod += M;
    if (flag) d[mod]++;
    else d[mod]--;
    for (auto e: graph[v]) {
        int u = e.first, digit = e.second;
        if (!used[u] && u != p) {
            dfs1(u, v, h + 1, mod + power[h] * digit, d, flag);
        }
    }
}

void dfs2(int v, int p, int h, int mod, unordered_map<int, int> &d) {
    mod = mod % M;
    int tmp = (-mod * inv[h]) % M;
    if (tmp < 0) tmp += M;
    ans += d[tmp];
    for (auto e: graph[v]) {
        int u = e.first, digit = e.second;
        if (!used[u] && u != p) {
            dfs2(u, v, h + 1, mod * 10 + digit, d);
        }
    }
}

void dfs3(int v, int p, int h, int mod) {
    mod %= M;
    if (mod == 0) ans++;
    for (auto e: graph[v]) {
        int u = e.first, digit = e.second;
        if (!used[u] && u != p) {
            dfs3(u, v, h + 1, mod + power[h] * digit);
        }
    }
}

void solve(int v) {
    dfs_size(v);
    int k = size[v];
    int centroid = -1;
    dfs_centroid(v, -1, k, centroid);
    v = centroid;
    used[v] = true;

    unordered_map<int, int> d;
    d[0] = 1;
    for (auto e: graph[v]) {
        int u = e.first, digit = e.second;
        if (!used[u]) {
            dfs1(u, -1, 1, digit, d, true);
        }
    }
    for (auto e: graph[v]) {
        int u = e.first, digit = e.second;
        if (!used[u]) {
            dfs1(u, -1, 1, digit, d, false);
            dfs2(u, -1, 1, digit, d);
            dfs1(u, -1, 1, digit, d, true);
            dfs3(u, -1, 1, digit);
        }
    }

    for (auto e: graph[v]) {
        if (!used[e.first]) {
            solve(e.first);
        }
    }
}

int getpow(int a, int k) {
    if (k == 0) return 1;
    if (k & 1) return getpow(a, k - 1) * a % M;
    return getpow(a * a % M, k / 2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> M;
    for (int i = 0; i < n - 1; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }

    int phi = M;
    int t = M;
    for (int i = 2; i * i <= n; i++) {
        if (t % i != 0) continue;
        phi /= i; phi *= (i - 1);
        while (t % i == 0) t /= i;
    }
    if (t > 1) phi /= t, phi *= (t - 1);
    power[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        power[i] = power[i - 1] * 10 % M;
        inv[i] = getpow(power[i], phi - 1);
    }

    solve(0);
    cout << ans << '\n';
}