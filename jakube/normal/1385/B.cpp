#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for (auto& x : v)
        cin >> x;
    
    vector<bool> seen(n+1, false);
    for (int x : v) {
        if (!seen[x])
            cout << x << " ";
        seen[x] = true;
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