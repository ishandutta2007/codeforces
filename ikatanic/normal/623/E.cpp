#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <complex>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 30030;
const int mod = 1e9 + 7;
const double pi = acos(-1);

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

namespace FFT {
  const int MAX = 1 << 16;

  typedef llint value;
  typedef complex<double> comp;
 
  int N;
  comp omega[MAX];
  comp a1[MAX], a2[MAX];
  comp z1[MAX], z2[MAX];
 
  void fft(comp *a, comp *z, int m = N) {
    if (m == 1) {
      z[0] = a[0];
    } else {
      int s = N/m;
      m /= 2;
 
      fft(a, z, m);
      fft(a+s, z+m, m);
 
      REP(i, m) {
        comp c = omega[s*i] * z[m+i];
        z[m+i] = z[i] - c;
        z[i] += c;
      }
    }
  }
 
  void mult(value *a, value *b, value *c, int len) {
    N = 2*len;
    while (N & (N-1)) ++N;
    assert(N <= MAX);
 
    REP(i, N) a1[i] = 0;
    REP(i, N) a2[i] = 0;
    REP(i, len) a1[i] = a[i];
    REP(i, len) a2[i] = b[i];
 
    REP(i, N) omega[i] = polar(1.0, 2*pi/N*i);
    fft(a1, z1, N);
    fft(a2, z2, N);
 
    REP(i, N) omega[i] = comp(1, 0) / omega[i];
    REP(i, N) a1[i] = z1[i] * z2[i] / comp(N, 0);
    fft(a1, z1, N);
 
    REP(i, 2*len) c[i] = round(z1[i].real());
  }

  void mult2(int *a, int *b, int *c, int len) {
    // K = sqrt(mod)
    const int K = 1<<15;

    REP(i, 2*len) c[i] = 0;
    static value x[MAX], y[MAX], z[MAX];
    REP(ca, 2) REP(cb, 2) {
      REP(i, len) {
        x[i] = ca ? a[i] / K : a[i] % K;
        y[i] = cb ? b[i] / K : b[i] % K;
      }
      mult(x, y, z, len);
      int k = mul(ca ? K : 1, cb ? K : 1);
      REP(i, 2*len)
        c[i] = add(c[i], mul(k, z[i] % mod));
    }
  }
}

int f[MAX], invf[MAX];

vector<int> solve(llint n, int k) {
  if (n > k) return vector<int>(k + 1, 0);
  if (n == 0) {
    vector<int> ans(k + 1, 0);
    ans[0] = 1;
    return ans;
  }
  if (n == 1) {
    vector<int> ans(k + 1, 1);
    ans[0] = 0;
    return ans;
  }

  vector<int> a, b;
  int nb;
  if (n % 2 == 0) {
    a = b = solve(n / 2, k);
    nb = n / 2;
  } else {
    a = solve(n - 1, k);
    b = solve(1, k);
    nb = 1;
  }
  
  int pw = 1, base = powmod(2, nb);
  REP(i, k + 1) {
    a[i] = mul(a[i], invf[i]);
    b[i] = mul(b[i], invf[i]);
    a[i] = mul(a[i], pw);
    pw = mul(pw, base);
  }

  vector<int> c(2*(k+1), 0);
  FFT::mult2(&a[0], &b[0], &c[0], k + 1);
  REP(i, k + 1) c[i] = mul(c[i], f[i]);
  c.resize(k + 1);
  return c;
}

int main(void) {
  llint n;
  int k;
  scanf("%lld %d", &n, &k);

  f[0] = invf[0] = 1;
  FOR(i, 1, k + 1) {
    f[i] = mul(f[i-1], i);
    invf[i] = powmod(f[i], mod - 2);
  }

  vector<int> v = solve(n, k);
  int ans = 0;
  REP(i, k + 1) {
    int x = v[i];
    x = mul(x, f[k]);
    x = mul(x, mul(invf[i], invf[k-i]));
    ans = add(ans, x);
  }
  printf("%d\n", ans);
  return 0;
}