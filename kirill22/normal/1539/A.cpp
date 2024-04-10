#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

int f(int n) {
    if (n < 0) return 0;
    return n * (n + 1) / 2;
}

void solve() {
    int n, x, t;
    cin >> n >> x >> t;
    int ans = -f(n);
    int k = t / x;
    if (k > n - 1) ans += n * n;
    else {
        ans += f(n) - f(k);
        ans += n * k;
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