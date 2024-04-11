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

struct pt {
  int x, y;
  pt(int _x, int _y) : x(_x), y(_y) {}

  pt rotate() {
    return {y, -x};
  }
  pt operator+(const pt& other) {
    return pt(x + other.x, y + other.y);
  }
  pt operator-(const pt& other) {
    return pt(x - other.x, y - other.y);
  }
};

int n, m;
int tab[27][27];

pt foo(int x) {
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
    if(tab[i][j] == x) return pt(i, j);
  }
  assert(false);
}

vector <vi> ret;

void mov(const vector <pt> &X) {
  vi C;
  for(auto x : X) {
    // cerr << x.x << " " << x.y << " ";
    C.push_back(tab[x.x][x.y]);
  }
  // cerr << "\n";
  ret.push_back(C);
  rotate(C.begin(), C.end()-1, C.end());
  for(int i=0; i<SZ(X); i++) {
    tab[X[i].x][X[i].y] = C[i];
  }
}

bool valid(pt a) {
  return 0 <= a.x and a.x < n and 0 <= a.y and a.y < m;
}

void cyc(pt a, pt b, pt c) {
  pt d = b - a + b;
  pt e = b + c - a;
  pt f = d + c - a;
  mov({a, b, e, c});
  mov({b, d, f, e});
  mov({c, e, f, d, b, a});
}

void swp(pt a, pt b) {
  // cerr << "SWP\n";
  if(!valid(b-a+b)) swap(a, b);
  pt change = (a-b).rotate();
  pt c = a + change;
  if(!valid(c)) c = a - change;
  cyc(a, b, c);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> tab[i][j];
      tab[i][j]--;
    }
  }
  for(int i=0; i<n*m; i++) {
    pt cur = foo(i), doc = {i/m, i%m};
    int dy = (cur.y < doc.y) ? 1 : -1;
    // cerr << "I" << i << "\n";
    while(cur.y != doc.y) {
      // cerr << "HERE\n";
      if(cur.x < n-1) mov({cur, cur+pt(0, dy), cur+pt(1, dy), cur+pt(1,0)});
      else if(cur.x > doc.x + 1) mov({cur, cur+pt(0, dy), cur+pt(-1, dy), cur+pt(-1, 0)});
      else swp(cur, cur+pt(0, dy));
      cur.y += dy;
    }
    while(cur.x > doc.x) {
      // cerr << "THERE\n";
      if(cur.y < m-1) mov({cur, cur+pt(-1, 0), cur+pt(-1, 1), cur+pt(0, 1)});
      else swp(cur, cur + pt(-1, 0));
      cur.x--;
    }
  }
  cout << SZ(ret) << "\n";
  for(auto rr : ret) {
    cout << SZ(rr) << " ";
    for(auto r : rr) cout << r+1 << " ";
    cout << "\n";
  }

  return 0;
}