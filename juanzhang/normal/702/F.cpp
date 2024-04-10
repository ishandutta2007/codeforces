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
const int maxn = 2e5 + 10;
int n, m, ans[maxn];

struct node {
  int c, q;
} A[maxn];

struct gaygay {
  int x, tid;
} val[maxn];

int rt, ch[maxn][2];
int rnd[maxn], tag[maxn], sub[maxn];

void pushtag(int k, int x) {
  ans[val[k].tid] += x, tag[k] += x;
}

void pushsub(int k, int x) {
  val[k].x -= x, sub[k] += x;
}

void pushdown(int k) {
  int &x = tag[k], &y = sub[k];
  if (x) pushtag(ch[k][0], x), pushtag(ch[k][1], x), x = 0;
  if (y) pushsub(ch[k][0], y), pushsub(ch[k][1], y), y = 0;
}

void split(int k, int &x, int &y, int v) {
  if (!k) return x = y = 0, void();
  pushdown(k);
  if (val[k].x <= v) {
    x = k, split(ch[k][1], ch[x][1], y, v);
  } else {
    y = k, split(ch[k][0], x, ch[y][0], v);
  }
}

int merge(int x, int y) {
  if (!x || !y) return x | y;
  int res;
  pushdown(x), pushdown(y);
  if (rnd[x] < rnd[y]) {
    res = x, ch[res][1] = merge(ch[x][1], y);
  } else {
    res = y, ch[res][0] = merge(x, ch[y][0]);
  }
  return res;
}

vector <int> nod;

void getall(int k) {
  if (!k) return;
  pushdown(k);
  nod.push_back(k);
  getall(ch[k][0]), getall(ch[k][1]);
  ch[k][0] = ch[k][1] = 0;
}

void solve() {
  cin >> n;
  rep(i, 1, n) {
    A[i].c = read(), A[i].q = read();
  }
  sort(A + 1, A + n + 1, [] (node P, node Q) {
    return P.q > Q.q || (P.q == Q.q && P.c < Q.c);
  });
  cin >> m;
  rep(i, 1, m) {
    rnd[i] = Rnd();
    val[i] = {read(), i};
  }
  sort(val + 1, val + m + 1, [] (gaygay P, gaygay Q) {
    return P.x < Q.x;
  });
  rep(i, 1, m) {
    rt = merge(rt, i);
  }
  rep(i, 1, n) {
    int x, y, z;
    split(rt, x, y, 2 * A[i].c - 1);
    split(x, x, z, A[i].c - 1);
    pushsub(y, A[i].c), pushtag(y, 1);
    if (z) {
      nod.clear(), getall(z);
      for (int u : nod) {
        int x1, x2;
        ans[val[u].tid]++;
        val[u].x -= A[i].c;
        split(x, x1, x2, val[u].x);
        x = merge(merge(x1, u), x2);
      }
    }
    rt = merge(x, y);
  }
  getall(rt);
  rep(i, 1, m) printf("%d ", ans[i]);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}