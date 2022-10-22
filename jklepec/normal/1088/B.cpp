#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

#define fi first
#define se second

const int mod = 1e9 + 7;
int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

const int MAXN = 1e5 + 5;
int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> v;
  REP(i, n) {
    cin >> a[i];
    v.pb(a[i]);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  vector<int> sol;

  REP(i, k) {
    if(i == v.size()) break;
    sol.pb(v[i] - (i ? v[i - 1] : 0));
  }

  REP(i, sol.size() - k) sol.pb(0);

  REP(i, k) cout << sol[i] << '\n';
}