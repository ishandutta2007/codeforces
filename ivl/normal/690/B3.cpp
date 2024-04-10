#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define pb push_back
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pt;


int N, M;

ll ccw(pt a, pt b, pt c) {
  return (ll)a.x*(b.y-c.y) + (ll)b.x*(c.y-a.y) + (ll)c.x*(a.y-b.y);
}

vector<pt> convex_hull(vector<pt> P) {
  sort(P.begin(), P.end());
  
  vector<pt> H;
  REP(step, 2) {
    int start = (int)H.size();
    for (auto p : P) {
      while ((int)H.size() >= start + 2 && ccw(H[H.size()-2], H.back(), p) >= 0)
        H.pop_back();
      H.push_back(p);
    }
    
    reverse(P.begin(), P.end());
    H.pop_back();
  }
  
  return H;
}

inline bool pt_in_triangle(pt p, pt a, pt b, pt c) {
  return abs(ccw(p, a, b)) + abs(ccw(p, b, c)) + abs(ccw(p, a, c))
      == abs(ccw(a, b, c));
}

inline bool inside(int x, int y, vector<pt> &cv) {
  pt p = {x, y};
  int n = (int)cv.size();
  int lo = 1, hi = n - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (ccw(cv[0], cv[mid], p) < 0) lo = mid + 1;
    else hi = mid;
  }
  return (lo <= n-2 && pt_in_triangle(p, cv[0], cv[lo], cv[lo+1]))
      || (lo >= 2 && pt_in_triangle(p, cv[0], cv[lo], cv[lo-1]));
}

void solve() {
  vector<pt> P;
  REP(i, M) {
    int u, v; cin >> u >> v;
    P.pb({u, v});
  }
  
  vector<pt> CP = convex_hull(P);
  vector<pt> H;
  
  auto check = [&](int x, int y) {
    REP(dx, 2) REP(dy, 2)
      if (!inside(x+dx, y+dy, CP))
        return;
    H.pb({x, y});
  };
  
  for (auto it : P) {
    for (int dx = -1; dx <= 0; ++dx)
      for (int dy = -1; dy <= 0; ++dy)
        check(it.x + dx, it.y + dy);
  }
  
  H = convex_hull(H);
  cout << (int)H.size() << endl;
  for (auto it : H) cout << it.x << " " << it.y << endl;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  
  while ((cin >> N >> M) && N) {
    solve();
  }

  
  return 0; 
}