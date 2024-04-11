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
  int la, ra, ta, lb, rb, tb;
  cin >> la >> ra >> ta >> lb >> rb >> tb;
  if(la > lb) {
    swap(la, lb);
    swap(ra, rb);
    swap(ta, tb);
  }
  int g = __gcd(ta, tb);
  ra += (lb - la) / g * g;
  la += (lb - la) / g * g;
  int res = 0;
  res = max(res, min(ra, rb) - max(la, lb) + 1);
  res = max(res, min(ra + g, rb) - max(la + g, lb) + 1);
  cout << res << "\n";
  return 0;
}