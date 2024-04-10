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

const int MAXN = 1e5 + 5;

int a[MAXN];

vector<int> divs;
ll sol[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  int sum = 0;
  vector<int> v;
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
    if(a[i]) {
      v.pb(i);
    }
  }
  divs.pb(sum);
  for(int x = 2; x * x <= sum; ++x) {
    if(sum % x == 0) {
      divs.pb(x);
      if(x * x != sum) divs.pb(sum / x);
    }
  }
  if(sum <= 1) {
    cout << -1; return 0;
  }

  REP(i, v.size()) {
    for(auto x: divs) {
      int j = (i / x) * x;
      sol[x] += abs(v[i] - v[j + x / 2]);
    }
  }

  ll best = (ll) n * n;
  for(auto x: divs) best = min(best, sol[x]);
  cout << best << endl;
}