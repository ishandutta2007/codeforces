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

const int MAXN = 2e5 + 5;

int a[MAXN];

int kolko[MAXN];

unordered_map<ll, int> ima;

ll f(int x, int y) {
  return (ll) x * (1e9 + 1) + y;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) cin >> a[i + 1];

  ll sol = 0;
  REP(i, n) sol += a[i + 1];

  int q; cin >> q;
  REP(i, q) {
    int s, t, u;
    cin >> s >> t >> u;
    if(ima[f(s, t)]) {
      int u2 = ima[f(s, t)];
      kolko[u2] --;
      if(kolko[u2] < a[u2]) sol ++;
    }
    if(u != 0) {
      kolko[u] ++;
      if(kolko[u] <= a[u]) {
        sol --;
      }
    }
    ima[f(s, t)] = u;
    cout << sol << '\n';
  }
}