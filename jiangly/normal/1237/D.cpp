#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto [mn, mx] = minmax_element(a.begin(), a.end());
    if (2 * *mn >= *mx) {
        for (int i = 1; i <= n; ++i) cout << -1 << " \n"[i == n];
        return 0;
    }
    a.insert(a.end(), a.begin(), a.end());
    vector<int> r(n), stk;
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (i < n) {
            int x = -1, y = stk.size() - 1;
            while (x < y) {
                int mid = (x + y + 1) / 2;
                if (2 * a[stk[mid]] < a[i])
                    x = mid;
                else
                    y = mid - 1;
            }
            if (x == -1)
                r[i] = -1;
            else
                r[i] = stk[x] - i;
        }
        while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
        stk.push_back(i);
    }
    int m = 1E9;
    for (int i = n - 1; i >= 0; --i)
        if (r[i] != -1)
            m = min(m, i + n + r[i]);
    vector<int> t(n);
    for (int i = n - 1; i >= 0; --i) {
        if (r[i] != -1)
            m = min(m, i + r[i]);
        t[i] = m - i;
    }
    for (int i = 0; i < n; ++i) cout << t[i] << " \n"[i == n - 1];
    return 0;
}