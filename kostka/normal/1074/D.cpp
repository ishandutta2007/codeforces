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

map <int, int> rep, value;

int find(int x) {
  if(rep.find(x) == rep.end()) return x;
  int f = find(rep[x]);
  value[x] ^= value[rep[x]];
  return rep[x] = f;
}

void unia(int a, int b, int x) {
  // cerr << "UNIA " << a << " " << b << "\n";
  int fa = find(a), fb = find(b);
  if(fa == fb) return;
  value[fa] ^= x ^ value[b] ^ value[a];
  rep[fa] = fb;
}

int main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  int las = 0;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l ^= las;
      r ^= las;
      x ^= las;
      if(l > r) swap(l, r);
      unia(l, r+1, x);
    } else {
      int l, r;
      cin >> l >> r;
      l ^= las;
      r ^= las;
      if(l > r) swap(l, r);
      int fl = find(l), fr = find(r+1);
      if(fl != fr) {
        cout << -1 << "\n";
        las = 1;
      } else {
        // cerr << value[l] << " " << value[r+1] << "\n";
        int res = value[l] ^ value[r+1];
        cout << res << "\n";
        las = res;
      }
    }
  }
  return 0;
}