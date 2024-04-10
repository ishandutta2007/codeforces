#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int P = 998244353, Q = P - 1, R = 3;
const int N = 110;

int k;

struct Mat {
  int g[N][N];

  Mat() { memset(g, 0, sizeof(g)); }

  Mat(const Mat& rhs) { memcpy(g, rhs.g, sizeof(g)); }

  int*operator[](int ind) { return g[ind]; }
  const int*operator[](int ind)const { return g[ind]; }

  Mat operator*(const Mat& rhs) const {
    Mat ret = Mat();
    for (int i = 1; i <= k; ++i)
      for (int j = 1; j <= k; ++j)
        for (int l = 1; l <= k; ++l)
          ret[i][j] = (ret[i][j] + g[i][l] * (ll)rhs[l][j]) % Q;
    return ret;
  }
};

int b;
unordered_map<ll, ll> giant;

int mpow(ll a, ll k, int m) {
  ll ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)a % m;
    a = a * (ll)a % m;
    k >>= 1;
  }
  return ret;
}

int ggcd;

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    ggcd = a;
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int ford(int v) {
  b = sqrt(Q);
  ll step = mpow(R, b, P), prod = 1;
  for (int i = 0; i * (ll)b < Q; ++i) {
    unordered_map<ll, ll>::iterator it = giant.find(prod);
    if (it != giant.end())
      break;
    giant[prod] = i * (ll)b;
    prod = prod * (ll)step % P;
  }
  prod = v;
  int ans = Q;
  unordered_map<ll, ll>::iterator it;
  for (int i = 0; i < b; ++i) {
    it = giant.find(prod);
    if (it != giant.end()) {
      ans = it->second - i;
      break;
    }
    prod = prod * (ll)R % P;
  }
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &k);
  Mat gen = Mat();
  for (int i = 1; i < k; ++i)
    gen[i][i + 1] = 1;
  for (int i = 1; i <= k; ++i)
    scanf("%d", &gen[i][1]);
  Mat res = Mat();
  for (int i = 1; i <= k; ++i)
    res[i][i]= 1;
  int n, m;
  scanf("%d%d", &n, &m);
  n -= 1;
  while (n) {
    if (n & 1)
      res = res * gen;
    if (n >>= 1)
      gen = gen * gen;
  }
  int ord = res[1][k];
  int ind = ford(m);
  int x, y;
  exGcd(ord, Q, x, y);
  //LOG("DIV %d %d inmod %d\n", ind, ord, Q);
  int inv = x;
  if (inv < 0)
    inv += Q;
  if (ind % ggcd != 0)
    puts("-1");
  else
    printf("%d\n", mpow(R, (ind / ggcd) * (ll)inv % Q, P));

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}