#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < (int) b; ++i)
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

ll a[MAXN];

vector<ll> divs;
ll sol[MAXN];
ll pref[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  ll sum = 0;
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
    pref[i] = a[i];
    if(i) pref[i] += pref[i - 1];
  }
  if(sum <= 1) {
    cout << -1; return 0;
  }
  divs.pb(sum);
  for(ll x = 2; x * x <= sum; ++x) {
    if(sum % x == 0) {
      divs.pb(x);
      if(x * x != sum) divs.pb(sum / x);
    }
  }
  vector<ll> ndivs;
  REP(i, divs.size()) {
    bool ok = true;
    REP(j, i) if(divs[i] % divs[j] == 0) ok = false;
    if(ok) ndivs.pb(divs[i]);
  }

  REP(i, n) {
    ll L = pref[i];
    REP(j, ndivs.size()) {
      ll x = ndivs[j];
      sol[j] += min(L % x, x - L % x);
    }
  }

  ll best = sol[0];
  REP(j, ndivs.size()) best = min(best, sol[j]);
  cout << best << endl;
}