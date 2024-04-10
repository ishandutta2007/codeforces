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
typedef long double db;
const int maxn = 1e5 + 10;
ll k;
int n, A[maxn], B[maxn];

ll getval(int i, int x) {
  return A[i] - 3ll * x * x + 3ll * x - 1;
}

ll check(ll val) {
  ll sum = 0;
  rep(i, 1, n) {
    int l = 1, r = A[i], mid, res = 0;
    while (l <= r) {
      mid = (l + r) >> 1;
      getval(i, mid) >= val ? l = (res = mid) + 1 : r = mid - 1;
    }
    B[i] = res, sum += res;
  }
  return sum;
}

struct cmp {
  bool operator () (int x, int y) {
    return getval(x, B[x] + 1) < getval(y, B[y] + 1);
  }
};

void solve() {
  cin >> n >> k;
  rep(i, 1, n) A[i] = read();
  ll l = -4e18, r = 1e18, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    check(mid) <= k ? r = mid : l = mid + 1;
  }
  ll sum = check(l);
  priority_queue <int, vector <int>, cmp> Q;
  rep(i, 1, n) {
    if (B[i] < A[i]) Q.push(i);
  }
  while (sum < k) {
    int i = Q.top();
    Q.pop(), sum++, B[i]++;
    if (B[i] < A[i]) Q.push(i);
  }
  rep(i, 1, n) printf("%d ", B[i]);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}