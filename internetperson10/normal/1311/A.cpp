#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    ll a, b;
    cin >> a >> b;
    int ans = 0;
    if(a == b) ans = 0;
    if(a < b) {
        if(a%2 == b%2) ans = 2;
        else ans = 1;
    }
    if(a > b) {
        if(a%2 != b%2) ans = 2;
        else ans = 1;
    }
    cout << ans << '\n';
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