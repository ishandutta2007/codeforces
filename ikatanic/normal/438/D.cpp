#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> par;

const int inf = 1e9;
const int offset = 1<<17;
const int MAXN = 2*offset;

struct Tournament {
  par T[MAXN];
  llint S[MAXN];

  void init() {
    for (int i = 0; i < 2*offset; ++i)
      T[i] = {-inf, -1}, S[i] = 0;
  }
  
  void set(int x, int v) {
    x += offset;
    T[x] = {v, x-offset};
    S[x] = v;
    for (x /= 2; x; x /= 2) {
      T[x] = max(T[x*2], T[x*2+1]);
      S[x] = S[x*2] + S[x*2+1];
    }
  }

  par get(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return make_pair(-inf, -1);
    if (lo >= a && hi <= b) return T[i];
    return max(get(i*2, lo, (lo+hi)/2, a, b), get(i*2+1, (lo+hi)/2, hi, a, b));
  }
  
  llint sum(int i, int lo, int hi, int a, int b) {
    if (lo >= b || hi <= a) return 0;
    if (lo >= a && hi <= b) return S[i];
    return sum(i*2, lo, (lo+hi)/2, a, b) + sum(i*2+1, (lo+hi)/2, hi, a, b);
  }
  
  int getmax(int a, int b) {
    return get(1, 0, offset, a, b+1).second;
  }
  llint sum(int a, int b) {
    return sum(1, 0, offset, a, b+1);
  }
} T;

int a[MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  
  T.init();
  REP(i, n) {
    scanf("%d", a+i);
    T.set(i, a[i]);
  }

  REP(i, m) {
    int tip;
    scanf("%d", &tip);

    // PROMJENI LL!!
    if (tip == 1) {
      int l, r;
      scanf("%d %d", &l, &r); --l, --r;
      printf("%I64d\n", T.sum(l, r));
    }
    if (tip == 2) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x); --l, --r;
      
      while (true) {
        int p = T.getmax(l, r);
        if (a[p] < x) break;
        a[p] %= x;
        T.set(p, a[p]);
      }
    }
    if (tip == 3) {
      int k, x;
      scanf("%d %d", &k, &x); --k;
      a[k] = x;
      T.set(k, x);
    }
  }

  return 0;
}