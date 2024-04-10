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
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 5e5 + 10;
int n, k, A[maxn];

struct DSU {
  int par[maxn];
  
  void init() {
    rep(i, 0, maxn - 1) par[i] = i;
  }
  
  int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }
} pre, suf;

int cnt[maxn];
bool vis[maxn];

typedef pair <int, int> pii;

priority_queue <pii, vector <pii>, greater <pii> > Q;

void solve() {
  cin >> k >> n;
  rep(i, 1, n) A[i] = read();
  sort(A + 1, A + n + 1);
  rep(i, 1, n - 1) A[i] = A[i + 1] - A[i];
  A[n--] = 0;
  per(i, n + 1, 2) A[i] = A[i - 1];
  A[1] = 1e9, A[n += 2] = 1e9;
//  rep(i, 1, n) printf("%d%c", A[i], "\n "[i < n]);
  pre.init(), suf.init();
  rep(i, 1, n) Q.push({A[i], i}), cnt[i] = 1;
  int res = 0;
  while (k) {
    pii p = Q.top();
    int pos = p.second;
    Q.pop();
    if (vis[pos]) continue;
    k -= cnt[pos];
//    printf("!%d\n" ,k);
    int l = pre.find(pos - 1);
    int r = suf.find(pos + 1);
    res += A[pos];
//    printf("#(%d %d) (%d %d) ", pos, A[pos], l, r);
    A[pos] = A[l] + A[r] - A[pos];
    cnt[pos] = cnt[l] + cnt[r] - cnt[pos];
//    printf("%d %d\n", A[pos], cnt[pos]);
    Q.push({A[pos], pos});
    vis[l] = vis[r] = 1, cnt[l] = cnt[r] = 0, A[l] = A[r] = 0;
    if (l >= 1) pre.par[pre.find(l)] = pre.find(l - 1);
    if (l <= n) suf.par[suf.find(l)] = suf.find(l + 1);
    if (r >= 1) pre.par[pre.find(r)] = pre.find(r - 1);
    if (r <= n) suf.par[suf.find(r)] = suf.find(r + 1);
  }
  cout << res << endl;
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}