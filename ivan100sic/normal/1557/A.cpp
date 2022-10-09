// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    cout << setprecision(10) << fixed;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        ll s = accumulate(begin(a), end(a), 0ll);
        ll h = *max_element(begin(a), end(a));
        cout << h + ((s - h) / (n - 1.0)) << '\n';
    }
}