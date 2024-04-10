#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

int x;

const int MAXN = 2e5 + 5, inf = 2e9 + 5;

vector<point> v[MAXN];
set<point> s[MAXN];

void solve(int i) {
  sort(v[i].begin(), v[i].end());

  int mn = inf;
  for(auto p: v[i]) {
    mn = min(mn, p.second);
    s[i].insert(point(p.first, mn));
  }
}

int l[MAXN], r[MAXN], c[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n >> x;

  REP(i, n) {
    cin >> l[i] >> r[i] >> c[i];

    v[r[i] - l[i] + 1].push_back(point(r[i], c[i]));
  }

  REP(i, MAXN) {
    solve(i);
  }

  int sol = inf;

  REP(i, n) {
    if(r[i] - l[i] + 1 >= x) continue;

    int need = x - r[i] + l[i] - 1;

    if(s[need].upper_bound(point(l[i] - 1, inf)) == s[need].begin()) continue;

    sol = min(sol, c[i] + (*(--s[need].upper_bound(point(l[i] - 1, inf)))).second);
  }

  cout << (sol == inf ? -1 : sol);
}