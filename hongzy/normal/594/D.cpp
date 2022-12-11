#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e6 + 10;
const int mod = 1e9 + 7;
int n, q, a[N], g[P], ig[P], last[P], pre[N], ans[N];
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int inv(int x) { return qpow(x, mod - 2); }
struct BIT {
  vector<int> c;
  int n;
  BIT(int sz) { c = vector<int>(1 + (n = sz), 1); }
  void add(int x, int y) {
    for(; x <= n; x += x & (-x))
      c[x] = (ll)c[x] * y % mod;
  }
  int qry(int x) {
    int ans = 1;
    for(; x >= 1; x &= x - 1)
      ans = (ll)ans * c[x] % mod;
      return ans;
  }
};
vector<int> prime[P];
vector<pii> v[N];
void insert(int pos, BIT &bit) {
  int cur = 1;
  for (auto x : prime[a[pos]]) {
    if(last[x]) bit.add(last[x], ig[x]);
    cur = (ll)cur * g[x] % mod;
    last[x] = pos;
  }
  bit.add(pos, cur);
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i);
  int mx = *max_element(a + 1, a + n + 1);
  pre[0] = 1;
  rep(i, 1, n) pre[i] = (ll)pre[i - 1] * a[i] % mod;
  vector<bool> vis(mx + 1);
  rep(i, 2, mx) if(!vis[i]) {
    prime[i].pb(i);
    g[i] = (i - 1ll) * inv(i) % mod;
    ig[i] = inv(g[i]);
    for (int j = i + i; j <= mx; j += i)
      prime[j].pb(i), vis[j] = 1;
  }
  scanf("%d", &q);
  rep(i, 1, q) {
    int l, r;
    scanf("%d%d", &l, &r);
    v[r].pb({l, i});
  }
  BIT bit(n + 1);
  rep(i, 1, n) {
    insert(i, bit);
    for(auto x : v[i]) {
      ans[x.sc] = (ll)pre[i] * bit.qry(i) % mod * inv((ll)pre[x.fs - 1] * bit.qry(x.fs - 1) % mod) % mod;
    }
  }
  rep(i, 1, q) printf("%d\n", ans[i]);
  return 0;
}