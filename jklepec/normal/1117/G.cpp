#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int off = 1 << 20, MAXN = 1e6 + 5;
pii t[2 * off];
pii get(int x, int lo, int hi, int a, int b) {
  if(lo >= a && hi <= b) {
    return t[x];
  }
  if(lo >= b || hi <= a) {
    return {-1, -1};
  }
  int mid = (lo + hi) >> 1;
  return max(get(x * 2, lo, mid, a, b), get(x * 2 + 1, mid, hi, a, b));
}
void upd(int x, int v) {
  x += off;
  t[x] = {v, x - off};

  for(x /= 2; x; x /= 2) {
    t[x] = max(t[x * 2], t[x * 2 + 1]);
  }
}

ll sol[MAXN];

int lft[MAXN], rgt[MAXN];

void rek(int lo, int hi) {
  if(lo > hi) return;
  int mi = get(1, 0, off, lo, hi + 1).second;
  lft[mi] = lo;
  rgt[mi] = hi;

  rek(lo, mi - 1);
  rek(mi + 1, hi);
}

int n, q;
int p[MAXN];

int L[MAXN], R[MAXN];
vector<int> odg_l[MAXN], odg_r[MAXN];

ll sum[2 * off];
int pr[2 * off];

void prop(int x, int lo, int hi) {
  if(pr[x]) {
    sum[x] += (ll) (hi - lo) * pr[x];
    if(x < off) {
      pr[x * 2] += pr[x];
      pr[x * 2 + 1] += pr[x];
    }
    pr[x] = 0;
  }
}

ll get_sum(int x, int lo, int hi, int a, int b) {
  prop(x, lo, hi);
  if(lo >= a && hi <= b) {
    return sum[x];
  }
  if(lo >= b || hi <= a) {
    return 0;
  }
  int mid = (lo + hi) >> 1;
  return get_sum(x * 2, lo, mid, a, b) + get_sum(x * 2 + 1, mid, hi, a, b);
}
void upd_sum(int x, int lo, int hi, int a, int b) {
  if(lo >= a && hi <= b) {
    pr[x] ++;
    prop(x, lo, hi);
    return;
  }
  prop(x, lo, hi);
  if(lo >= b || hi <= a) {
    return;
  }
  int mid = (lo + hi) >> 1;
  upd_sum(x * 2, lo, mid, a, b);
  upd_sum(x * 2 + 1, mid, hi, a, b);
  sum[x] = sum[x * 2] + sum[x * 2 + 1];
}

void solve() {
  REP(i, q) cin >> L[i];
  REP(i, q) cin >> R[i];

  REP(i, q) {
    R[i] --; L[i] --;
    odg_l[R[i]].pb(i);
    odg_r[L[i]].pb(i);
  }

  REP(i, n) {
    upd_sum(1, 0, off, lft[i], i + 1);
    for(auto j: odg_l[i]) {
      sol[j] += get_sum(1, 0, off, L[j], i + 1);
    }
  }

  memset(sum, 0, sizeof sum);
  memset(pr, 0, sizeof pr);

  for(int i = n - 1; i >= 0; --i) {
    upd_sum(1, 0, off, i, rgt[i] + 1);
    for(auto j: odg_r[i]) {
      sol[j] += get_sum(1, 0, off, i, R[j] + 1);
    }
  }

  REP(i, q) {
    cout << sol[i] - (R[i] - L[i] + 1) << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> q;
  REP(i, n) {
    cin >> p[i];
    upd(i, p[i]);
  }

  rek(0, n - 1);
  solve();
}