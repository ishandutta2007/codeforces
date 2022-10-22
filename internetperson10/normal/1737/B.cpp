#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll f(ll x) {
    ll l = 0, r = 1000000001;
    while(l != r - 1) {
        ll mid = (l + r) / 2;
        if(mid * mid <= x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    ll ans = l * 3 - 2;
    if(x >= l * l + l) ans++;
    if(x >= l * l + l + l) ans++;
    return ans;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l-1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}