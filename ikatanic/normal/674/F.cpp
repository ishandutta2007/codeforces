#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef unsigned int uint;

struct bignum {
  static const int MAXD = 500;
  static const int BASE = 10000;
  
  int a[MAXD], n;
  
  bignum (int x = 0) {
    n = 0;
    while (x > 0) a[n++] = x%BASE, x /= BASE;
  };
  
  bignum (char *s) {
    n = 0;
    int len = strlen(s);
    REP(i, len) *this = (*this) * 10 + int(s[i]-'0');
  }
  
  void print() {
    if (n == 0) printf("0\n"); else {
      printf("%d", a[n-1]);
      for (int i = n-2; i >= 0; --i)
        printf("%04d", a[i]);
      printf("\n");
    }
  }
  
  static int cmp(const bignum &a, const bignum &b) {
    if (a.n != b.n) return a.n < b.n ? 1 : -1;
    for (int i = a.n-1; i >= 0; --i)
      if (a.a[i] != b.a[i]) return a.a[i] < b.a[i] ? 1 : -1;
    return 0;
  }
  
  friend bool operator == (const bignum &a, const bignum &b) { return cmp(a, b) == 0; }
  friend bool operator < (const bignum &a, const bignum &b) { return cmp(a, b) == +1; }
  friend bool operator > (const bignum &a, const bignum &b) { return cmp(a, b) == -1; }
  friend bool operator >= (const bignum &a, const bignum &b) { return cmp(a, b) <= 0; }
  friend bool operator <= (const bignum &a, const bignum &b) { return cmp(a, b) >= 0; }
  friend bool operator != (const bignum &a, const bignum &b) { return cmp(a, b) != 0; }
  
  // operacije bignum-bignum
  friend bignum operator + (const bignum &a, const bignum &b) {
    bignum r; r.n = max(a.n, b.n);
    int rem = 0;
    REP(i, r.n) {
      r.a[i] = rem;
      if (i < a.n) r.a[i] += a.a[i];
      if (i < b.n) r.a[i] += b.a[i];
      rem = (r.a[i] >= BASE);
      r.a[i] -= rem*BASE;
    }
    if (rem) r.a[r.n++] = 1;
    return r;
  }
  
  friend bignum operator - (const bignum &a, const bignum &b) {
    bignum r; r.n = a.n;
    int rem = 0;
    REP(i, a.n) {
      if (i >= b.n) r.a[i] = a.a[i]-rem; else
        r.a[i] = (a.a[i]-b.a[i]-rem);
      rem = r.a[i] < 0;
      if (rem) r.a[i] += BASE;
    }
    while (r.n > 0 && r.a[r.n-1] == 0) --r.n;
    return r;
  }

  friend bignum operator * (const bignum &a, const bignum &b) {
    if (a == 0 || b == 0) return 0;
    bignum r; r.n = a.n + b.n - 1;
    REP(i, r.n) r.a[i] = 0;
    REP(i, a.n) REP(j, b.n)
      r.a[i+j] += a.a[i]*b.a[j];
    int rem = 0;
    REP(i, r.n) {
      r.a[i] += rem;
      rem = r.a[i]/BASE;
      r.a[i] %= BASE;
    }
    while (rem) r.a[r.n++] = rem%BASE, rem /= BASE;
    return r;
  }
  
  friend bignum operator / (const bignum &a, const bignum &b) {
    if (a < b) return 0;
    bignum hi = 1;
    while (hi*b < a) hi = hi*BASE;
    bignum lo = hi / BASE;
    bignum mid;

    while (lo < hi) {
      mid = (lo + hi + 1)/2;
      if (mid*b <= a) lo = mid; else
        hi = mid-1;
    }
    return lo;
  }

  friend bignum operator % (const bignum &a, const bignum &b) {
    return a - (a/b)*b;
  }

  // operacije bignum-int
  friend bignum operator + (const bignum &a, const int &b) {
    int rem = b;
    bignum ans; ans.n = a.n;
    REP(i, a.n) {
      rem += a.a[i];
      ans.a[i] = rem%BASE;
      rem /= BASE;
    }
    while (rem > 0) ans.a[ans.n++] = rem%BASE, rem /= BASE;
    return ans;
  }
  
  friend bignum operator * (const bignum &a, const int &b) {
    llint rem = 0;
    bignum ans; ans.n = a.n;
    REP(i, a.n) {
      rem += a.a[i]*llint(b);
      ans.a[i] = rem%BASE;
      rem /= BASE;
    }
    while (rem > 0) ans.a[ans.n++] = rem%BASE, rem /= BASE;
    return ans;
  }

  friend bignum operator - (const bignum &a, const int &b) {
    int rem = -b;
    bignum ans; ans.n = a.n;
    REP(i, a.n) {
      rem += a.a[i];
      ans.a[i] = rem; rem = 0;
      if (ans.a[i] < 0) {
        rem = -(-ans.a[i]+BASE-1)/BASE;
        ans.a[i] -= rem*BASE;
      }
    }
    while (ans.n > 0 && ans.a[ans.n-1] == 0) ans.n--;
    return ans;
  }

  friend bignum operator / (const bignum &a, const int &b) {
    llint rem = 0;
    bignum ans = 0;
    for (int i = a.n-1; i >= 0; --i) {
      rem = rem*BASE + a.a[i];
      ans = ans*BASE + (rem/b);
      rem %= b;
    }
    return ans;
  }
  
  friend llint operator % (const bignum &a, const llint &b) {
    llint rem = 0;
    for (int i = a.n-1; i >= 0; --i)
      rem = (rem*BASE + a.a[i])%b;
    return rem;
  }
};


int main(void) {
  int N, P, Q;
  scanf("%d %d %d", &N, &P, &Q);
  P = min(P, N - 1);

  vector<uint> ch(P + 1);
  bignum cur = 1;
  ch[0] = 1;
  FOR(i, 1, P + 1) {
    cur = (cur * (N-i+1)) / i;
    ch[i] = cur % (1LL<<32);
  }
  
  uint ans = 0;
  REP(k, Q+1) {
    uint tot = 0;
    uint pw = 1;
    REP(i, P+1) {
      tot += ch[i] * pw;
      pw *= k;
    }
    ans ^= k*tot;
  }
  
  cout << ans << endl;
  return 0;
}