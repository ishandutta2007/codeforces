#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 505, MAXQ = 6e5 + 5;

bitset<MAXN> p1[MAXN][MAXN], p2[MAXN][MAXN];

bool c[MAXN][MAXN];
bool sol[MAXQ];

int n, m;
int a1[MAXQ], b1[MAXQ], a2[MAXQ], b2[MAXQ];

int readint() {
   int ret = 0, d;
    d = getchar();
    while (d < 48 || d > 57)
       	d = getchar();
    do {
        ret = ret * 10 + d - 48;
        d = getchar();
    } while (d > 47 && d < 58);
    return ret;
}

void solve(int lo, int hi, vector<int> &Q) {
  if(hi <= lo) return;

  int mid = (lo + hi) >> 1;

  for(int j = mid; j >= lo; --j) {
    for(int i = n - 1; i >= 0; --i) {

      p1[i][j].reset();

      if(c[i][j]) {
        if(j == mid) p1[i][j].set(i);

        p1[i][j] |= p1[i + 1][j];
        if(j < mid) p1[i][j] |= p1[i][j + 1];
      }
    }
  }

  for(int j = mid; j < hi; ++j) {
    for(int i = 0; i < n; ++i) {

      p2[i][j].reset();

      if(c[i][j]) {
        if(j == mid) p2[i][j].set(i);

        if(i) p2[i][j] |= p2[i - 1][j];
        if(j > mid) p2[i][j] |= p2[i][j - 1];
      }
    }
  }

  vector<int> l, r;

  for(auto i: Q) {
    if(b1[i] <= mid && b2[i] >= mid) {
      if((p1[a1[i]][b1[i]] & p2[a2[i]][b2[i]]).any()) {
        sol[i] = true;
      }
    }
    else if(b1[i] < mid) {
      l.pb(i);
    }
    else {
      r.pb(i);
    }
  }

  solve(lo, mid, l);
  solve(mid + 1, hi, r);
}

int main() {
  n = readint();
  m = readint();

  REP(i, n) REP(j, m) {
    char x; x = getchar();
    while(x != '.' && x != '#') x = getchar();
    if(x == '.') c[i][j] = true;
  }

  int q; q = readint();
  REP(i, q) {
    a1[i] = readint() - 1;
    b1[i] = readint() - 1;
    a2[i] = readint() - 1;
    b2[i] = readint() - 1;
  }

  vector<int> v;
  REP(i, q) v.pb(i);

  solve(0, m, v);

  REP(i, q) {
    if(sol[i]) {
      puts("Yes");
    }
    else {
      puts("No");
    }
  }
}