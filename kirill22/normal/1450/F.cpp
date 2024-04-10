#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[a[i]]++;
        }
        int cnt = 0;
        for (auto [x, c] : b) {
            cnt = max(cnt, c);
        }
        if (cnt > (n + 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        int l = a[0], r = a[0], sum = 0;
        vector<pair<int, int>> c;
        for (int i = 1; i < n; i++) {
            if (a[i] != r) {
                sum++;
                r = a[i];
            } else {
                c.push_back({l, r});
                l = r = a[i];
            }
        }
        c.push_back({l, r});
        b.clear();
        for (auto [x, y] : c) {
            b[x]++;
            b[y]++;
        }
        int res = 0, ans;
        for (auto [x, c] : b) {
            res = max(res, c);
        }
        if (res <= (int) c.size() + 1) {
            ans = sum;
        } else {
            ans = sum - (res - ((int) c.size() + 1));
        }
        cout << n - 1 - ans << '\n';
    }
}