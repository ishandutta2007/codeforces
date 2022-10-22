#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 5, LOG = 19, off = 1 << 19;

pii t[LOG][2 * off];

void upd(int x, pii p, int lg) {
  for(x += off; x; x /= 2) {
    t[lg][x].first = min(t[lg][x].first, p.first);
    t[lg][x].second = max(t[lg][x].second, p.second);
  }
}

pii get(int x, int lo, int hi, int a, int b, int lg) {
  if(lo >= a && hi <= b) {
    return t[lg][x];
  }
  if(lo >= b || hi <= a) {
    return {off, 0};
  }
  int mid = (lo + hi) >> 1;
  pii lson = get(x * 2, lo, mid, a, b, lg);
  pii rson = get(x * 2 + 1, mid, hi, a, b, lg);

  return pii(min(lson.first, rson.first), max(lson.second, rson.second));
}

int r[MAXN];
pii par[MAXN][LOG];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  REP(i, n) {
    cin >> r[i];
  }

  if(n == 1) {
    cout << 0;
    return 0;
  }

  REP(i, 2 * off) REP(lg, LOG) {
    t[lg][i].first = off;
  }

  REP(i, n) REP(j, 3) {
    par[i + j * n][0].first = max(0, i + j * n - r[i]);
    par[i + j * n][0].second = min(3 * n - 1, i + j * n + r[i]);

    upd(i + j * n, par[i + j * n][0], 0);
  }

  FOR(lg, 1, LOG) {
    FOR(i, n, 2 * n) {
      par[i][lg] = get(1, 0, off, par[i][lg - 1].first, par[i][lg - 1].second + 1, lg - 1);
    }
    REP(i, n) {
      par[i][lg].first = max(0, par[i + n][lg].first - n);
      par[i][lg].second = min(3 * n - 1, par[i + n][lg].second - n);
    }
    FOR(i, 2 * n, 3 * n) {
      par[i][lg].first = max(0, par[i - n][lg].first + n);
      par[i][lg].second = min(3 * n - 1, par[i - n][lg].second + n);
    }
    REP(i, 3 * n) {
      upd(i, par[i][lg], lg);
    }
  }

  REP(j, n) {
    int i = n + j;

    int lo = i, hi = i, sol = 0;
    for(int lg = LOG - 1; lg >= 0; --lg) {
      pii res = get(1, 0, off, lo, hi + 1, lg);
      if(res.second - res.first + 1 < n) {
        lo = res.first;
        hi = res.second;
        sol += (1 << lg);
      }
    }

    cout << sol + 1 << endl;
  }

}