#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    vector<vector<int>> a(n);
    for (int i = 0; i < c; ++i) {
        int x, y;
        cin >> x >> y;
        a[--x].push_back(y);
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> l(m + 2), r(m + 2), cnt(m + 2), to(m + 2);
        for (int x = i; x < n; ++x)
            for (int y : a[x])
                ++cnt[y];
        int last = 0;
        for (int j = 1; j <= m; ++j) {
            if (cnt[j] > 0) {
                l[j] = last;
                r[last] = j;
                last = j;
            }
        }
        r[last] = m + 1;
        l[m + 1] = last;
        LL res = 0;
        for (int i = r[0], j = 0, s = 0; i <= m; i = r[i]) {
            while (j <= m && s < k) {
                j = r[j];
                s += cnt[j];
            }
            res += (i - l[i]) * (m + 1 - j);
            to[i] = j;
            s -= cnt[i];
        }
        auto remove = [&](int x) {
            int i = x;
            while (l[i] > 0 && to[l[i]] >= x)
                i = l[i];
            --cnt[x];
            for (int j = l[i], s = 0; i <= x; i = r[i]) {
                while (j <= m && s < k) {
                    j = r[j];
                    s += cnt[j];
                }
                res -= (i - l[i]) * (j - to[i]);
                to[i] = j;
                s -= cnt[i];
            }
            if (cnt[x] == 0) {
                l[r[x]] = l[x];
                r[l[x]] = r[x];
            }
        };
        for (int d = n - 1; d >= i; --d) {
            ans += res;
            for (int x : a[d])
                remove(x);
        }
    }
    cout << ans << endl;
    return 0;
}