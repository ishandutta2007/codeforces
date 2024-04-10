#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int off = 1 << 15, mod = 1e9 + 7, P = 1e7 + 19, MAX = 15005, MAXQ = 35005;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}

point A[MAX];
vector<point> T[2 * off];

int n, k;

void update(int x, int lo, int hi, int a, int b, int i) {
  if(lo >= a && hi <= b) {
    T[x].push_back(A[i]);
    return;
  }
  if(lo >= b || hi <= a) {
    return;
  }
  int mid = (lo + hi) >> 1;

  update(x * 2 + 0, lo, mid, a, b, i);
  update(x * 2 + 1, mid, hi, a, b, i);
}

int cookie;
int lo[MAX], hi[MAX];

stack< vector<int> > knapsack;

int calc() {
  int ret = 0;

  int p = 1;
  FOR(i, 1, k + 1) {
    ret = add(ret, mul(knapsack.top()[i], p));
    p = mul(p, P);
  }

  return ret;
}

int sol[MAXQ];

void dfs(int x, int lo, int hi) {
  if(lo >= cookie) return;

  vector<int> new_knap, before;
  new_knap = knapsack.top();

  for(auto p: T[x]) {
    before = new_knap;
    REP(i, k + 1) {
      new_knap[i] = before[i];
      if(i - p.second >= 0) {
        new_knap[i] = max(new_knap[i], add(before[i - p.second], p.first));
      }
    }
  }

  knapsack.push(new_knap);

  if(lo == hi - 1) {
    sol[lo] = calc();
    knapsack.pop();
    return;
  }

  int mid = (lo + hi) >> 1;

  dfs(x * 2 + 0, lo, mid);
  dfs(x * 2 + 1, mid, hi);

  knapsack.pop();
}

int main() {

  fill(hi, hi + MAX, off);

  cin >> n >> k;

  REP(i, n) {
    cin >> A[i].first >> A[i].second;
  }

  int q; cin >> q;

  REP(i, q) {
    int type; cin >> type;

    if(type == 1) {
      cin >> A[n].first >> A[n].second;

      lo[n] = cookie;

      n ++;
    }

    if(type == 2) {
      int x; cin >> x;

      hi[x - 1] = cookie;
    }

    if(type == 3) {
      cookie ++;
    }
  }

  REP(i, n) {
    update(1, 0, off, lo[i], hi[i], i);
  }

  vector<int> v;
  v.resize(k + 1, 0);

  knapsack.push(v);

  dfs(1, 0, off);

  REP(i, cookie) {
    cout << sol[i] << endl;
  }
}