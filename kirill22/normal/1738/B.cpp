#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }
    long long lst = (long long) 1e18;
    for (int j = k - 1; j >= 1; j--) {
        long long x = s[j] - s[j - 1];
        if (x > lst) {
            cout << "NO\n";
            return;
        }
        lst = x;
    }
    if (lst != (long long) 1e18 && lst * (n - k + 1) < s[0]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}