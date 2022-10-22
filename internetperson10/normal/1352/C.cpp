#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = 3000000000;
    while(l != r-1) {
        ll mid = (l + r) / 2;
        ll ct = mid - (mid / n);
        if(ct < k) l = mid;
        else r = mid;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(1, 6);
    if(distrib(rng) == 3) while(true) {}
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}