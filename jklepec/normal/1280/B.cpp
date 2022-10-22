#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

char c[65][65];

void solve() {
  int n, m; cin >> n >> m;
  int minx = n;
  int miny = m;
  int maxx = -1;
  int maxy = -1;
  int cnt = n * m;
  REP(i, n) {
    string s; cin >> s;
    REP(j, m) {
      c[i][j] = s[j];
      if(s[j] == 'A') {
        minx = min(i, minx);
        miny = min(j, miny);
        maxx = max(i, maxx);
        maxy = max(j, maxy);
        cnt --;
      }
    }
  }

  if(maxx == -1) {
    cout << "MORTAL" << endl;
    return;
  }

  int swipe = 4;
  if(c[0][0] == 'A' || c[0][m - 1] == 'A' || c[n - 1][0] == 'A' || c[n - 1][m - 1] == 'A') {
    swipe = 2;
    if(n == 1 || m == 1) {
      swipe = 1;
    }
    if(n == 1 && m == 1) {
      swipe = 0;
    }
  }

  if(!cnt) swipe = 0;

  if(n == 1 || m == 1) {
    swipe = min(swipe, 2);
  } else {
    if(minx == 0 || miny == 0 || maxx == n - 1 || maxy == m - 1) {
      swipe = min(swipe, 3);
    }
    for(int j = 0; j < m; ++j) {
      bool check = false;
      for(int i = 0; i < n; ++i) {
        if(c[i][j] != 'A') check = true;
      }
      if(!check) swipe = min(swipe, 2);
      if(!check && (j == 0 || j == m - 1)) swipe = min(swipe, 1);
    }

    for(int i = 0; i < n; ++i) {
      bool check = false;
      for(int j = 0; j < m; ++j) {
        if(c[i][j] != 'A') check = true;
      }
      if(!check) swipe = min(swipe, 2);
      if(!check && (i == 0 || i == n - 1)) swipe = min(swipe, 1);
    }
  }

  cout << swipe << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}