#include <bits/stdc++.h>
#define ls o << 1
#define rs o << 1 | 1

using LL = long long;

constexpr int N(2e5 + 5), L(1 << 19);
constexpr LL INF(LLONG_MAX / 2);
int n, q, len;
LL a[N];
int w[N], v[N], p[N], ip[N];
struct Data {
  LL sw, sv, tw;
} t[18][L];
void pushup(int i, int o) {
  t[i][o] = {
    t[i][ls].sw + t[i][rs].sw,
    t[i][ls].sv + t[i][rs].sv,
    std::min(t[i][ls].tw, t[i][ls].sw + t[i][rs].tw)
  };
}
void update(int i, int j) {
  int o = j + len;
  if (j < n) {
    j = p[j];
    if (w[j] < 1 << i) {
      t[i][o] = {a[j] * w[j], a[j] * v[j], INF};
    } else {
      t[i][o] = {0, 0, a[j] ? w[j] : INF};
    }
  } else {
    t[i][o] = {0, 0, INF};
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> q;
  len = 2;
  while (len < n) len <<= 1;
  for (int i = 0; i < n; i++) std::cin >> a[i] >> w[i] >> v[i];
  std::iota(p, p + n, 0);
  std::sort(p, p + n, [&](int i, int j) {
    return v[i] > v[j] || v[i] == v[j] && w[i] < w[j];
  });
  for (int i = 0; i < n; i++) {
    ip[p[i]] = i;
  }
  for (int i = 0; i < 18; i++) {
    for (int j = 0; j < len; j++) update(i, j);
    for (int o = len - 1; o; o--) pushup(i, o);
  }
  while (q--) {
    int opt;
    std::cin >> opt;
    if (opt <= 2) {
      int x, j;
      
      std::cin >> x >> j;
      j--;
      if (opt == 2) x = -x;
      a[j] += x;
      j = ip[j];
      for (int i = 0; i < 18; i++) {
	update(i, j);
	for (int o = len + j >> 1; o; o >>= 1) pushup(i, o);
      }
    } else {
      LL c, ans = 0;
      std::cin >> c;
      for (int i = 17, o = len, r; i >= 0; i--) {
	for (r = len + len - 1; o <= r; o >>= 1, r >>= 1) {
	  if (o & 1 ^ 1) continue;
	  if (t[i][o].tw <= c) {
	    while (o < len) {
	      if (t[i][ls].tw <= c) {
		o = ls;
	      } else {
		c -= t[i][ls].sw, ans += t[i][ls].sv;
		o = rs;
	      }
	    }
	    int j = p[o - len];
	    c -= w[j], ans += v[j];
	    r = ++o;
	    break;
	  }
	  if (t[i][o].sw > c) {
	    while (o < len) {
	      if (t[i][ls].sw > c) {
		o = ls;
	      } else {
		c -= t[i][ls].sw, ans += t[i][ls].sv;
		o = rs;
	      }
	    }
	    int j = p[o - len];
	    LL cnt = std::min(a[j], c / w[j]);
	    c -= cnt * w[j], ans += cnt * v[j];
	    r = ++o;
	    break;
	  }
	  c -= t[i][o].sw, ans += t[i][o].sv;
	  o++;
	}
	if (o > r) break;
      }
      std::cout << ans << "\n";
    }
  }
  return 0;
}
/*
1 1
15782 18529 93504
3 370204893

 */