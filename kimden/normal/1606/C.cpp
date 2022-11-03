#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> pow10 = {1};
    for (int i = 1; i <= 19; ++i) {
        ll neu = pow10.back() * 10ULL;
        pow10.push_back(neu);
    }
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a.push_back(19);
        ll x = 0;
        ++k;
        for (int i = 0; i < n && k > 0; ++i) {
            ll z = pow10[a[i + 1] - a[i]] - 1;
            ll delta = min<ll>(z, k);
            k -= z;
            x += pow10[a[i]] * (ll)delta;
        }
        cout << x << "\n";
    }
    
}