//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vi X(n), Y(n);
  for(int i=0; i<n; i++) cin >> X[i] >> Y[i];
  auto x = minmax_element(ALL(X));
  auto y = minmax_element(ALL(Y));
  int res = 0;
  auto check = [&](int a, int b, int c) {
    if(a == b or a == c or b == c) return;
    res = max(res, abs(X[a] - X[b]) + abs(X[b] - X[c]) + abs(X[c] - X[a]) +
                   abs(Y[a] - Y[b]) + abs(Y[b] - Y[c]) + abs(Y[c] - Y[a]));
  };
  for(int i=0; i<n; i++) {
    check(i, distance(X.begin(), x.y), distance(X.begin(), x.x));
    check(i, distance(X.begin(), x.y), distance(Y.begin(), y.x));
    check(i, distance(X.begin(), x.y), distance(Y.begin(), y.y));
    check(i, distance(X.begin(), x.x), distance(Y.begin(), y.x));
    check(i, distance(X.begin(), x.x), distance(Y.begin(), y.y));
    check(i, distance(Y.begin(), y.x), distance(Y.begin(), y.y));
  }
  cout << res << " ";
  for(int i=4; i<=n; i++) cout << 2 * (*x.y - *x.x + *y.y - *y.x) << " ";
  cout << "\n";
  return 0;
}