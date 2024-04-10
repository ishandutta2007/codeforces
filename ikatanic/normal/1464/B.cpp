#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  i64 x, y;
  cin >> x >> y;

  int n = s.size();
  vector<int> c0(n + 1), c1(n + 1);
  c0[0] = 0;
  c1[0] = 0;
  for (int i = 0; i < n; ++i) {
    c0[i + 1] = c0[i] + (s[i] == '0');
    c1[i + 1] = c1[i] + (s[i] == '1');
  }

  int t0 = c0[n], t1 = c1[n];

  i64 s0 = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      s0 += y * c1[i] + (t1 - c1[i]) * x;
      cnt++;
    }
  }

  i64 ret = s0;
  i64 cnt0 = cnt;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      s0 -= y * c1[i] + (t1 - c1[i]) * x;
      s0 += x * c0[i] + (t0 - c0[i]) * y;
      cnt0--;
      ret = min(ret, s0 + cnt0 * (cnt - cnt0) * y);
    }
  }

  s0 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      s0 += x * c0[i] + (t0 - c0[i]) * y;
    }
  }

  ret = min(ret, s0);

  i64 cnt1 = cnt;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      s0 -= x * c0[i] + (t0 - c0[i]) * y;
      s0 += y * c1[i] + (t1 - c1[i]) * x;
      cnt1--;
      ret = min(ret, s0 + cnt1 * (cnt - cnt1) * x);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ret += y * c1[i] + (t1 - c1[i]) * x;
    }
  }

  cout << ret << '\n';
  return 0;
}