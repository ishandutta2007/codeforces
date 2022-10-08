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
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  vector <int> vis(n, -1);
  s--;
  int gdzie = 0;
  t++;
  while(t--) {
    if(t % n == 0) {
      if(vis[s] != -1) break;
      vis[s] = ++gdzie;
    }
    if(s < m) s += t;
    else s -= t;
    s = (s%n+n)%n;
   }
   if(t == 0) {
     cout << s+1 << "\n";
     return 0;
   } else {
     gdzie++;
     ll la = t / n % (gdzie - vis[s]) + vis[s];
     for(int i=0; i<n; i++) {
       if(vis[i] == la) {
         cout << i+1 << "\n";
         return 0;
       }
    }
  }
}