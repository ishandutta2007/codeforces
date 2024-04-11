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

const int MAXN = 2007;
bool taken[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vi A(2*n), P(2*n, -1);
  for(int i=0; i<2*n; i++) cin >> A[i];
  // sort(ALL(A));
  vector <pii> E;
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    E.emplace_back(a, b);
    P[a] = b;
    P[b] = a;
  }
  int t;
  cin >> t;
  t %= 2;
  int last = -1;
  for(int i=0; i<2*n; i++) {
    if(i%2 == t) {
      int pl;
      cin >> pl;
      taken[pl-1] = true;
      last = pl-1;
    } else {
      int pl = -1;
      if(last != -1 and P[last] != -1 and !taken[P[last]]) {
        pl = P[last];
      } else {
        for(auto e : E) {
          if(!taken[e.x] or !taken[e.y]) {
            pl = (A[e.x] > A[e.y] ? e.x : e.y);
            break;
          }
        }
        if(pl == -1) {
          for(int k=0; k<2*n; k++) {
            if(taken[k]) continue;
            if(pl == -1 or A[k] > A[pl]) pl = k;
          }
        }
      }
      cout << pl + 1 << endl;
      taken[pl] = true;
    }
  }
  return 0;
}