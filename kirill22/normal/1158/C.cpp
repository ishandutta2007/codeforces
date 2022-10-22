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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != -1) {
                a[i]--;
            } else {
                a[i] = i + 1;
            }
        }
        vector<int> ans(n);
        int f = 1;
        function<void(int, int, int, int)> solve = [&] (int l, int r, int cl, int cr) {
            if (l > r) {
                return;
            }
            if (a[l] > r + 1) {
                f = 0;
                return;
            }
            if (a[l] == r + 1) {
                ans[l] = cr;
                solve(l + 1, r, cl, cr - 1);
                return;
            }
            ans[l] = cl + (a[l] - l - 1);
            solve(l + 1, a[l] - 1, cl, ans[l] - 1);
            solve(a[l], r, ans[l] + 1, cr);
        };
        solve(0, n - 1, 1, n);
        if (!f) {
            cout << -1 << '\n';
        } else {
            for (auto x : ans) {
                cout << x << " ";
            }
            cout << '\n';
        }
    }
}