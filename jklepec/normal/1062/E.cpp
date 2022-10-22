#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int off = 1 << 17, MAXN = 1e5 + 5, LOG = 18;

point tx[2 * off], tn[2 * off];

point getmx(int x, int lo, int hi, int a, int b) {
  if(lo >= a && hi <= b) {
    return tx[x];
  }
  if(lo >= b || hi <= a) {
    return {-1, 0};
  }
  int mid = (lo + hi) >> 1;
  return max(getmx(x * 2, lo, mid, a, b), getmx(x * 2 + 1, mid, hi, a, b));
}

point getmn(int x, int lo, int hi, int a, int b) {
  if(lo >= a && hi <= b) {
    return tn[x];
  }
  if(lo >= b || hi <= a) {
    return {MAXN, 0};
  }
  int mid = (lo + hi) >> 1;
  return min(getmn(x * 2, lo, mid, a, b), getmn(x * 2 + 1, mid, hi, a, b));
}

void updmx(int x, int v) {
  tx[x + off] = {v, x};
  x += off;
  for(x /= 2; x; x /= 2) tx[x] = max(tx[x * 2], tx[x * 2 + 1]);
}
void updmn(int x, int v) {
  tn[x + off] = {v, x};
  x += off;
  for(x /= 2; x; x /= 2) tn[x] = min(tn[x * 2], tn[x * 2 + 1]);
}

int par[MAXN][LOG];
int lo[MAXN], hi[MAXN];
int cookie, dub[MAXN];

vector<int> e[MAXN];

void dfs(int u, int v) {
  lo[v] = cookie ++;
  dub[v] = dub[u] + 1;
  par[v][0] = u;
  FOR(i, 1, LOG) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for(auto w: e[v]) {
    if(w != u) {
      dfs(v, w);
    }
  }
  hi[v] = cookie;
}

int tmp, kik;

void Try(int l, int r, int x) {
  point mn = min(getmn(1, 0, off, l, x), getmn(1, 0, off, x + 1, r));
  point mx = max(getmx(1, 0, off, l, x), getmx(1, 0, off, x + 1, r));

  int y = mn.second;

  if(mn.first == mx.first || mn.first == 0) {
    if(dub[y] > dub[tmp]) {
      tmp = y;
      kik = x;
    }
    return;
  }

  int lt = mn.first, rt = mx.first;

  for(int i = LOG - 1; i >= 0; --i) {
    int z = par[y][i];
    if(lo[z] > lt || hi[z] <= rt) y = z;
  }

  //cout << l _ r _ x _ y << endl;

  if(lo[y] > lt || hi[y] <= rt)
    y = par[y][0];

  if(dub[tmp] < dub[y]) {
    tmp = y;
    kik = x;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, q; cin >> n >> q;
  REP(i, n - 1) {
    int x; cin >> x; x --;
    e[x].pb(i + 1);
    e[i + 1].pb(x);
  }

  dfs(0, 0);

  REP(i, n) {
    updmx(i, lo[i]);
    updmn(i, lo[i]);
  }

  while(q --) {
    int l, r; cin >> l >> r;
    l --;
    kik = l;

    point mn = getmn(1, 0, off, l, r);
    point mx = getmx(1, 0, off, l, r);

//    cout << mn.first _ mn.second _ mx.first _ mx.second << endl;

    tmp = 0;

    Try(l, r, mn.second);
    Try(l, r, mx.second);

    cout << kik + 1 _ dub[tmp] - 1 << '\n';
  }
}