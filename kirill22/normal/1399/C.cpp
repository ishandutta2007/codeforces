#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    for (int k = 0; k <= 100; k++) {
        int res = 0;
        for (int j = 0; j <= k / 2; j++) {
            if (j * 2 == k) {
                res += a[j] / 2;
            }
            else {
                res += min(a[j], a[k - j]);
            }
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}