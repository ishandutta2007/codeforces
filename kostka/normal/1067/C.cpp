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

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[] = {-2, 2, -1, 1, 2, -2, 1, -1};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(0);
  int n;
  #ifdef LOCAL
    n = atoi(argv[1]);
  #else
    cin >> n;
  #endif

  set <pii> res;

  // queue <pii> Q;
  // set <pii> visited;
  // Q.emplace(0, 0);
  // visited.emplace(0, 0);
  // int nr = 0;
  // bool take = false;
  // while(!Q.empty()) {
  //   int x, y;
  //   tie(x, y) = Q.front();
  //   Q.pop();
  //   nr++;
  //   take |= (SZ(Q) >= n * n / 10 - n);
  //   // cerr << take << " " << SZ(Q) << "\n";
  //   if(take) res.emplace(x, y);
  //   if(SZ(res) == n) break;
  //   for(int i=0; i<8; i++) {
  //     int nx = x+dx[i], ny = y+dy[i];
  //     if(visited.find({nx, ny}) == visited.end()) {
  //       Q.emplace(nx, ny);
  //       visited.emplace(nx, ny);
  //     }
  //   }
  // }

  int d = n/6+1;
  for(int e=0; e<3; e++) {
    if(SZ(res) < n)  res.emplace(2*(d-e)+e, e);
    if(SZ(res) < n)  res.emplace(e, e);
    for(int i=1; i<d-e; i++) {
      if(SZ(res) < n) res.emplace(2*i+e, e);
      if(SZ(res) < n) res.emplace(e, 2*i+e);
    }
  }
  if(SZ(res) < n) res.emplace(1, 2*d-1);
  for(int i=0; i<3; i++) if(SZ(res) < n) res.emplace(i, 2*d-i);
  for(int i=0; i<3; i++) if(SZ(res) < n) res.emplace(i+2, 2*d-i);

  for(auto r : res) cout << r.x << " " << r.y << "\n";

  #ifdef LOCAL
    cerr << SZ(res) << "\n";
    assert(SZ(res) == n);
    while(true) {
      map <pii, int> M;
      for(auto r : res) {
        int x, y;
        tie(x, y) = r;
        for(int d=0; d<8; d++) M[make_pair(x+dx[d], y+dy[d])] += 1;
      }
      int pr = SZ(res);
      for(auto ele : M) {
        if(ele.y >= 4) res.insert(ele.x);
      }
      if(SZ(res) == pr) break;
    }
    cerr << "R" << SZ(res) << " " << n*n/10 << "\n";
    assert(SZ(res) >= n*n/10);
    for(auto r : res) cerr << r.x << " " << r.y << "\n";
  #endif

  return 0;
}