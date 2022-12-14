#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <complex>
#include <algorithm>

typedef std::complex<double> Complex;

const int N = 524288;
const double PI = acos(-1.);

int n, m, k;

char s[N], t[N];

std::vector<int> pos[4];

int trans(char ch) {
  switch (ch) {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
  }
}

void init() {
  static int cnt[4];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= k; ++i) ++cnt[s[i]];
  for (int i = 1; i <= n; ++i) {
    if (i + k <= n) ++cnt[s[i + k]];
    for (int j = 0; j < 4; ++j) if (cnt[j]) pos[j].push_back(i);//, fprintf(stderr, "%d %d\n", j, i);
    if (i - k > 0) --cnt[s[i - k]];
  }
}

void fft(Complex *a) {
  for (int i = 0, j = 0; i < N; ++i) {
    if (i < j) std::swap(a[i], a[j]);
    for (int k = (N >> 1); (j ^= k) < k;) k >>= 1;
  }
  for (int m = 2; m <= N; m *= 2) {
    int gap = m / 2;
    double arg = 2. * PI / m;
    Complex w(cos(arg), sin(arg));
    for (int i = 0; i < N; i += m) {
      Complex o(1., 0.);
      for (int j = i; j < i + gap; ++j, o *= w) {
        Complex u = a[j], v = o * a[j + gap];
        a[j] = u + v;
        a[j + gap] = u - v;
      }
    }
  }
}

template <typename T> inline T sqr(const T &x) { return x * x; }

void solve(int x, bool res[]) {
  static bool a[N], b[N];
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  for (int i = 0; i < pos[x].size(); ++i) a[pos[x][i]] = true;
  for (int i = 1; i <= m; ++i) b[i] = (t[m - i + 1] == x);
  static Complex c[N], temp[N + 1];
  for (int i = 0; i < N; ++i) temp[i] = Complex(!a[i], b[i]);
  fft(temp);
  temp[N] = temp[0];
  Complex inv(0., .25);
  for (int i = 0; i < N; ++i) c[i] = (sqr(std::conj(temp[N - i])) - sqr(temp[i])) * inv;
  fft(c);
  std::reverse(c + 1, c + N);
  for (int i = 1; i + m - 1 <= n; ++i) res[i] = (7. * c[m + i].real() < N);
}

int main() {
  scanf("%d%d%d %s %s", &n, &m, &k, s + 1, t + 1);
  for (int i = 1; i <= n; ++i) s[i] = trans(s[i]);
  for (int i = 1; i <= m; ++i) t[i] = trans(t[i]);
  init();
  static bool res[4][N];
  for (int i = 0; i < 4; ++i) solve(i, res[i]);
  int ans = 0;
  for (int i = 1; i + m - 1 <= n; ++i) if (res[0][i] && res[1][i] && res[2][i] && res[3][i]) ++ans;
  printf("%d\n", ans);
  return 0;
}