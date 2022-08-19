#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[--x] = --y;
    }
    vector<int> lmax(n), rmax(n), lmin(n), rmin(n), cnt(2 * n);
    function<LL(int, int)> solve = [&](int l, int r) {
        if (r - l == 1)
            return 1LL;
        int m = (l + r) / 2;
        LL result = solve(l, m) + solve(m, r);
        lmin[m - 1] = lmax[m - 1] = a[m - 1];
        for (int i = m - 2; i >= l; --i) {
            lmin[i] = min(lmin[i + 1], a[i]);
            lmax[i] = max(lmax[i + 1], a[i]);
        }
        rmin[m] = rmax[m] = a[m];
        for (int i = m + 1; i < r; ++i) {
            rmin[i] = min(rmin[i - 1], a[i]);
            rmax[i] = max(rmax[i - 1], a[i]);
        }
        for (int x = l; x < m; ++x) {
            int y = x + lmax[x] - lmin[x];
            if (y >= m && y < r && rmax[y] < lmax[x] && rmin[y] > lmin[x])
                ++result;
        }
        for (int y = m; y < r; ++y) {
            int x = y - rmax[y] + rmin[y];
            if (x >= l && x < m && lmax[x] < rmax[y] && lmin[x] > rmin[y])
                ++result;
        }
        int s = m, t = m;
        for (int x = m - 1; x >= l; --x) {
            while (t < r && rmin[t] > lmin[x]) {
                ++cnt[t - rmax[t] + n];
                ++t;
            }
            while (s < t && rmax[s] < lmax[x]) {
                --cnt[s - rmax[s] + n];
                ++s;
            }
            result += cnt[x - lmin[x] + n];
        }
        while (s < t) {
            --cnt[s - rmax[s] + n];
            ++s;
        }
        s = t = m;
        for (int x = m - 1; x >= l; --x) {
            while (t < r && rmax[t] < lmax[x]) {
                ++cnt[t + rmin[t]];
                ++t;
            }
            while (s < t && rmin[s] > lmin[x]) {
                --cnt[s + rmin[s]];
                ++s;
            }
            result += cnt[x + lmax[x]];
        }
        while (s < t) {
            --cnt[s + rmin[s]];
            ++s;
        }
        return result;
    };
    cout << solve(0, n) << endl;
    return 0;
}