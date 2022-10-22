#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int la, ra, ta;
    int lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    int g = __gcd(ta, tb);
    if (abs(la - lb) % g == 0) {
        cout << min(ra - la + 1, rb - lb + 1);
        return 0;
    }
    int ans = 0;
    int p = (g - ((la - lb) % g + g) % g) % g;
    ans = max(ans, min(ra - la + 1 - p, rb - lb + 1));
    int p2 = (g - ((lb - la) % g + g) % g) % g;
    ans = max(ans, min(rb - lb + 1 - p2, ra - la + 1));
    cout << ans;
}