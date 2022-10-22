#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int mx = a[0];
    int sum = 0, g = 0;
    for (int i = 0; i < n; i++) {
        sum += mx - a[i];
        if (mx != a[i]) {
            g = __gcd(g, mx - a[i]);
        }
    }
    cout << sum / g << " " << g;
}