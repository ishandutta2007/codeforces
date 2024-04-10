#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int64 k;
    cin >> n >> k;
    if (k < 1LL * n * (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) a[i] = n - i;
    for (int i = 0; i < n; ++i) b[i] = n - i / 2;
    k -= 1LL * n * (n + 1) / 2;
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int t = min(k, int64(b[i] - a[i]));
        c[i] = a[i] + t;
        k -= t;
        ans += c[i];
    }
    cout << ans << "\n";
    vector<int> p(n), q(n);
    vector<bool> u(n), v(n);
    for (int i = 0; i < n; ++i)
        if (i % 2 == 0) {
            p[i] = c[i];
            u[p[i] - 1] = true;
        } else {
            q[i] = c[i];
            v[q[i] - 1] = true;
        }
    for (int i = 0, j = n - 1; i < n; ++i) {
        if (p[i] != 0) continue;
        while (u[j]) --j;
        p[i] = j + 1, --j;
    }
    for (int i = 0, j = n - 1; i < n; ++i) {
        if (q[i] != 0) continue;
        while (v[j]) --j;
        q[i] = j + 1, --j;
    }
    for (int i = 0; i < n; ++i) cout << p[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i) cout << q[i] << " \n"[i == n - 1];
    return 0;
}