#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

void solve() {
  string str, res = "";
  cin >> str;
  int n = str.size();
  rep(i, 0, n - 3) res += '9';
  per(len, n - 1, 0) if (str[len] != '0') {
    per(ch, str[len] - 1, len ? '0' : '1') {
      string cur = str.substr(0, len) + char(ch);
      int S = 0;
      for (char x : cur) S ^= 1 << (x - '0');
      string tmp = "";
      per(i, 9, 0) if (S >> i & 1) {
        tmp += i + '0';
      }
      while (str.size() > cur.size() + tmp.size()) {
        cur += '9';
      }
      cur += tmp;
      if (cur.size() == str.size()) {
        res = cur; break;
      }
    }
    if (res.size() == str.size()) break;
  }
  cout << res << endl;
}

int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}