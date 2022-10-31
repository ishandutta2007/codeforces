#include <bits/stdc++.h>

using namespace std;

using ld = long double;

ld dp[100228][10];
int prv[100228][10];
int prvj[100228][10];

int main() {
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = -2e9;
        }
    }

    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (dp[i + 1][j * a[i] % 10] < dp[i][j] + logl(a[i])) {
                dp[i + 1][j * a[i] % 10] = dp[i][j] + logl(a[i]);
                prv[i + 1][j * a[i] % 10] = 1;
                prvj[i + 1][j * a[i] % 10] = j;
            }
            if (dp[i + 1][j] < dp[i][j]) {
                dp[i + 1][j] = dp[i][j];
                prv[i + 1][j] = 2;
            }
        }
    }
    if (dp[n][d] < 0) {
        cout << "-1\n";
    } else {
        vector<int> ans;
        for (int i = n, j = d; i > 0; i--) {
            if (prv[i][j] == 1) {
                ans.emplace_back(a[i - 1]);
                j = prvj[i][j];
            }
        }
        if (ans.empty()) {
            cout << "-1\n";
            return 0;
        }
        cout << ans.size() << "\n";
        for (auto x : ans) {
            cout << x << " ";
        }
    }

    return 0;
}