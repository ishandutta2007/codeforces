#include "bits/stdc++.h"
using namespace std;

// using ModInt = Modular<1'000'000'007>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    
    for (int i = 0; i < n; i++) {
        if (i % 2)
            v[i] = abs(v[i]);
        else
            v[i] = -abs(v[i]);
    }
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}