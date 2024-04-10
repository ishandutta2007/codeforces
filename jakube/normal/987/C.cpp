#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    vector<long long> dp(c.begin(), c.end());
    for (int i = 0; i < 2; i++) {
        vector<long long> dp2(n, std::numeric_limits<int>::max());
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (s[k] < s[j])
                    dp2[j] = min(dp2[j], c[j] + dp[k]);
            }
        }
        dp = dp2;
    }
    long long mi = *min_element(dp.begin(), dp.end());
    if (mi > 3e8)
        cout << -1 << '\n';
    else
        cout << mi << '\n';
}