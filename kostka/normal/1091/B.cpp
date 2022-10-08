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
  vector <pii> A(n), B(n);
  for(int i=0; i<n; i++) cin >> A[i].x >> A[i].y;
  sort(A.begin(), A.end());
  for(int i=0; i<n; i++) cin >> B[i].x >> B[i].y;
  for(int i=0; i<n; i++) {
    pii treasure = make_pair(A[0].x + B[i].x, A[0].y + B[i].y);
    vector <pii> C;
    for(int j=0; j<n; j++) {
      C.emplace_back(treasure.x - B[j].x, treasure.y - B[j].y);
    }
    sort(C.begin(), C.end());
    if(A == C) {
      cout << treasure.x << " " << treasure.y << "\n";
      return 0;
    }
  }
  return 0;
}