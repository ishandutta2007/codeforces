#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const long long INF = 1000000000000000001;

bool used[N];

int fa[N], a[N];

long long g[N + 1], f[N + 1];

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

void merge(int x, int y) { fa[find(y)] = find(x); }

long long mul(long long a, long long b) {
    if (1.0 * a * b > 2E18) return INF;
    return min(INF, a * b);
}

long long sum(long long a, long long b) { return min(INF, a + b); }

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    if (k > f[n]) {
        cout << -1 << "\n";
        return;
    }
    iota(fa, fa + n, 0);
    fill(used, used + n, false);
    --k;
    for (int i = 0; i < n;) {
        int j = 1;
        while (mul(g[j], f[n - i - j]) <= k) {
            k -= g[j] * f[n - i - j];
            ++j;
        }
        long long x = k / f[n - i - j];
        a[i] = i + j - 1;
        used[a[i]] = true;
        merge(i, a[i]);
        if (j > 1) {
            for (int l = i + 1; l < i + j - 1; ++l) {
                for (int v = i; v < i + j; ++v) {
                    if (used[v] || find(v) == find(l)) continue;
                    if (g[j - l + i] <= x) {
                        x -= g[j - l + i];
                        continue;
                    }
                    a[l] = v;
                    used[v] = true;
                    merge(l, v);
                    break;
                }
            }
            for (int v = i; v < i + j; ++v) {
                if (!used[v]) a[i + j - 1] = v;
            }
        }
        i += j;
        k %= f[n - i];
    }
    for (int i = 0; i < n; ++i) cout << a[i] + 1 << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    g[1] = g[2] = 1;
    for (int i = 3; i <= N; ++i) g[i] = mul(g[i - 1], i - 2);
    f[0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j) f[i] = sum(f[i], mul(f[i - j], g[j]));
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}