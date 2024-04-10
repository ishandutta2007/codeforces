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
typedef pair <int, int> pii;
const int maxn = 2e5 + 10;
int n;
ll A[maxn];

map <ll, vector <int> > mp;

int m;

struct node {
  int l, r;
} da[maxn];

void solve() {
  cin >> n;
  mp[0].push_back(0);
  rep(i, 1, n) {
    scanf("%lld", A + i);
    A[i] += A[i - 1];
    mp[A[i]].push_back(i);
  }
  for (auto p : mp) {
    vector <int> &vec = p.second;
    rep(i, 1, vec.size() - 1) {
      da[++m] = {vec[i - 1]+1, vec[i] - 1};
    }
  }
  sort(da + 1, da + m + 1, [] (node P, node Q) {
    return P.r < Q.r || (P.r == Q.r && P.l < Q.l);
//    return P.l < Q.l || (P.l == Q.l && P.r < Q.r);
  });
  int res = 0, tmp = -1;
  rep(i, 1, m) {
//    printf("(%d %d)\n", da[i].l, da[i].r);
//    f1=max(f1,da[i].r);
    if (tmp < da[i].l) {
      res++, tmp = da[i].r;
    }
  }
  cout << res << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}