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
const int maxn = 15010;
int n;

vector <pii> ans;

void run(int k, int de) {
  rep(i, 0, k - 1) {
    rep(j, 1, 1 << k) {
      rep(t, 0, (1 << i) - 1) {
        int x = j + t + de, y = j + t + (1 << i) + de;
        ans.push_back({x, y});
      }
      j += (1 << (i + 1)) - 1;
    }
  }
}

vector <int> vec[16];

void unite(vector <int> &v1, vector <int> &v2) {
  vector <int> tmp;
  for (int y : v1) {
    int x = v2.back();
    v2.pop_back(), ans.push_back({x, y}), tmp.push_back(x);
  }
  for (int x : tmp) v1.push_back(x);
}

void solve() {
  cin >> n;
  int cur = 1;
  per(i, 15, 0) if (n >> i & 1) {
    run(i, cur - 1);
    rep(j, 1, (1 << i)) vec[i].push_back(cur++);
  }
  static int id[16];
  rep(i, 0, 15) id[i] = i;
  sort(id, id + 16, [] (int x, int y) {
    return (int) vec[x].size() > (int) vec[y].size();
  });
  while (1) {
    sort(id + 1, id + 16, [] (int x, int y) {
      return (int) vec[x].size() > (int) vec[y].size();
    });
    int p1 = id[0], p2 = 0, p3 = 0;
    rep(i, 1, 15) if (!vec[id[i]].empty()) p2 = p3, p3 = id[i];
    if (!p2) break;
    while (vec[p2].size() > vec[p3].size()) {
      unite(vec[p3], vec[p1]);
    }
    unite(vec[p3], vec[p2]);
  }
  printf("%d\n", (int) ans.size());
  for (pii p : ans) printf("%d %d\n", p.first, p.second);
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}