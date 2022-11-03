#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
            while (a[i] > 0 && a[i] % 2 == 0) {
                a[i] /= 2;
                ++cnt;
            }
        }
        sort(a.begin(), a.end());
        while (cnt) {
            a.back() *= 2;
            --cnt;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i];
        }
        cout << ans << '\n';
    }
    
}