#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll negMod(ll a) {
  if (a < 0) {
    a = ((a % MOD) + MOD) % MOD;
  }
  return a;
}

// properly handles negative a
ll pow(ll a, ll n) {
  a = negMod(a);

  if (n == 0) return 1;
  if (n == 1) return a;
  ll res = pow(a, n / 2);
  res = (res * res) % MOD;
  if (n % 2 == 1) {
    res = (res * a) % MOD;
  }

  return res;
}

ll inv(ll a) {
  return pow(a, MOD - 2);
}


ll calculateRecursionElement(ll x0, ll x1, ll r0, ll r1, ll d, ll index, bool print = false) {
  if (print) {
    cout << "deb " << x0 << " " << x1 << " " << index << " " << d << "\n";
  }
  
  if (index == 0) return x0;
  if (index == 1) return x1;
  if (index == 2) return (2 * x1 + (9 - d) * x0) % MOD;

  ll x2 = (2 * x1 + (9 - d)) % MOD;
  index--;

  ll a = (negMod(x2 - x1 * r1) * inv(r0 - r1)) % MOD;
  ll b = (negMod(x2 - x1 * r0) * inv(r1 - r0)) % MOD;

  ll res = (a * pow(r0, index) + b * pow(r1, index)) % MOD;

  if (print) {
    cout << "deb " << x0 << " " << x1 << " " << x2 << " " << a << " " << b << " " << r0 << " " << r1 << " " << res << "\n";
  }
  return res;

}

ll calculateDP(int leftIndex, int rightIndex, int lastDigit, bool print = false) {
  int length = rightIndex - leftIndex;
  return calculateRecursionElement(1, lastDigit + 1, -2, 4, lastDigit, length, print);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string c;
  cin >> c;
  vector<int> digits(n);
  for (int i = 0; i < n; i++) {
    digits[i] = c[i] - '0';
  }
  map<int, ll> dp;
  for (int i = 0; i < n; i++) {
    if (i == 0 || c[i - 1] != '1') dp[i] = 1;
  }
  dp[n] = 1;

  for (auto it = dp.begin(); it != dp.end(); ++it) {
    if (it->first != n) {
      dp[it->first] = calculateDP(it->first, next(it)->first, digits[next(it)->first - 1]);
    }
  }

  ll result = 1;
  for (auto it = dp.begin(); it != dp.end(); ++it) {
    result = (result * it->second) % MOD;
  }

  for (int i = 0; i < m; i++) {
    int x, d;
    cin >> x >> d;
    x--;
    if (digits[x] == d) {
      cout << result << "\n";
      continue;
    }

    if (d != 1) {
      if (dp.find(x + 1) != dp.end()) {
        auto it = dp.find(x + 1);
        auto it_prev = next(it, -1);
        result = (result * inv(it_prev->second)) % MOD;
        digits[x] = d;
        dp[it_prev->first] = calculateDP(it_prev->first, it->first, d);
        result = (result * dp[it_prev->first]) % MOD;
      } else {
        auto it = dp.upper_bound(x);
        auto it_prev = next(it, -1);
        result = (result * inv(it_prev->second)) % MOD;
        digits[x] = d;
        dp[it_prev->first] = calculateDP(it_prev->first, x + 1, d);
        result = (result * dp[it_prev->first]) % MOD;
        dp[x + 1] = calculateDP(x + 1, it->first, digits[it->first - 1]);
        result = (result * dp[x + 1]) % MOD;
      }
    } else {
      // it wasn't previously one
      // x + 1 should be in dp; if not we have a bug
      auto it = dp.find(x + 1);
      auto it_prev = next(it, -1);
      result = (result * inv(dp[it->first])) % MOD;
      result = (result * inv(dp[it_prev->first])) % MOD;
      digits[x] = d;
      if (x == n - 1) {
        dp[it_prev->first] = calculateDP(it_prev->first, it->first, d);
        result = (result * dp[it_prev->first]) % MOD;
      } else {
        auto it_next = next(it);
        dp[it_prev->first] = calculateDP(it_prev->first, it_next->first, digits[it_next->first - 1]);
        result = (result * dp[it_prev->first]) % MOD;
        dp.erase(it);
      }
    }

    cout << result << "\n";
  }
}