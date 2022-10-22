#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
 
const ll MOD = 998244353;

ll power(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;
 
    ll squareRoot = power(a, n / 2);
    ll res = (squareRoot * squareRoot) % MOD;
    if (n % 2 == 1) {
        res = (res * a) % MOD;
    }
    return res;
}

ll pow(ll a, ll n) {
  ll ans = 1;
  while (n) {
    if (n % 2 == 1) {
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

const int NUM = 300005;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<int> c(n);
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> counts(1 << 10, vector<int>());
    for (auto ch : c) {
      counts[ch & 1023].push_back(ch);
    }
    vector<vector<int>> ccounts(1 << 10, vector<int>());
    for (auto count : counts) {
      for (auto ch : count) {
        ccounts[ch >> 10].push_back(ch);
      }
    }
    int currIndex = 0;
    for (auto count : ccounts) {
      for (auto ch : count) {
        c[currIndex++] = ch;
      }
    }
    for (int i = 0; i < n / 2; i++) {
      int temp = c[i];
      c[i] = c[n - i - 1];
      c[n - i - 1] = temp;
    }

    vector<ll> sums(n + 1, 0);
    for (ll i = 0; i < n; i++) {
      sums[i + 1] = sums[i] + c[i];
      if (sums[i + 1] >= MOD) sums[i + 1] -= MOD;
    }
    // sums[i] sum till c[i] exclusive
    const ll inverseN = pow(n, MOD - 2);
    const ll fullSum = sums[n];
    vector<ll> results(n);
    for (ll k = 1; k <= n; k++) { 
        ll beginK = k;
        ll sum = 0;
        while (beginK < n) {
            sum = sum + fullSum - sums[beginK];
            //if (sum >= MOD) sum -= MOD;
            //if (sum < 0) sum += MOD;
            beginK += k;
        }
        results[k - 1] = ((((sum % MOD) + MOD) % MOD) * inverseN) % MOD;
    }

    for (int i = 0; i < n; i++) cout << results[i] << " ";
    cout << "\n";
}