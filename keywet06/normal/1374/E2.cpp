#include <bits/stdc++.h>

const int N = 2e5;

int n, m, k;
int c[N], v[N], t[N], a[N], b[N];

long long s[N];

std::vector<int> p[N];

void add(int x, int y) {
    x = t[x];
    for (int i = x + 1; i <= n; i += i & -i) {
        c[i - 1] += y;
        s[i - 1] += y * v[x];
    }
}

long long get(int k) {
    int x = 0;
    for (int i = 1 << 17; i; i >>= 1)
        if (x + i <= n && k >= c[x + i - 1]) k -= c[(x += i) - 1];
    long long res = 0;
    for (int i = x; i; i = i & (i - 1)) res += s[i - 1];
    return res + 1ll * k * v[x];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) std::cin >> t[i] >> a[i] >> b[i];
    std::copy(t, t + n, v);
    std::sort(v, v + n);
    for (int i = 0; i < n; ++i) t[i] = std::lower_bound(v, v + n, t[i]) - v;
    for (int i = 0; i < n; ++i) p[a[i] | b[i] << 1].push_back(i);
    for (int i = 0; i < 4; ++i)
        std::sort(p[i].begin(), p[i].end(),
                  [&](int i, int j) { return t[i] < t[j]; });
    long long ans = -1;
    for (auto i : p[0]) add(i, 1);
    for (auto i : p[3]) add(i, 1);
    for (int i = k; i < int(p[1].size()); ++i) add(p[1][i], 1);
    for (int i = k; i < int(p[2].size()); ++i) add(p[2][i], 1);
    long long sum = 0, c = -1;
    for (int i = 0; i < std::min(k, int(p[1].size())); ++i)
        sum += v[t[p[1][i]]];
    for (int i = 0; i < std::min(k, int(p[2].size())); ++i)
        sum += v[t[p[2][i]]];
    for (int i = 0; i <= k && i <= int(p[3].size()); ++i) {
        if (i) {
            sum += v[t[p[3][i - 1]]];
            add(p[3][i - 1], -1);
            if (k - i < int(p[1].size())) {
                sum -= v[t[p[1][k - i]]];
                add(p[1][k - i], 1);
            }
            if (k - i < int(p[2].size())) {
                sum -= v[t[p[2][k - i]]];
                add(p[2][k - i], 1);
            }
        }
        if (k - i <= int(std::min(p[1].size(), p[2].size())) &&
            2 * k - i <= m) {
            long long res = sum + get(m - (2 * k - i));
            if (ans == -1 || ans > res) {
                ans = res;
                c = i;
            }
        }
    }
    std::cout << ans << "\n";
    if (ans == -1) return 0;
    std::vector<int> q;
    for (int i = 0; i < c; ++i) q.push_back(p[3][i]);
    for (int i = 0; i < k - c; ++i) {
        q.push_back(p[1][i]);
        q.push_back(p[2][i]);
    }
    std::vector<int> vis(n), pp(n);
    for (auto i : q) vis[i] = 1;
    std::iota(pp.begin(), pp.end(), 0);
    std::sort(pp.begin(), pp.end(), [&](int i, int j) { return t[i] < t[j]; });
    for (int i = 0; i < n; ++i)
        if (int(q.size()) < m && !vis[pp[i]]) q.push_back(pp[i]);
    for (int i = 0; i < m; ++i) std::cout << q[i] + 1 << " \n"[i == m - 1];
    return 0;
}