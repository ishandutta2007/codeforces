#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> point;

const int mod = 998244353;

const int MAXN = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  vector<point> v;

  v.pb({0, 0});
  v.pb({2, 0});
  v.pb({4, 0});
  v.pb({1, 1});
  v.pb({3, 1});
  v.pb({2, 2});
  REP(i, 1000) {
    v.pb({4 + 2 * i, 2});
    v.pb({5 + 2 * i, 1});
    v.pb({6 + 2 * i, 0});
  }

  int n; cin >> n;
  REP(i, n) {
    cout << v[i].fi _ v[i].se << '\n';
  }
}