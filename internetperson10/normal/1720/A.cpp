#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a * d == b * c) {
        cout << 0 << '\n';
        return;
    }
    ll x = max(a * d, b * c);
    ll y = min(a * d, b * c);
    if(y == 0) {
        cout << 1 << '\n';
    }
    else if((x / y) * y == x) {
        cout << 1 << '\n';
    }
    else {
        cout << 2 << '\n';
    }
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