#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int off = 1 << 19;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int T[2 * off];

int query(int i, int lo, int hi, int a, int x) {
  assert(hi >= a);

  if (T[i] % x == 0) return hi;
  if (i >= off) return i - off;

  int mid = (lo + hi) / 2;

  if (a < mid) {
    int left_r = query(i*2, lo, mid, a, x);
    if (left_r != mid) return left_r;
  }

  return query(i*2 + 1, mid, hi, a, x);
}

bool divisible(int i, int lo, int hi, int a, int b, int x) {
  if (lo >= b || hi <= a) return true;
  if (lo >= a && hi <= b) return T[i] % x == 0;
  return
    divisible(i*2, lo, (lo+hi)/2, a, b, x) &&
    divisible(i*2+1, (lo+hi)/2, hi, a, b, x);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &T[off + i]);
  for (int i = off - 1; i > 0; --i) T[i] = gcd(T[i*2], T[i*2 + 1]);

  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      --l;

      int maks_r = query(1, 0, off, l, x);

      bool ans = false;

      if (maks_r >= r) {
        ans = true;
      } else {
        ans = divisible(1, 0, off, maks_r + 1, r, x);
      }

      puts(ans ? "YES" : "NO");
    } else if (type == 2) {
      int i, y;
      scanf("%d %d", &i, &y);
      --i;

      i += off;
      T[i] = y;
      for (i /= 2; i; i /= 2) T[i] = gcd(T[i*2], T[i*2 + 1]);
    }
  }
  return 0;
}