#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll a[4];
    for(int i = 0; i < 4; i++) cin >> a[i];
    sort(a, a + 4);
    ll ans = a[0] * a[2];
    cout << ans << endl;
}

int main() {
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}