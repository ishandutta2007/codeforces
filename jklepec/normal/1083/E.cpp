#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> point;

vector<pll> hull;

ll get(int i, ll x) {
  return hull[i].first * x + hull[i].second;
}

ll query(ll x) {
  int lo = 0, hi = hull.size() - 1;
  while(lo < hi) {
    int mi = (lo + hi) >> 1;
    if(get(mi, x) > get(mi + 1, x)) {
      hi = mi;
    }
    else {
      lo = mi + 1;
    }
  }

  return get(lo, x);
}

typedef long double lf;

lf ccw(pll a, pll b, pll c) {
  return (lf) a.first * (b.second - c.second) +
         (lf) b.first * (c.second - a.second) +
         (lf) c.first * (a.second - b.second);
}

void add(pll p) {
  while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p) <= 0.) hull.pop_back();
  hull.push_back(p);
}

const int MAXN = 1e6 + 5;

vector<pair<pll, ll>> pr;

ll sol;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) {
    ll x, y, c; cin >> x >> y >> c;
    pr.pb({{x, y}, c});
  }

  sort(pr.begin(), pr.end());

  add({0, 0});
  for(auto pp: pr) {
    ll tmp = pp.first.first * (pp.first.second) - pp.second;
    tmp += query(pp.first.second);

    sol = max(sol, tmp);
    add({-pp.first.first, tmp});
  }

  cout << sol << endl;
}