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

ll foo(int n, int d) {
  return 1LL * n * (n - d + 2) / d / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <ll> ret;
  for(int i=1; i*i<=n; i++) {
    if(n % i == 0) {
      ret.emplace_back(foo(n, i));
      if(i * i != n) ret.emplace_back(foo(n, n/i));
    }
  }
  sort(ALL(ret));
  ret.erase(unique(ALL(ret)), ret.end());
  // cout << SZ(ret) << "\n";
  for(auto r : ret) cout << r << " ";
  cout << "\n";
  return 0;
}