#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const s64 N = 10000000000ll;
const int L = 100000;
const int D = 10;

s64 prod[D + 1][D + 1];

map<s64, string> all;

inline void update(string cur, string &res) {
  if (cur.size() < res.size()) {
    res = cur;
  }
}

int main() {
  for (int i = 1; i <= D; ++i) {
    prod[i][0] = 1;
    for (int j = 1; j <= D; ++j) {
      prod[i][j] = prod[i][j - 1] * i;
    }
  }

  for (int i = 2; i <= L; ++i) {
    s64 exp = i;
    for (int k = 2; N / exp >= i; ++k) {
      exp *= i;
      string cur = to_string(i) + '^' + to_string(k);
      auto it = all.find(exp);
      if (it == all.end()) {
        all.emplace(exp, cur);
      } else {
        if (cur.size() < it->second.size()) {
          it->second = cur;
        }
      }
    }
  }

  s64 n;
  cin >> n;
  string res = to_string(n);

  for (auto [x, s] : all) {
    if (x <= n) {
      string cur;
      if (n % x == 0) {
        cur = s;
        if (n / x > 1) {
          cur = to_string(n / x) + '*' + s;
        }
        update(cur, res);

        auto it = all.find(n / x);
        if (it != all.end()) {
          update(s + '*' + it->second, res);
        }
      }

      cur = s;
      if (n != x) {
        cur += '+' + to_string(n - x);
      }
      update(cur, res);

      auto it = all.find(n - x);
      if (it != all.end()) {
        update(s + '+' + it->second, res);
      }

      int l = (n - 1000) / x, r = n / x;
      for (int i = l + 1; i <= r; ++i) {
        cur = to_string(i) + '*' + s + '+' + to_string(n - i * x);
        update(cur, res);
      }
    }
  }

  string p = "0*0^0+0^0", q = "0^0*0^0+0";
  for (int a = 2; a < 10; ++a) {
    for (int b = 2; b < 10; ++b) {
      for (int c = 2; c < 10; ++c) {
        for (int d = 2; d < 10; ++d) {
          for (int e = 2; e < 10; ++e) {
            s64 x = a * prod[b][c] + prod[d][e];
            if (x == n) {
              p[0] = a + '0';
              p[2] = b + '0';
              p[4] = c + '0';
              p[6] = d + '0';
              p[8] = e + '0';
              update(p, res);
            }

            x = prod[a][b] * prod[c][d] + e;
            if (x == n) {
              q[0] = a + '0';
              q[2] = b + '0';
              q[4] = c + '0';
              q[6] = d + '0';
              q[8] = e + '0';
              update(q, res);
            }
          }
        }
      }
    }
  }

  cout << res << endl;

  return 0;
}