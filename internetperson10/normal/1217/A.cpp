#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    ll s, i, e;
    cin >> s >> i >> e;
    ll x = i - s;
    cout << max(0LL, (e - x + 1) / 2 - max(0LL, (-e - x - 1) / 2)) << '\n';
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