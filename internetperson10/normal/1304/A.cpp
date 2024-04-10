#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    cout << (((y - x) % (a + b)) ? -1 : (y - x) / (a + b)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}