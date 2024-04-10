#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int off = 1 << 18, inf = 1e9;

struct tour {
  vector<int> t;
  void init() {
    t.resize(2 * off);
  }

  int get(int x, int lo, int hi, int a, int b) {
    if(lo >= a && hi <= b) return t[x];
    if(lo >= b || hi <= a) return -inf;
    int mi = (lo + hi) >> 1;
    return max(get(x * 2, lo, mi, a, b), get(x * 2 + 1, mi, hi, a, b));
  }

  void upd(int x, int v) {
    x += off;
    t[x] = v;
    for(x /= 2; x; x /= 2) {
      t[x] = max(t[x * 2], t[x * 2 + 1]);
    }
  }

} tur[32];

int inv;

void upd(int i, vector<int> v) {
  REP(mask, inv + 1) {
    int val = 0;
    REP(j, v.size()) {
      if((1 << j) & mask) {
        val += v[j];
      }
      else {
        val -= v[j];
      }
    }
    tur[mask].upd(i, val);
  }
}

int query(int lo, int hi) {
  int ret = -inf;
  REP(i, inv + 1) {
    int j = i ^ inv;
    int tmp = tur[i].get(1, 0, off, lo, hi) + tur[j].get(1, 0, off, lo, hi);
    ret = max(ret, tmp);
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, k; cin >> n >> k;

  inv = (1 << k) - 1;

  REP(i, inv + 1) {
    tur[i].init();
  }

  REP(i, n) {
    vector<int> v;
    REP(j, k) {
      int x; cin >> x;
      v.pb(x);
    }

    upd(i, v);
  }

  int q; cin >> q;
  REP(i, q) {
    int type; cin >> type;
    if(type == 1) {
      int in; cin >> in;
      vector<int> v;
      REP(j, k) {
        int x; cin >> x;
        v.pb(x);
      }
      upd(in - 1, v);
    }
    else {
      int l, r; cin >> l >> r;
      cout << query(l - 1, r) << '\n';
    }
  }
}