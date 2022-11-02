#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, a[N], dp[N];
vector<int> mi, mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dp[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i - 1];
        int typ = (a[i] == a[i - 1] ? -1 : a[i] > a[i - 1]);
        while (!mi.empty() && a[mi.back()] > a[i]) {
            if (typ == 0) {
                dp[i] = min(dp[i], dp[mi.back()]);
            }
            mi.pop_back();
        }
        if (!mi.empty()) {
            if (typ == 0) {
                dp[i] = min(dp[i], dp[mi.back()]);
            }
            if (a[mi.back()] == a[i]) {
                mi.pop_back();
            }
        }
        mi.push_back(i);
        while (!mx.empty() && a[mx.back()] < a[i]) {
            if (typ == 1) {
                dp[i] = min(dp[i], dp[mx.back()]);
            }
            mx.pop_back();
        }
        if (!mx.empty()) {
            if (typ == 1) {
                dp[i] = min(dp[i], dp[mx.back()]);
            }
            if (a[mx.back()] == a[i]) {
                mx.pop_back();
            }
        }
        mx.push_back(i);
        dp[i]++;
    }
    cout << dp[n];
}