#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

long long a[N], suf[N], pr[N];

int main() {
    int i, j, n;
    long long k, sum = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        pr[i] = max(pr[i - 1] + a[i], (long long)0);
    }

    for (i = n; i >= 1; --i) {
        suf[i] = max(suf[i + 1] + a[i], (long long)0);
    }
    if (k <= 0) {
        long long mx = 0, ans = 0;
        for (i = 1; i <= n; ++i) {
            mx = max(mx + a[i] * k, pr[i]);
            ans = max(ans, mx + suf[i + 1]);
        }
        cout << ans;
    } else {
        long long mx = 0, ans = 0;
        for (i = 1; i <= n; ++i) {
            mx = max((long long)0, a[i] + mx);
            ans = max(ans, mx * k + suf[i + 1]);
        }
        cout << ans;
    }
}