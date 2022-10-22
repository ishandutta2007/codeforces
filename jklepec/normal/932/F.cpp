#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long double lf;
typedef long long ll;
typedef pair<ll, ll> point;

const int off = 1 << 17, MAXN = 1e5 + 5;

int n;
vector<int> e[MAXN];

lf ccw(point a, point b, point c) {
  return (lf) a.first * (b.second - c.second) +
         (lf) b.first * (c.second - a.second) +
         (lf) c.first * (a.second - b.second);
}
int uk;
bool bio[2 * off];
vector<point> hull[2 * off];

void build(int x) {
  bio[x] = true;

  int N = hull[x * 2].size();
  int M = hull[x * 2 + 1].size();
  int i = 0, j = 0;

  while(i < N || j < M) {
    point p;
    if(j == M || i != N && hull[x * 2][i] < hull[x * 2 + 1][j]) {
      p = hull[x * 2][i];
      i ++;
    }
    else {
      p = hull[x * 2 + 1][j];
      j ++;
    }

    while(hull[x].size() >= 2 && ccw(hull[x][hull[x].size() - 2], hull[x].back(), p) <= 0) {
      hull[x].pop_back();
    }
    hull[x].push_back(p);
    uk ++;
  }
}

ll calc(point p, ll x) {
  return p.first * x + p.second;
}

ll ans(int i, ll x) {
  int lo = 0, hi = hull[i].size() - 1;
  while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(calc(hull[i][mid], x) < calc(hull[i][mid + 1], x)) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }
  return calc(hull[i][lo], x);
}

ll query(int x, int lo, int hi, int a, int b, int v) {
  if(lo >= a && hi <= b) {
    return ans(x, v);
  }
  if(lo >= b || hi <= a) {
    return (ll) 1e17;
  }

  int mid = (lo + hi) >> 1;
  return min(query(x * 2, lo, mid, a, b, v),
             query(x * 2 + 1, mid, hi, a, b, v));
}

int lo[MAXN], hi[MAXN], cookie;

void dfs(int u, int v) {
  lo[v] = cookie ++;
  for(auto w: e[v]) {
    if(u != w) dfs(v, w);
  }
  hi[v] = cookie;
}

ll dp[MAXN];

int a[MAXN], b[MAXN];

void solve(int u, int v) {
  for(auto w: e[v]) {
    if(u != w) solve(v, w);
  }

  dp[v] = 0;
  if(lo[v] != hi[v] - 1) {
    dp[v] = query(1, 0, off, lo[v] + 1, hi[v], a[v]);
  }

  hull[lo[v] + off].push_back({b[v], dp[v]});
  bio[lo[v] + off] = true;

  int x = (lo[v] + off) / 2;
  for(; x && bio[x * 2] && bio[x * 2 + 1]; x /= 2) build(x);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  REP(i, n - 1) {
    int x, y; cin >> x >> y;
    e[x - 1].push_back(y - 1);
    e[y - 1].push_back(x - 1);
  }

  dfs(0, 0);
  solve(0, 0);

  REP(i, n) {
    cout << dp[i] << " ";
  }
}