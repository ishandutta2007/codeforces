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

const int MAXN = 1e5 + 5, MAXM = 3e5 + 5;

ll d[MAXN];
int A[MAXM], B[MAXM];
ll sol[MAXM];

vector<int> poz;
vector<int> neg;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, m; cin >> n >> m;
  REP(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u] += w;
    d[v] -= w;
  }

  int solSz = 0;
  FOR(i, 1, n+1) {
    if(d[i] > 0) {
      poz.pb(i);
    } else if(d[i] < 0) {
      neg.pb(i);
    }
    d[i] = abs(d[i]);
  }

  int i = 0, j = 0;

  while(i < poz.size() && j < neg.size()) {
    int u = poz[i];
    int v = neg[j];
    A[solSz] = u;
    B[solSz] = v;
    sol[solSz ++] = min(d[u], d[v]);

    if(d[u] == d[v]) {
      i ++;
      j ++;
    } else if(d[u] > d[v]) {
      j ++;
      d[u] -= d[v];
    } else {
      i ++;
      d[v] -= d[u];
    }
  }

  cout << solSz << '\n';
  REP(i, solSz) {
    cout << A[i] _ B[i] _ sol[i] << '\n';
  }
}