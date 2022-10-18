#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 10010;
const int off = 1 << 14;

vector<int> T[2*off];

bitset<MAX> ans;
bitset<MAX> cur;
bitset<MAX> stack[20];

void add(int i, int lo, int hi, int a, int b, int x) {
  if (lo >= b || hi <= a) return;
  if (lo >= a && hi <= b) {
    T[i].push_back(x);
    return;
  }

  add(i*2, lo, (lo+hi)/2, a, b, x);
  add(i*2+1, (lo+hi)/2, hi, a, b, x);
}

void go(int i, int d, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return;
  stack[d] = cur;
  for (int x: T[i]) {
    cur |= (cur << x);
  }

  if (hi-lo == 1) {
    ans |= cur;
    return;
  } else {
    go(i*2, d+1, lo, (lo+hi)/2, a, b);
    go(i*2+1, d+1, (lo+hi)/2, hi, a, b);
  }

  cur = stack[d];
}

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, q) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x); --l;
    add(1, 0, off, l, r, x);
  }

  cur.set(0);
  go(1, 0, 0, off, 0, n);

  vector<int> ret;
  FOR(i, 1, n+1) if (ans.test(i)) ret.push_back(i);

  printf("%d\n", (int)ret.size());
  for (int x: ret) printf("%d ", x);
  printf("\n");
  return 0;
}