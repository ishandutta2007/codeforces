#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) (a).size()
#define fi first
#define se second
#define pii pair<int, int>
#define ld long double
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back

void solve() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int ans = 1e18;
    vector<int> mas = {a, b, c};
    for (auto x : mas) ans = min(ans, (x - m % x) % x);
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