#include <bits/stdc++.h>
using namespace std;
int dp[200000];
int a[200000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) dp[i] = 1;
        int mmax = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + i; j <= n; j += i)
                if (a[i] < a[j]) dp[j] = max(dp[j], dp[i] + 1);

            mmax = max(mmax, dp[i]);
        }
        cout << mmax << endl;
    }
}