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
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <ll, ll> pii;
const int maxn = 3e5 + 10;
int n, A[maxn];

pii calc(int l, int r, int bit, int &pos) {
  int s0 = 0, s1 = 0;
  ll c0 = 0, c1 = 0;
  vector <int> vec0, vec1;
  rep(i, l, r) {
    int x = A[i] >> bit & 1;
    if (x) {
      s1++, c1 += s0, vec1.push_back(A[i]);
    } else {
      s0++, c0 += s1, vec0.push_back(A[i]);
    }
  }
  int cur = l;
  for (int x : vec0) A[cur++] = x;
  pos = cur - 1;
  for (int x : vec1) A[cur++] = x;
  return pii(c0, c1);
}

void solve() {
  cin >> n;
  rep(i, 1, n) A[i] = read();
  vector <pii> seg;
  seg.push_back({1, n});
  int X = 0; ll res = 0;
  per(bit, 29, 0) {
    vector <pii> vec;
    ll c0 = 0, c1 = 0;
    for (pii p : seg) {
      int pos;
//      putchar('#');
//      rep(i, p.first, p.second) printf("%d ", A[i]);
      pii t = calc(p.first, p.second, bit, pos);
//      printf("\n(%lld %lld)\n", t.first, t.second);
      c0 += t.first, c1 += t.second;
      if (p.first <= pos) vec.push_back({p.first, pos});
      if (pos < p.second) vec.push_back({pos + 1, p.second});
    }
    if (c0 > c1) {
      X |= 1 << bit, res += c1;
    } else {
      res += c0;
    }
    swap(vec, seg);
  }
  cout << res << ' ' << X << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}