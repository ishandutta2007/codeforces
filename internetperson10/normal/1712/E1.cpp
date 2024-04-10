#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    ll k = r - l + 1;
    ll ans = k * (k - 1) * (k - 2) / 6;
    for(int i = l+2; i <= r; i++) {
        if(i % 6 == 0) {
            if(i / 2 >= l) ans--;
        }
        if(i % 15 == 0) {
            if(2 * i / 5 >= l) ans--;
        }
        set<int> divs, di;
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) di.insert(j);
        }
        for(int g : di) {
            divs.insert(g);
            divs.insert(i/g);
        }
        ll x = 0;
        for(int g : divs) {
            if(g >= l) x++;
        }
        ans -= ((x-2) * (x - 1)) / 2;
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