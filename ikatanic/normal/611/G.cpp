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

const int MAX = 500500;
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

struct Pt {
  int x, y;
} p[MAX];

int md(llint x) { return (x%mod + mod) % mod; }

struct S {
  llint kx, ky, l;

  friend S operator + (const S& a, const S& b) {
    return {a.kx + b.kx, a.ky + b.ky, a.l + b.l};
  }

  friend S operator - (const S& a, const S& b) {
    return {a.kx - b.kx, a.ky - b.ky, a.l - b.l};
  }

  friend S operator * (const int& k, const S& a) {
    return {k*a.kx, k*a.ky, k*a.l};
  }

  friend S operator % (const S& a, const int& k) {
    return {md(a.kx), md(a.ky), md(a.l)};
  }

  llint eval(const Pt& p) {
    return kx*p.x + ky*p.y + l;
  }
};

S f[MAX];
S s[MAX];
S wf[MAX];
S ws[MAX];
int n;

S getsum(int i, int j) {
  if (i > j) return getsum(i, n-1) + getsum(0, j);
  auto ans = s[j];
  if (i > 0) ans = ans + (-1)*s[i-1];
  return ans;
}

S getwsum(int i, int j) {
  S ans;
  if (i > j) {
    ans = wf[n-1] - wf[i-1] + wf[j] + n*(getsum(0, j) % mod);
  } else {
    ans = wf[j];
    if (i > 0) ans = ans + (-1)*wf[i-1];
  }
  ans = ans + (-i)*(getsum(i, j) % mod);
  return ans % mod;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", &p[i].x, &p[i].y);

  REP(i, n) {
    int j = (i + 1) % n;
    f[i] = { p[j].y - p[i].y,
             p[i].x - p[j].x,
             llint(p[j].x)*p[i].y - llint(p[i].x)*p[j].y,
    };
    s[i] = f[i];
    wf[i] = i * (f[i] % mod);
    if (i > 0) {
      s[i] = s[i] + s[i - 1];
      wf[i] = wf[i] + wf[i - 1];
    }
    wf[i] = wf[i] % mod;
  }

  auto area = [&] (int o, int j) {
    return getsum((o+1)%n, (o+j-1)%n).eval(p[o]);
  };

  llint total = area(0, n-1);
  llint ans = 0;

  int j = 1;
  REP(i, n) {
    if (j > 1) j--;
    while (j+1 < n && area(i, j+1)*2LLU <= total) j++;
    llint ar = area(i, j);
    int a = j - 1;
    int b = n - 2 - a;

    if (a > 0) {
      int lo = (i + 1) % n;
      int hi = (i + a) % n;
      S sum = getsum(lo, hi) % mod;
      S sumt = ((b-3-a) * sum) % mod;
      ans += sumt.eval(p[i]) % mod;
      S wsum = (getwsum(lo, hi) + sum) % mod;
      ans += 2*wsum.eval(p[i]) % mod;
    }

    if (b > 0) {
      int lo = (i + a + 1) % n;
      int hi = (i + a + b) % n;
      S sum = getsum(lo, hi) % mod;
      S sumt = ((b+1+3*a)*sum) % mod;
      ans += sumt.eval(p[i]) % mod;
      S wsum = (getwsum(lo, hi) + (a+1)*sum) % mod;
      ans -= 2*wsum.eval(p[i]) % mod;
    }
    ans %= mod;
    if (ans < 0) ans += mod;
  }
  
  ans = mul(ans, (mod + 1) / 2);
  printf("%lld\n", ans);
  return 0;
}