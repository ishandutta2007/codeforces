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
int n, m, A[maxn], mp[maxn], lef[maxn], rig[maxn];

int par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

// val = max(1, i - delta)

void solve(int *ans) {
  rep(i, 1, n + m) par[i] = i, mp[i] = i;
  int delta = 0;
  rep(i, 1, m) {
    int pos = A[i];
    delta++;
    int &x = mp[pos + delta];
    int &y = mp[pos + delta + 1];
    if (!x) continue;
    if (!y) {
      y = x, x = 0;
    } else {
      par[find(x)] = find(y), x = 0;
    }
  }
  rep(i, 1, n + m) {
    ans[mp[i]] = max(1, i - m);
  }
  rep(i, 1, n) {
    ans[i] = ans[find(i)];
  }
}

int main() {
  cin >> n >> m;
  if (n == 1) return puts("0"), 0;
  rep(i, 1, m) A[i] = read();
  solve(lef);
  rep(i, 1, m) A[i] = n - A[i] + 1;
  solve(rig);
  reverse(rig + 1, rig + n + 1);
  rep(i, 1, n) rig[i] = n - rig[i] + 1;
  ll ans = 0;
  rep(i, 1, n) {
    ans += rig[i] - lef[i] + 1 + (lef[i] > 1) + (rig[i] < n);
  }
  cout << ans << endl;
  return 0;
}