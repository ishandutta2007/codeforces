#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int w, h;
    cin >> w >> h;
    int ans = 0;
    int mod = 998244353;
    ans = 4;
    for (int i = 0; i <  w + h - 1 - 1; i++) {
    	ans = (ans * 2) % mod;
    }
    cout << ans;
}