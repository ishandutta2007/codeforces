#include<bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, mod;
    cin >> n >> mod;
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * 1ll * i % mod;
    }
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        int res = (n - x + 1) * 1ll * (n - x + 1) % mod * fact[x] % mod * fact[n - x] % mod;
        ans = (ans + res) % mod;
    }
    cout << ans;
}