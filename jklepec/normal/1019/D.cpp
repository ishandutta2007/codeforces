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

const int MAXN = 2e3 + 5;

ll ccw(const point &a, const point &b, const point &c) {
  return (ll) a.fi * (b.se - c.se) +
         (ll) b.fi * (c.se - a.se) +
         (ll) c.fi * (a.se - b.se);
}

point p[MAXN];
int where[MAXN];

point operator - (const point &a, const point &b) {
  point c = {b.first - a.first, b.second - a.second};
  return c;
}

bool cmp2(point a, point b) {
  point c = p[a.se] - p[a.fi];
  point d = p[b.se] - p[b.fi];

  return ccw({0, 0}, c, d) > 0;
}

bool cmp(int x, int y) {
  if(p[x].se == p[y].se) return p[x].fi > p[y].fi;
  return p[x].se > p[y].se;
}

vector<int> ind;
vector<point> ev;

void ans(int i, int j, int k) {
  cout << "Yes\n";
  cout << p[i].fi _ p[i].se << '\n';
  cout << p[j].fi _ p[j].se << '\n';
  cout << p[k].fi _ p[k].se << '\n';
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  ll S; cin >> S; S *= 2;

  REP(i, n) {
    cin >> p[i].fi >> p[i].se;
    ind.pb(i);
  }

  sort(ind.begin(), ind.end(), cmp);
  REP(i, n) {
    where[ind[i]] = i;
  }

  REP(i, n) FOR(j, i + 1, n) {
    if(point(p[i].se, p[i].fi) < point(p[j].se, p[j].fi)) {
      ev.pb({i, j});
    }
    else {
      ev.pb({j, i});
    }
  }
  sort(ev.begin(), ev.end(), cmp2);

  for(auto pi: ev) {
    int i = pi.fi;
    int j = pi.se;

    swap(where[i], where[j]);
    swap(ind[where[i]], ind[where[j]]);

    ll dis2 = (p[i].fi - p[j].fi) * (p[i].fi - p[j].fi) + (p[i].se - p[j].se) * (p[i].se - p[j].se);
    ll dis = sqrt(dis2);

    //if(dis2 != dis * dis) continue;

    int ml = 1;
    REP(k, 2) {
      int lo = 0, hi = n - 1;
      while(lo < hi) {
        int mid = (lo + hi) >> 1;
        if(ccw(p[i], p[j], p[ind[mid]]) > S * ml) {
          lo = mid + 1;
        }
        else {
          hi = mid;
        }
      }
      if(ccw(p[i], p[j], p[ind[lo]]) == S * ml) {
        ans(i, j, ind[lo]);
      }
      ml *= 1;
    }
  }

  cout << "No\n";
}