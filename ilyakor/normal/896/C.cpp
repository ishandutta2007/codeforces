#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m, seed, vmax;

int rnd() {
  int ret = seed;
  seed = (int) ((((int64) seed) * 7LL + 13LL) % 1000000007LL);
  return ret;
}

vi a;
vi op, l, r, x, y;

int64 pw(int64 x, int y, int mod) {
  x %= mod;
  int64 res = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      --y;
      res *= x;
      res %= mod;
    }
    y /= 2;
    x *= x;
    x %= mod;
  }
  return res;
}

pair<int64, int> data[218 * 1000];
int cnt;

const int BUBEN = 1500;

struct Seg {
  vector<int64> a;
  int64 fix_num = -1;
  int64 inc = 0;

  void Set(int l, int r, int x) {
    if (l < 0) l = 0; if (r > sz(a) - 1) r = sz(a) - 1;
    if (r < l) return;
    if (l <= 0 && r >= sz(a) - 1) {
      //cerr << "Full set\n";
      fix_num = x;
      inc = 0;
      return;
    }
    //cerr << "Incomplete " << l << " " << r << " " << (sz(a) - 1) << "\n";
    for (int i = 0; i < sz(a); ++i) {
      int64 val = a[i];
      if (i >= l && i <= r) {
        val = x;
      } else {
        if (fix_num != -1) {
          val = fix_num;
        }
        val += inc;
      }
      a[i] = val;
    }
    fix_num = -1;
    inc = 0;
  }

  void Inc(int l, int r, int x) {
    if (l < 0) l = 0; if (r > sz(a) - 1) r = sz(a) - 1;
    if (r < l) return;
    if (l <= 0 && r >= sz(a) - 1) {
      inc += x;
      return;
    }
    for (int i = 0; i < sz(a); ++i) {
      int64 val = a[i];
      if (fix_num != -1) {
        val = fix_num;
      }
      val += inc;
      if (i >= l && i <= r) {
        val += x;
      }
      a[i] = val;
    }
    fix_num = -1;
    inc = 0;
  }

  void Populate(int l, int r) {
    if (l < 0) l = 0; if (r > sz(a) - 1) r = sz(a) - 1;
    if (r < l) return;
    if (fix_num != -1) {
//      cerr << "Cutoff\n";
      int64 val = fix_num + inc;
      data[cnt++] = mp(val, r - l + 1);
      return;
    }
//    cerr << "Full iter " << cnt << "\n";
    int64 prev = -1;
    int pcnt = 0;
    for (int i = l; i <= r && i < sz(a); ++i) {
      int64 val = a[i] + inc;
      if (val == prev) ++pcnt;
      else {
        if (pcnt > 0) data[cnt++] = mp(prev, pcnt);
        prev = val;
        pcnt = 1;
      }
    }
    if (pcnt > 0) data[cnt++] = mp(prev, pcnt);
    //cerr << cnt << "\n";
  }
};

vector<Seg> segs;

void Inc(int l, int r, int64 x) {
  for (int i = l / BUBEN; i <= r / BUBEN; ++i) {
    if (i >= sz(segs)) continue;
    int L = i * BUBEN, R = (i + 1) * BUBEN - 1;
    segs[i].Inc(max(L, l) - L, min(R, r) - L, x);
  }
}

void Set(int l, int r, int64 x) {
  for (int i = l / BUBEN; i <= r / BUBEN; ++i) {
    if (i >= sz(segs)) continue;
    int L = i * BUBEN, R = (i + 1) * BUBEN - 1;
    //cerr << i << " " << l << " " << r << "\n";
    segs[i].Set(max(L, l) - L, min(R, r) - L, x);
  }
}

void DoPopulate(int l, int r) {
  cnt = 0;
  for (int i = l / BUBEN; i <= r / BUBEN; ++i) {
    if (i >= sz(segs)) continue;
    int L = i * BUBEN, R = (i + 1) * BUBEN - 1;
    segs[i].Populate(max(L, l) - L, min(R, r) - L);
  }
//  cerr << "Total size: " << cnt << "\n";
}

int64 Nth(int l, int r, int n) {
//  --n;
  DoPopulate(l, r);
  sort(data, data + cnt);
  for (int i = 0; i < cnt; ++i) {
    auto entry = data[i];
    if (n < entry.second) {
      return entry.first;
    }
    n -= entry.second;
  }
  assert(false);
}

int64 Sum(int l, int r, int x, int y) {
  DoPopulate(l, r);
  int64 res = 0;
  for (int i = 0; i < cnt; ++i) {
    res += pw(data[i].first, x, y) * (int64) data[i].second;
    res %= y;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> seed >> vmax;
  a.resize(n);
  for (int i = 0; i < n; ++i)
    a[i] = rnd() % vmax + 1;

  op.resize(m);
  l.resize(m);
  r.resize(m);
  x.resize(m);
  y.resize(m);
  for (int i = 0; i < m; ++i) {
    op[i] = rnd() % 4 + 1;
    l[i] = rnd() % n;
    r[i] = rnd() % n;
    if (l[i] > r[i]) swap(l[i], r[i]);
    if (op[i] == 3)
      x[i] = rnd() % (r[i] - l[i] + 1);
    else
      x[i] = rnd() % vmax + 1;

    if (op[i] == 4)
      y[i] = rnd() % vmax + 1;
  }

  for (int i = 0; i < n; i += BUBEN) {
    Seg seg;
    for (int j = 0; i + j < n && j < BUBEN; ++j)
      seg.a.pb(a[i + j]);
    segs.emplace_back(seg);
  }

  for (int i = 0; i < m; ++i) {
    if (op[i] == 1) {
      Inc(l[i], r[i], x[i]);
    } else if (op[i] == 2) {
      Set(l[i], r[i], x[i]);
    } else if (op[i] == 3) {
      cout << Nth(l[i], r[i], x[i]) << "\n";
    } else {
      cout << Sum(l[i], r[i], x[i], y[i]) << "\n";
    }
  }
  return 0;
}