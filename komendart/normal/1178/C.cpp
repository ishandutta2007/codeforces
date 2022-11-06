#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int w, h;
    cin >> w >> h;
    int ans = 1;
    for (int i = 0; i < w + h; ++i) {
        ans = ans * 2 % mod;
    }
    cout << ans << '\n';
}