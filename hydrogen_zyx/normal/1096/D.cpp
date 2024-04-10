#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll dp[5];
    dp[0] = 0;
    dp[1] = dp[2] = dp[3] = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'h') {
            if (dp[1] == -1)
                dp[1] = dp[0];
            else
                dp[1] = min(dp[0], dp[1]);
            dp[0] += a[i];
        } else if (s[i] == 'a') {
            if (dp[2] == -1 && dp[1] != -1)
                dp[2] = dp[1];
            else if (dp[2] != -1)
                dp[2] = min(dp[1], dp[2]);
            if (dp[1] != -1) dp[1] += a[i];
        } else if (s[i] == 'r') {
            if (dp[3] == -1 && dp[2] != -1)
                dp[3] = dp[2];
            else if (dp[3] != -1)
                dp[3] = min(dp[2], dp[3]);
            if (dp[2] != -1) dp[2] += a[i];
        } else if (s[i] == 'd') {
            if (dp[3] != -1) dp[3] += a[i];
        }
    }
    ll mmin = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < 4; i++) mmin = min(max(dp[i], 0LL), mmin);
    cout << mmin;
}