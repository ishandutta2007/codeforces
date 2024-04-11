#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int power = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += power * a[i];
        ans %= mod;
        power *= 2; power %= mod;
    }
    power = 1;
    for (int i = n - 1; i >= 0; --i) {
        ans -= power * a[i];
        ans %= mod;
        power *= 2; power %= mod;
    }
    cout << (ans + mod) % mod << '\n';
}