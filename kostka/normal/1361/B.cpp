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

const int MOD = 1'000'000'007;

int pot(int a, int b, int m) {
  if(b==0) return 1;
  ll p = pot(a,b/2,m);
  if(b&1) return p*p%m*a%m;
  return p*p%m;
}

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    int n, p;
    cin >> n >> p;
    map <int, int> M, E;
    for (int i=0; i<n; i++) {
      int k;
      cin >> k;
      M[k]++;
    }
    if(p == 1) {
      cout << n%2 << "\n";
      continue;
    }
    vector <pii> MM(M.rbegin(), M.rend());
    bool plus = false;
    ll ret = 0;
    for (auto [a, b] : MM) {
      while(b--) {
        if(plus) {
          // cerr << "- " << a << "\n";
          ret -= pot(p, a, MOD)%MOD;
          ret %= MOD;
          E[a]--;
          if (E[a] == 0) E.erase(a);
          else {
            int w = a;
            while (E.find(w) != E.end() and E[w] == -p) {
              E.erase(w);
              w++;
              E[w]--;
              if (E[w] == 0) E.erase(w);
            }
          }
          if (E.empty()) plus = false;
        } else {
          // cerr << "+ " << a << "\n";
          ret += pot(p, a, MOD)%MOD;
          ret %= MOD;
          E[a]++;
          plus = true;
        }
      }
    }
    cout << (ret+MOD)%MOD << "\n";
  }
  return 0;
}