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
  vi l(n), p(n), ret(n, n);
  for(int i=0; i<n; i++) {
    cin >> l[i];
    ret[i] -= l[i];
  }
  for(int i=0; i<n; i++) {
    cin >> p[i];
    ret[i] -= p[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<i; j++) if(ret[j] > ret[i]) l[i]--;
    for(int j=i+1; j<n; j++) if(ret[j] > ret[i]) p[i]--;
    if(l[i] or p[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for(auto r : ret) cout << r << " ";
  cout << "\n";
  return 0;
}