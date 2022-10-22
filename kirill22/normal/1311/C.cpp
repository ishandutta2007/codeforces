#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> a(m + 1, n - 1);
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < m; i++) a[i]--;
        vector<int> ans(26, 0);
        vector<int> z(n);
        for (auto x : a) z[x]++;
        int tmp = 0;
        for (int i = n - 1; i >= 0; i--) {
            tmp += z[i];
            ans[(s[i] - 'a')] += tmp;
        }
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }
}