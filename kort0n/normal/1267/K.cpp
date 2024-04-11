#include <bits/stdc++.h>
using namespace std;

long long comb(int n, int r) {
  if (r < 0 or r > n) {
    return 0;
  }
  if (r == 0) {
    return 1;
  }
  return comb(n - 1, r - 1) * n / r;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  auto fn = [](vector<int> v) {
    map<int, int> mp;
    for (int e : v) {
      ++mp[e];
    }
    int n = v.size();
    long long res = 1;
    for (auto itr = rbegin(mp); itr != rend(mp); ++itr) {
      int a, b;
      tie(a, b) = *itr;
      if (a == 0) {
        break;
      }
      res *= comb(n - a + 1, b);
      n -= b;
    }
    return res;
  };
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    vector<int> v;
    int d = 2;
    while (k) {
      v.push_back(k % d);
      k /= d;
      ++d;
    }
    sort(begin(v), end(v));
    long long res = fn(v);
    if (v[0] == 0) {
      res -= fn(vector<int>(next(begin(v)), end(v)));
    }
    --res;
    cout << res << '\n';
  }
}