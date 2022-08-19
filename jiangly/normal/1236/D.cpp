#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int mx = 1, Mx = n - 1, my = 0, My = m - 1;
    LL res = 1LL * n * m - k, cnt = 1;
    vector<vector<int>> r(n), c(m);
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        r[x].push_back(y);
        c[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        r[i].push_back(-1);
        r[i].push_back(m);
    }
    for (int i = 0; i < m; ++i) {
        c[i].push_back(-1);
        c[i].push_back(n);
    }
    for (int i = 0; i < n; ++i)
        sort(r[i].begin(), r[i].end());
    for (int i = 0; i < m; ++i)
        sort(c[i].begin(), c[i].end());
    int x = 0, y = 0;
    while (true) {
        int t = min(My, *upper_bound(r[x].begin(), r[x].end(), y) - 1);
        if ((x != 0 || y != 0) && t == y)
            break;
        cnt += t - y;
        y = t;
        My = t - 1;
        t = min(Mx, *upper_bound(c[y].begin(), c[y].end(), x) - 1);
        if (t == x)
            break;
        cnt += t - x;
        x = t;
        Mx = t - 1;
        t = max(my, *--lower_bound(r[x].begin(), r[x].end(), y) + 1);
        if (t == y)
            break;
        cnt += y - t;
        y = t;
        my = t + 1;
        t = max(mx, *--lower_bound(c[y].begin(), c[y].end(), x) + 1);
        if (t == x)
            break;
        cnt += x - t;
        x = t;
        mx = t + 1;
    }
    if (cnt == res)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    return 0;
}