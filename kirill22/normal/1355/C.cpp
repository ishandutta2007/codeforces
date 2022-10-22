#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0, tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp++;
        if (tmp >= a[i]) {
            tmp = 0;
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int l = a; l <= b; l++) {
        if (l + c - 1 > d) {
            int cnt = min(l + c - 1 - d, c - b + 1);
            ans += cnt * (d - c + 1);
            if (cnt == c - b + 1) continue;
            int res = ((d + 1 - l) + l - 1) - c + 1;
            int res2 = max(0ll, (b + l - 1) - c + 1);
            ans -= (res2 * (res2 - 1)) / 2 - (res * (res + 1)) / 2;
        }
        else {
            int res = (c + l - 1) - c + 1;
            int res2 = max(0ll, (b + l - 1) - c + 1);
            ans -= (res2 * (res2 - 1)) / 2 - (res * (res + 1)) / 2;
        }
    }
    cout << ans;
}