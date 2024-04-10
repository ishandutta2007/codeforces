#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <complex>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<


typedef long long llint;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

struct bignum {
  static const int MAXD = 1500;
  static const int BASE = 100000000;
  
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
        printf("%08d", a[i]);
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
    bignum ans; ans.n = a.n;
    for (int i = a.n-1; i >= 0; --i) {
      rem = rem*BASE + a.a[i];
      ans.a[i] = rem / b;
      rem %= b;
    }
    while (ans.n > 0 && ans.a[ans.n-1] == 0) ans.n--;
    return ans;
  }
  
  friend int operator % (const bignum &a, const int &b) {
    llint rem = 0;
    for (int i = a.n-1; i >= 0; --i)
      rem = (rem*BASE + a.a[i])%b;
    return rem;
  }
};

int main(void) {
  int n;
  scanf("%d", &n);

  vector<int> a(n), b(n);
  FOR(i, 1, n) scanf("%d", &a[i]);
  REP(i, n) scanf("%d", &b[i]);

  vector<int> c = {1};
  vector<vector<int>> w = {{b[0]}};
  FOR(i, 1, n) {
    if (a[i] > 1) {
      c.push_back(a[i]);
      w.push_back({});
    }
    w.back().push_back(b[i]);
  }

  n = c.size();
  vector<int> ws(n);
  REP(i, n) ws[i] = accumulate(w[i].begin(), w[i].end(), 0);

  vector<int> max_rem(n);
  int sum = 0;
  REP(i, n) {
    sum += ws[i];
    max_rem[i] = sum;
    if (i + 1 < n) sum /= c[i+1];
  }
  
  // sum(max_rem) <= 600000
  // n <= 30000
  
  const int MAXL = 10010;
  char m_str[MAXL];
  scanf("%s", m_str);

  bignum m(m_str);
  vector<int> p(n);

  REP(i, n) {
    m = m / c[i];

    if (i + 1 < n) {
      p[i] = m % c[i+1];
    } else {
      if (m > max_rem[i]) {
        puts("0");
        return 0;
      } else {
        p[i] = m % (max_rem[i] + 1);
      }
    }
  }
  
  
  vector<int> f;
  f.resize(max_rem[n-1]+1);
  f[p[n-1]] = 1;
  
  for (int i = n-1; i >= 0; --i) {
    int k = w[i].size();
    int m = f.size();
    vector<int> nf(m);
    
    REP(x, k) {
      int cnt = w[i][x];
      REP(y, m) nf[y] = 0;
      
      int running_sum = 0;
      for (int y = m-1; y >= 0; --y) {
        running_sum = add(running_sum, f[y]);
        nf[y] = running_sum;
        if (y+cnt < m) {
          running_sum = sub(running_sum, f[y+cnt]);
        }
      }
      f.swap(nf);
    }


    int nsz = i == 0 ? 1 : max_rem[i-1]+1;
    int q = i > 0 ? p[i-1] : 0;
    
    nf.resize(nsz);
    REP(x, nsz) nf[x] = 0;
    
    REP(x, m) if (x*1LL*c[i]+q < nsz) nf[x * c[i] + q] = f[x];
    f.swap(nf);
  }

  printf("%d\n", f[0]);
  return 0;
}