#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, w, x, y, z;
    ll m, n, a, b, c=0, d, k, ans=0;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 1;
        c = 0;
        for(int i = 0; i < n; i++) {
            d = k;
            cin >> k;
            if(i > 0) {
                if(d < k) {
                    ans = max(ans, c);
                    c = 0;
                }
            }
            c++;
            // cout << c << ' ' << ans << '\n';
        }
        cout << max(ans, c) << '\n';
    }
}