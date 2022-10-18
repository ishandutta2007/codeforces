#include "bits/stdc++.h"
using namespace std;

// using ModInt = Modular<1'000'000'007>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    

    if (v[0] < v.back())
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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