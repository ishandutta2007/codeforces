#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

struct Position {
  llint t, x, q, p;
  friend bool operator < (const Position &a, const Position &b) {
    return a.q < b.q;
  }
};

int parity(llint x) {
  return abs(x) % 2;
}

llint ceil(llint a, llint b);
llint floor(llint a, llint b);

llint floor(llint a, llint b) {
  assert(b > 0);
  if (a < 0) return -ceil(-a, b);
  return a/b;
}

llint ceil(llint a, llint b) {
  assert(b > 0);
  if (a < 0) return -floor(-a, b);
  return (a+b-1) / b;
}

void no_solution() {
  puts("NO");
  exit(0);
}

void solve(vector<Position> &v, int m, vector<int> &ans) {
  sort(v.begin(), v.end());
  v.insert(v.begin(), {0, 0, 0, 0});
  v.push_back({-m, 0LL, m, -1});

  llint lo = -m, hi = +m;
  for (int i = 1; i < (int)v.size(); ++i) {
    llint d = v[i].q - v[i - 1].q;
    llint k = v[i].p - v[i - 1].p;
    llint x = v[i].x - v[i - 1].x;

    if (parity(x - k*(m%2)) != parity(d)) no_solution();

    if (k == 0) {
      if (abs(x) > d) no_solution();
      continue;
    }
    
    if (k > 0) {
      lo = max(lo, ceil(x-d, k));
      hi = min(hi, floor(x+d, k));
    } else {
      lo = max(lo, ceil(-d-x, -k));
      hi = min(hi, floor(d-x, -k));
    }
  }

  if (parity(lo) != parity(m)) lo++;
  if (parity(hi) != parity(m)) hi--;

  if (lo > hi) no_solution();

  llint bal = lo;

  for (int i = 1; i < (int)v.size(); ++i) {
    llint d = v[i].q - v[i - 1].q;
    llint k = v[i].p - v[i - 1].p;
    llint x = v[i].x - v[i - 1].x;
    
    llint sum = x - k * bal;
    assert(parity(sum) == parity(d));
    assert(abs(sum) <= d);

    while (sum) {
      if (sum > 0) ans.push_back(+1), sum--; else
	ans.push_back(-1), sum++;
      d--;
    }

    assert(d%2 == 0);
    while (d > 0) {
      ans.push_back(+1);
      ans.push_back(-1);
      d -= 2;
    }
  }

  assert((int)ans.size() == m);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  static vector<Position> px, py;
  REP(i, n) {
    llint t, x, y;
    scanf("%lld %lld %lld", &t, &x, &y);
    px.push_back({t, x + y, t % m, t / m});
    py.push_back({t, x - y, t % m, t / m});
  }
  
  static vector<int> ansx, ansy;
  solve(px, m, ansx);
  solve(py, m, ansy);

  REP(i, m) {
    int dx = (ansx[i] + ansy[i]) / 2;
    int dy = (ansx[i] - ansy[i]) / 2;
    
    if (dx == +1 && dy == 0) putchar('R'); else
      if (dx == -1 && dy == 0) putchar('L'); else
	if (dx == 0 && dy == -1) putchar('D'); else
	  if (dx == 0 && dy == +1) putchar('U'); else
	    assert(false);
  }
  putchar('\n');
  return 0;
}