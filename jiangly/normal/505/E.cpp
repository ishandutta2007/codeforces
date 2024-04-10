#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX_N = 1E5, MAX_M = 5E3;
int n, m, k, p;
int h[MAX_N], a[MAX_N];
int c[MAX_M + 1];
bool check(LL x) {
    LL sum = 0;
    for (int i = 0; i < n; ++i)
        sum += max(0LL, (h[i] + 1LL * a[i] * m - x + p - 1) / p);
    if (sum > k * m)
        return false;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i) {
        int t = max(0LL, (h[i] + 1LL * a[i] * m - x + p - 1) / p);
        for (int j = 0; j < t; ++j)
            ++c[min(1LL * m, (x + 1LL * p * j) / a[i])];
    }
    if (c[0] > 0)
        return false;
    for (int i = 1; i <= m; ++i) {
        c[i] += c[i - 1];
        if (c[i] > i * k)
            return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; ++i)
        cin >> h[i] >> a[i];
    LL l = 1, r = 1E13;
    while (l < r) {
        LL x = (l + r) / 2;
        if (check(x))
            r = x;
        else
            l = x + 1;
    }
    cout << l << "\n";
    return 0;
}