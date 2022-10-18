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

const int MAX = 1 << 20;
const double pi = acos(-1);

namespace FFT {
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
}

char s[MAX];
llint a[MAX], b[MAX], c[MAX];
vector<int> divs[MAX];

int main(void) {
  for (int i = 1; i < MAX/2; ++i) {
    for (int j = i; j < MAX/2; j += i) {
      divs[j].push_back(i);
    }
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    REP(i, n) {
      a[i] = s[i] == 'V';
      b[n-i-1] = s[i] == 'K';
    }

    FFT::mult(a, b, c, n);
    vector<bool> good(n+1, true);

    REP(i, 2*n-1) {
      int d = abs(i - (n - 1));
      if (c[i] > 0) {
        assert(d > 0);
        for (int x: divs[d]) good[x] = false;
      }
    }

    vector<int> ret;
    FOR(i, 1, n+1) if (good[i]) ret.push_back(i);

    printf("%d\n", (int)ret.size());
    for (int x: ret) printf("%d ", x);
    printf("\n");
  }
  
  return 0;
}