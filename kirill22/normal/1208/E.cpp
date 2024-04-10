#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1e6 + 5, w;
    vector<int> log3(n, 0);
    int tmp = 2;
    for (int i = 1; i < n; i++) {
        if (i == tmp) {
            tmp *= 2;
            log3[i] = 1;
        }
        log3[i] += log3[i - 1];
    }
    cin >> n >> w;
    vector<pair<int, vector<int>>> a(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].first = k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i].second.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    vector<vector<vector<int>>> b(n);
    for (int l = 0; l < n; l++) {
        b[l].resize(a[l].first);
        vector<int> d(log3[a[l].first] + 5, 0);
        for (int i = 0; i < a[l].first; i++) {
            b[l][i] = d;
        }
        for (int i = 0; i < a[l].first; i++) {
            b[l][i][0] = a[l].second[i];
        }
        for (int k = 1; k <  log3[a[l].first] + 5; k++) {
            for (int i = 0; i + (1 << k) <= a[l].first; i++) {
                b[l][i][k] = max(b[l][i][k - 1], b[l][i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    vector<int> ans(w, 0);
    vector<int> ans2(n, 0);
    int x = 0, y = n, sum = 0;
    for (int i = 0; i < w; i++) {
        while (y > 0 && w - i < a[y - 1].first) {
            y--;
        }
        int X = n;
        for (int j = x; j < n; j++) {
            if (a[j].first > i + 1 && X == n) {
                X = j;
            }
            int r = i;
            int l = 0;
            if (y <= j) {
                l = a[j].first - w + i;
            }
            sum -= ans2[j];
            int s = log3[r - l + 1];
            int res = max(b[j][l][s], b[j][r - (1 << s) + 1][s]);
            if (a[j].first <= w - i - 1) {
                res = max(res, 0ll);
            }
            ans2[j] = res;
            sum += ans2[j];
        }
        for (int j = y; j < n; j++) {
            int r = min(i, a[j].first - 1);
            int l = a[j].first - w + i;
            sum -= ans2[j];
            int s = log3[r - l + 1];
            int res = max(b[j][l][s], b[j][r - (1 << s) + 1][s]);
            if (a[j].first <= i) {
                res = max(res, 0ll);
            }
            ans2[j] = res;
            sum += ans2[j];
        }
        ans[i] = sum;
        x = X;
    }
    for (auto c : ans) {
        cout << c << " ";
    }
}