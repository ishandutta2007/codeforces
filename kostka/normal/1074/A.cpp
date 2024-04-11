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
  int n, m;
  cin >> n >> m;
  vi X(n), Y;
  for(int i=0; i<n; i++) cin >> X[i];
  X.push_back(1e9);
  sort(ALL(X));
  for(int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1) Y.push_back(b);
  }
  m = SZ(Y);
  sort(ALL(Y));
  int j = 0, res = n + m;
  for(int i=0; i<=n; i++) {
    while(j < m and Y[j] < X[i]) j++;
    res = min(res, i + m - j);
  }
  cout << res << "\n";
  return 0;
}