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
const int maxn = 2e5 + 10;
int n;

priority_queue <ll, vector <ll>, greater <ll> > Q;

int main() {
  n = read();
  rep(i, 1, n) {
    int x = read();
    Q.push(x);
  }
  ll res = 0;
  if (n % 2 == 0) {
    ll x = Q.top(); Q.pop();
    ll y = Q.top(); Q.pop();
    res += x + y, Q.push(x + y);
  }
  while (Q.size() > 2) {
    ll x = Q.top(); Q.pop();
    ll y = Q.top(); Q.pop();
    ll z = Q.top(); Q.pop();
    res += x + y + z, Q.push(x + y + z);
  }
  cout << res;
  return 0;
}