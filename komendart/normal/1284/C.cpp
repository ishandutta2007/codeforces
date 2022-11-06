#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, mod;
    cin >> n >> mod;
    
    vector<int> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        ans += (n - len + 1) * (n - len + 1) % mod * fac[len] % mod * fac[n - len] % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}