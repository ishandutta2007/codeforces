#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int dp1[maxn], dp2[maxn];

main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'G') {
            dp2[i] = max(dp2[i - 1], dp1[i - 1]) + 1;
            dp1[i] = dp1[i - 1] + 1;
            cnt++;
        } else {
            dp2[i] = dp1[i - 1] + 1;
            dp1[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp2[i] > cnt) {
            cout << cnt;
            return 0;
        }
        ans = max(ans, dp2[i]);
    }
    cout << ans;
    return 0;
}