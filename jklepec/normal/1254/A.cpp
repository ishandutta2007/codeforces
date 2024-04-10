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

string s;

const int MAXN = 5e3 + 5;

char p[MAXN][MAXN];
char sol[MAXN][MAXN];

void solve() {
  int r, c; cin >> r >> c;
  int k; cin >> k;
  int ch = 0;
  REP(i, r) {
    REP(j, c) {
      cin >> p[i][j];
      if(p[i][j] == 'R') {
        ch ++;
      }
    }
  }
  int tmp = 0;
  int need = ch / k;
  int ima = 0;
  REP(i, r) {
    if(i % 2) {
      for(int j = c - 1; j >= 0; --j) {
        sol[i][j] = s[tmp];
        if(p[i][j] == 'R') {
          ima ++;
          ch --;
        }
        if(ima == need && k > 1) {
          ima = 0;
          k --;
          tmp ++;
          need = ch / k;
        }
      }
    }
    else {
      for(int j = 0; j < c; ++j) {
        sol[i][j] = s[tmp];
        if(p[i][j] == 'R') {
          ima ++;
          ch --;
        }
        if(ima == need && k > 1) {
          ima = 0;
          k --;
          tmp ++;
          need = ch / k;
        }
      }
    }
  }
  REP(i, r) {
    REP(j, c) cout << sol[i][j];
    cout << '\n';
  }
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  REP(i, 26) {
    s += 'a' + i;
    s += 'A' + i;
  }
  REP(i, 10) {
    s += '0' + i;
  }

  int t; cin >> t;
  while(t --) {
    solve();
  }
}