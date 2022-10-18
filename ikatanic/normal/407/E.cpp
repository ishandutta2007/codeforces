#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <stack>

#include <map>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1<<18;
const llint inf = 1e12;

struct Tournament {
  llint T[2*MAXN];
  llint S[2*MAXN];

  int offset = MAXN;
  
  void init(int n) {
    offset = 1;
    while (offset < n) offset *= 2;
    REP(i, 2*offset) S[i] = 0;
    REP(i, offset) T[i+offset] = i;
    for (int i = offset-1; i > 0; --i)
      T[i] = min(T[i*2], T[i*2+1]);
  }

  void propagate(int i) {
    int l = i*2, r = l+1;
    if (S[i]) {
      S[l] += S[i], S[r] += S[i];
      T[l] += S[i], T[r] += S[i];
      S[i] = 0;
    }
  }

  void merge(int i) {
    int l = i*2, r = l+1;
    if (T[l] < T[r]) T[i] = T[l] + S[i]; else
      T[i] = T[r] + S[i];
  }

  void inc(int i, int lo, int hi, int a, int b, int k) {
    if (lo >= b || hi <= a) return;
    if (lo >= a && hi <= b) { S[i] += k; T[i] += k; return; }
    propagate(i);

    inc(i*2, lo, (lo+hi)/2, a, b, k);
    inc(i*2+1, (lo+hi)/2, hi, a, b, k);

    merge(i);
  }
  
  void set(int x, llint v) {
    x += offset;
    T[x] = v, S[x] = 0;
    for (int y = x/2; y; y /= 2)
      T[x] -= S[y];
    for (x /= 2; x; x /= 2)
      merge(x);
  }

  int get(int i, int k) {
    if (i >= offset) return i-offset;
    propagate(i);
    if (T[i*2] <= k) return get(i*2, k);
    return get(i*2+1, k);
  }

  void inc(int a, int b, int k) { inc(1, 0, offset, a, b, k); }
  int getFirstLess(int k) { return T[1] > k ? -1 : get(1, k); }
} T;

int a[MAXN];

int main(void) {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  REP(i, n) scanf("%d", a+i);
  REP(i, n) a[i] += 1e9;

  auto equal = [&d](int x, int y) {
    return d == 0 ? (x == y) : (x%d) == (y%d);
  };
  
  T.init(n);

  int lo = 0;
  int ans = 0, ansl = 0;
  while (lo < n) {
    int hi = lo;
    while (hi < n && equal(a[lo], a[hi])) hi++;
    
    auto updateAns = [&ans, &ansl] (int x, int y) {
      if (y-x+1 > ans) ans = y-x+1, ansl = x;
    };
    
    if (d == 0) {
      updateAns(lo, hi-1);
      lo = hi;
      continue;
    }

    for (int i = lo; i < hi; ++i)
      a[i] /= d;
    
    static map<int, int> M;
    M.clear();
    
    static int Smin[MAXN], Smax[MAXN];
    int cmin = 0, cmax = 0;
    Smin[cmin++] = Smax[cmax++] = -1;

    for (int i = lo; i < hi; ++i) {
      int last = -1;
      if (M.count(a[i])) last = M[a[i]];
      while (lo <= last) T.set(lo, inf), lo++;
      M[a[i]] = i;

      Smin[cmin] = i;
      while (cmin > 1 && a[i] <= a[Smin[cmin-1]]) {
        T.inc(Smin[cmin-2]+1, Smin[cmin-1]+1, +a[Smin[cmin-1]]);
        cmin--;
      }
      Smin[cmin++] = i;
      T.inc(Smin[cmin-2]+1, Smin[cmin-1]+1, -a[i]);
      
      Smax[cmax] = i;
      while (cmax > 1 && a[i] >= a[Smax[cmax-1]]) {
        T.inc(Smax[cmax-2]+1, Smax[cmax-1]+1, -a[Smax[cmax-1]]);
        cmax--;
      }
      Smax[cmax++] = i;
      T.inc(Smax[cmax-2]+1, Smax[cmax-1]+1, +a[i]);

      int f = T.getFirstLess(k+i);
      if (f != -1) updateAns(f, i);
    }

    while (lo < hi) T.set(lo, inf), lo++;
  }

  printf("%d %d\n", ansl+1, ansl+ans);
  return 0;
}