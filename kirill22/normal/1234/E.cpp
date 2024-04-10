#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> f(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }
    vector<int> a;
    a.push_back(f[0]);
    for (int i = 1; i < m; i++) {
        if (f[i] != a.back()) {
            a.push_back(f[i]);
        }
    }
    if (a.size() < 2) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        return 0;
    }
    vector<int> A;
    vector<int> B;
    vector<int> c(n + 1);
    m = a.size();
    for (int i = 1; i < m; i++) {
        A.push_back(min(a[i - 1], a[i]));
        B.push_back(max(a[i - 1], a[i]));
        c[a[i]] += a[i - 1];
        if (a[i - 1] > a[i]) {
            c[a[i]]--;
        }
        c[a[i]] -= abs(a[i - 1] - a[i]);
        c[a[i - 1]] += a[i];
        if (a[i] > a[i - 1]) {
            c[a[i - 1]]--;
        }
        c[a[i - 1]] -= abs(a[i - 1] - a[i]);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans(n + 1, 0);
    for (int i = 1; i < m; i++) {
        ans[1] += abs(a[i] - a[i - 1]);
    }
    for (int k = 2; k <= n; k++) {
        int res = ans[1];
        res += c[k];
        int l = m - 1;
        auto it = upper_bound(B.begin(), B.end(), k);
        if (it == B.end()) {
            l = 0;
        }
        else {
            int r = it - B.begin();
            l -= r;
        }
        auto it2 = lower_bound(A.begin(), A.end(), k);
        if (it2 != A.end()) {
            int r = it2 - A.begin();
            int x = m - 1 - r;
            l -= x;
        }
        ans[k] = res - l;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}