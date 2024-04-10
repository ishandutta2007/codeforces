#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

long long pr[N], dp[N], a[N];

int main() {
    int i, j, n, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    multiset <int> s;
    dp[0] = 0;
    pr[0] = 0;
    for (i = 1; i <= min(n, c); ++i) {
        s.insert(a[i]);
        dp[i] = dp[i - 1] + a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    if (c > n) {
        cout << pr[n];
        return 0;
    }
    dp[c] -= *s.lower_bound(0);
    for (i = c + 1; i <= n; ++i) {
        pr[i] = pr[i - 1] + a[i];
        s.erase(s.find(a[i - c]));
        s.insert(a[i]);
        dp[i] = min(dp[i - 1] + a[i], dp[i - c] + pr[i] - pr[i - c] - *s.lower_bound(0));
    }
    cout << dp[n];
}