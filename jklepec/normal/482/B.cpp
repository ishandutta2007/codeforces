#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5, inf = (1 << 30) - 1, off = 1 << 17;

int T[2 * off];

void upd(int x, int lo, int hi, int a, int b, int v) {
  if(lo >= a && hi <= b) {
    T[x] |= v;
    return;
  }
  if(lo >= b || hi <= a) {
    return;
  }
  int mid = (lo + hi) >> 1;
  upd(x * 2, lo, mid, a, b, v);
  upd(x * 2 + 1, mid, hi, a, b, v);
}

int f(int x) {
  int ret = 0;
  for(x += off; x; x /= 2)
    ret |= T[x];
  return ret;
}

int T2[2 * off];
int check(int x, int lo, int hi, int a, int b) {
   if(lo >= a && hi <= b) {
    return T2[x];
  }
  if(lo >= b || hi <= a) {
    return inf;
  }
  int mid = (lo + hi) >> 1;
  return check(x * 2, lo, mid, a, b) & check(x * 2 + 1, mid, hi, a, b);
}

int l[MAXN], r[MAXN], v[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, m; cin >> n >> m;

  REP(i, m) {
    cin >> l[i] >> r[i] >> v[i];
    upd(1, 0, off, l[i] - 1, r[i], v[i]);
  }

  REP(i, n) {
    T2[i + off] = f(i);
  }

  for(int x = off - 1; x; x --) {
    T2[x] = T2[x * 2] & T2[x * 2 + 1];
  }

  REP(i, m) {
    if(check(1, 0, off, l[i] - 1, r[i]) != v[i]) {
      cout << "NO";
      return 0;
    }
  }


  cout << "YES\n";
  REP(i, n) {
    cout << T2[i + off] << " ";
  }
}