#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    vector<ll> c(3);
    for(int i = 0; i < 3; i++) cin >> c[i];
    vector<ll> a(5);
    for(int i = 0; i < 5; i++) cin >> a[i];

    for(int i = 0; i < 3; i++) {
        if(c[i] < a[i]) {
            cout << "NO\n";
            return;
        }
        c[i] -= a[i];
    }

    a[3] = max(a[3] - c[0], 0LL);
    a[4] = max(a[4] - c[1], 0LL);
    cout << (a[3] + a[4] <= c[2] ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}