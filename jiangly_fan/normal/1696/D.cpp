#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1), vmn, vmx;
        multiset<int> smn = {n}, smx = {n};
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            while (not vmn.empty() and a[vmn.back()] > a[i]) {
                vmn.pop_back();
            }
            while (not vmx.empty() and a[vmx.back()] < a[i]) {
                vmx.pop_back();
            }
            if (i > 1) {
                if (vmn.empty()) dp[i] = dp[vmx[0]] + 1;
                else if (vmx.empty()) dp[i] = dp[vmn[0]] + 1;
                else if (vmx.back() > vmn.back()) {
                    auto it = lower_bound(vmx.begin(), vmx.end(), vmn.back());
                    dp[i] = dp[*it] + 1;
                }
                else {
                    auto it = lower_bound(vmn.begin(), vmn.end(), vmx.back());
                    dp[i] = dp[*it] + 1;
                }
            }
            vmn.push_back(i);
            vmx.push_back(i);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}