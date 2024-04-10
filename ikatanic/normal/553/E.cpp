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

const int MAXBUFF = 1<<20;

namespace IO {
  char buffer[MAXBUFF], *p = buffer+MAXBUFF;
  
  inline char read_char() {
    if (p == buffer+MAXBUFF) {
      fread(buffer, 1, MAXBUFF, stdin);
      p = buffer;
    }
    return *p++;
  }
  
  inline int read_int() {
    char c;
    while (!isdigit(c = read_char()));
    int ret = c-'0';
    while (isdigit(c = read_char())) ret = ret*10 + c-'0';
    return ret;
  }
};

typedef long long llint;
typedef complex<double> fft_t;

const int MAXT = 1<<16;
const double pi = acos(-1);

namespace FFT {
  const int MAX = 1 << 16;
 
  typedef double value;
  typedef complex<double> comp;
 
  int N;
  comp *omega;
  comp a1[MAX], a2[MAX];
  comp z1[MAX], z2[MAX];
 
  comp omegas[17][MAX], omegasr[17][MAX];

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
    if (len <= 32) {
      REP(i, 2*len-1) c[i] = 0;
      REP(i, len) REP(j, len) c[i + j] += a[i] * b[j];
      return;
    }

    int k = 0;
    while ((1<<k) < len) k++;
    assert((1<<k) == len);

    N = 2*len;
    k++;
    assert(N <= MAX);
 
    REP(i, N) a1[i] = 0;
    REP(i, N) a2[i] = 0;
    REP(i, len) a1[i] = a[i];
    REP(i, len) a2[i] = b[i];
 
    omega = omegas[k];
    fft(a1, z1, N);
    fft(a2, z2, N);
    omega = omegasr[k];

    REP(i, N) a1[i] = z1[i] * z2[i] / comp(N, 0);
    fft(a1, z1, N);
 
    REP(i, 2*len) c[i] = z1[i].real();
  }

  void init() {
    REP(k, 17) {
      int N = 1<<k;
      REP(i, N) omegas[k][i] = polar(1.0, 2*pi/N*i);
      REP(i, N) omegasr[k][i] = comp(1, 0) / omegas[k][i];
    }
  }
}

const int MAXN = 110;

struct FFT_Online {
  double A[MAXT], B[MAXT], C[MAXT];
  int N, cur;
  
  void init(double *a, int n) {
    for (N = 1; N < n; N *= 2);
    REP(i, 2*N) A[i] = B[i] = C[i] = 0;
    REP(i, n) A[i] = a[i];
    cur = 0;
  }

  double next(double b) {
    B[cur] = b;
    C[cur] += B[cur] * A[0];
    for (int i = 0; (1<<i) < N && cur > 0 && cur % (1<<i) == 0; ++i) {
      static double tmp[MAXT];
      int len = 1<<i;
      FFT::mult(B + cur - len, A + len, tmp, len);
      REP(j, 2*len-1) C[cur + j] += tmp[j];
    }
    return C[cur++];
  }
  
  void finish() {
    while (cur <= N) next(0);
  }
} w[MAXN];

const double inf = 1e100;

vector<int> E[MAXN];

double p[MAXN][MAXT];
double f[MAXN][MAXT];
double g[MAXN][MAXT];
double d[MAXN][MAXN];
double rem[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
int n, m, T, G;

int too_late(int x) {
  return d[x][n - 1] + G;
}

int main(void) {
  FFT::init();

  scanf("%d %d %d %d", &n, &m, &T, &G);
  REP(i, m) {
    a[i] = IO::read_int();
    b[i] = IO::read_int();
    c[i] = IO::read_int();

    --a[i], --b[i];
    E[a[i]].push_back(i);
    REP(j, T) {
      int x = IO::read_int();
      p[i][j] = x / 1e5;
    }
  }
  
  REP(i, n) REP(j, n) d[i][j] = i == j ? 0 : inf;
  REP(i, m) d[a[i]][b[i]] = c[i];
  REP(k, n) REP(i, n) REP(j, n)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  
  REP(i, m) w[i].init(p[i], T+1);
  REP(i, n) f[i][0] = i == n-1 ? 0 : too_late(i);
  REP(i, m) g[i][0] = c[i] + too_late(b[i]);
  REP(i, m) w[i].next(0);
  REP(i, m) rem[i] = 1.0;

  for (int t = 1; t <= T; ++t) {
    REP(i, m) {
      rem[i] -= p[i][t - 1];
      g[i][t] = c[i] + rem[i] * too_late(b[i]) + w[i].next(f[b[i]][t - 1]);
    }
    REP(i, n-1) {
      f[i][t] = too_late(i);
      for (int e: E[i])
        f[i][t] = min(f[i][t], g[e][t]);
    }
    f[n-1][t] = 0;
  }

  printf("%.10lf\n", f[0][T]);
  return 0;
}