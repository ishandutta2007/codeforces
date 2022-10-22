#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
       int q;
       cin >> q;
       while (q--) {
           int n, x, y;
           cin >> n >> x >> y;
           int s = x + y;
           int ans = n, ans2 = 0;
           int x2 = n;
           if (x == n) x2--;
           int l = max(1ll, -n + (s + 1)), r = n;
           if (r < l) {
               ans = n;
           }
           else {
               ans = n - (r - l + 1);
               ans++;
           }
           l = 1, r = min(n, s - 1);
           if (r < l) {
               ans2 = 1;
           }
           else {
               int res = r - l + 1;
               res--;
               ans2 = res + 1;
           }
           cout << ans << " " << ans2 << endl;
       }
}