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

const int MAXN = 5005;

int a[MAXN];
int p[MAXN][MAXN];

void solve() {
  int n; cin >> n;
  REP(i, n) {
    cin >> a[i];
    a[i] --;
  }

  REP(i, n + 5) p[0][i] = 0;
  FOR(i, a[0], MAXN) p[0][i] = 1;

  FOR(i, 1, n) {
    REP(j, MAXN) {
      p[i][j] = p[i - 1][j];
      if (j) p[i][j] += p[i][j-1] - p[i-1][j-1];
      if (a[i] == j) p[i][j] ++;
    }
  }

  ll sol = 0;
  for (int b = 1; b < n; b++) for (int c = b + 1; c < n - 1; ++c) {
    int A = p[b - 1][a[c]];
    int D = p[n - 1][a[b]] - p[c][a[b]];
    sol += A * D;
  }

  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while (t --) solve();
}