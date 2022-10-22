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

const int mod = 998244353;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 1e6 + 5;

int a[MAXN];

int runda;

int calc(int i, int j) {
  int A = a[i];
  int B = a[j];

  assert(min(A, B) > 0);

  int ret = 1;
  FOR(k, i + 1, j) {
    if (a[k] == -1) ret = mul(ret, k + 1);
    else ret = mul(ret, min(k + 1, runda + 1));
  }

  return ret;
}

void solve() {
  int n, k; cin >> n >> k; runda = k;

  REP(i, n) a[i] = 0;
  REP(i, n - k) {
    cin >> a[i + k];
    if (a[i + k] > 0) a[i + k] += k;
  }

  REP(i, k) a[i] = -1;

  REP(i, n) {
    if (a[i] > i) {
      cout << 0 << endl;
      return;
    }
  }
  int arb, sol = 1;
  REP(i, k) {
    cin >> arb;
    if (arb > 0) {
      sol = 0;
    }
  }

  a[0] = n;
  a[n] = n;

  int last = 0;
  FOR(i, 1, n + 1) {
    if (a[i] > 0) {
      sol = mul(sol, calc(last, i));
      last = i;
    }
  }

  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while (t --) solve();
}