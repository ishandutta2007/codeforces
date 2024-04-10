#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 5e5 + 10;

typedef pair <int, int> pii;
const int P1 = 1e9 + 7, P2 = 1e9 + 9;
int base, pow1[maxn], pow2[maxn];

struct Hash {
  int v1, v2;

  Hash() {}
  Hash(int x, int y) : v1(x), v2(y) {}

  void print() {
    printf("#(%d %d)\n", v1, v2);
  }
  
  void get(int x) {
    v1 = (1ll * v1 * base + x) % P1;
    v2 = (1ll * v2 * base + x) % P2;
  }

  bool operator == (const Hash &o) const {
    return v1 == o.v1 && v2 == o.v2;
  }

  bool operator != (const Hash &o) const {
    return v1 != o.v1 || v2 != o.v2;
  }
};

int n, m;
ll a[maxn];

map <ll, ll> S;
vector <int> E[maxn];

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

void solve() {
  cin >> n >> m;
  rep(i, 1, n) {
    E[i].clear();
    scanf("%I64d", a + i);
  }
  rep(i, 1, m) {
    int u = read(), v = read();
    E[v].push_back(u);
  }
  S.clear();
  rep(i, 1, n) {
    if (E[i].empty()) continue;
    sort(E[i].begin(), E[i].end());
    Hash val(0, 0);
    for (int x : E[i]) val.get(x);
    S[1ll * val.v1 * P2 + val.v2] += a[i];
  }
  ll res = 0;
  for (auto p : S) {
    res = gcd(res, p.second);
  }
  printf("%I64d\n", res);
}

int main() {
  base = Rnd();
  if (base < 0) base = -base;
  base %= 19260817, base += 257;
  pow1[0] = pow2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    pow1[i] = 1ll * base * pow1[i - 1] % P1;
    pow2[i] = 1ll * base * pow2[i - 1] % P2;
  }
  int T = read();
  while (T--) solve();
  return 0;
}