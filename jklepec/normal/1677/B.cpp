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

const int MAXN = 1e6 + 5;

int col[MAXN];
int row[MAXN];

int a[MAXN];

void solve() {
  int n, m; cin >> n >> m;

  int cols = 0, frow = 0;
  REP(i, n * m) col[i] = row[i] = 0;
  REP(i, n * m) {
    char c; cin >> c;
    a[i] = c - '0';

    frow += a[i];
    if (i >= m) frow -= a[i - m];

    col[i % m] += a[i];
    if (a[i] && col[i % m] == 1) cols ++;

    int tmprow = 0;
    if (frow) tmprow ++;
    if (i >= m) tmprow += row[i - m];

    row[i] = tmprow;

    cout << cols + tmprow << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}