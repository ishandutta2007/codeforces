#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5, offset = 1 << 18;

int on[2 * offset], off[2 * offset], p[4 * offset];

void prop(int x) {
  if(p[x]) {
    swap(on[x], off[x]);
    p[x] ^= 1;
    p[x * 2] ^= 1;
    p[x * 2 + 1] ^= 1;
  }
}

int get(int x, int lo, int hi, int a, int b) {
  prop(x);
  if(lo >= b || hi <= a)
    return 0;
  if(lo >= a && hi <= b)
    return on[x];

  int mid = (lo + hi ) >> 1;
  return get(x * 2, lo, mid, a, b) + get(x * 2 + 1, mid, hi, a, b);
}
void update(int x, int lo, int hi, int a, int b) {
  if(lo >= a && hi <= b) {
    p[x] ^= 1;
    prop(x);
    return;
  }

  prop(x);
  if(lo >= b || hi <= a)
    return;

  int mid = (lo + hi) >> 1;
  update(x * 2 + 0, lo, mid, a, b);
  update(x * 2 + 1, mid, hi, a, b);

  on[x] = on[x * 2] + on[x * 2 + 1];
  off[x] = off[x * 2] + off[x * 2 + 1];
}

vector<int> e[MAXN];

int lo[MAXN], hi[MAXN], cookie = 0;
void dfs(int v) {
  lo[v] = cookie ++;
  for(auto w: e[v])
    dfs(w);
  hi[v] = cookie;
}

int main() {
  int n; cin >> n;
  REP(i, n - 1) {
    int x; cin >> x;
    e[x - 1].push_back(i + 1);
  }

  dfs(0);

  REP(i, n) {
    int x; cin >> x;
    if(x) {
      on[offset + lo[i]] ++;
    }
    else {
      off[offset + lo[i]] ++;
    }
  }

  for(int x = offset - 1; x; --x) {
    on[x] = on[x * 2] + on[x * 2 + 1];
    off[x] = off[x * 2] + off[x * 2 + 1];
  }

  int q; cin >> q;
  REP(i, q) {
    string s; cin >> s;
    if(s == "pow") {
      int x; cin >> x;
      update(1, 0, offset, lo[x - 1], hi[x - 1]);
    }
    else {
      int x; cin >> x;
      cout << get(1, 0, offset, lo[x - 1], hi[x - 1]) << endl;
    }
  }
}