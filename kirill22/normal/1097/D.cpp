#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * 1ll * x % mod;
        }
        x = x * 1ll * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    int k;
    cin >> n >> k;
    int ans = 1;
    auto upd = [&] (long long x) {
          int cnt = 0;
          while (n % x == 0) {
              cnt++;
              n /= x;
          }
          vector<int> dp(cnt + 1);
          dp.back() = 1;
          for (int i = 0; i < k; i++) {
              int sum = 0;
              for (int j = cnt; j >= 0; j--) {
                  sum = (sum + dp[j] * 1ll * binpow(j + 1, mod - 2)) % mod;
                  dp[j] = sum;
              }
          }
          int res = 0;
          long long c = 1;
          for (int j = 0; j <= cnt; j++) {
              res = (res + (c % mod) * 1ll * dp[j]) % mod;
              c *= x;
          }
          ans = ans * 1ll * res % mod;
    };
    for (int x = 2; x * 1ll * x <= n; x++) {
        if (n % x == 0) {
            upd(x);
        }
    }
    if (n > 1) {
        upd(n);
    }
    cout << ans;
    
}