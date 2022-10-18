#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int off = 1<<20;

struct data {
  int cnt, openning, closing;
};

data T[2*off];

data merge(data &a, data &b) {
  int add = min(a.openning, b.closing);
  return {a.cnt+b.cnt+add, a.openning+b.openning-add, a.closing+b.closing-add};
}

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return {0, 0, 0};
  if (lo >= a && hi <= b) return T[i];
  data L = query(i*2, lo, (lo+hi)/2, a, b);
  data R = query(i*2+1, (lo+hi)/2, hi, a, b);
  return merge(L, R);
}

int main(void)
{
  static char s[1000100];
  scanf("%s", s);
  int n = strlen(s);
  REP(i, n)
    if (s[i] == '(') T[off+i] = {0, 1, 0}; else
      T[off+i] = {0, 0, 1};

  for (int i = off-1; i > 0; --i)
    T[i] = merge(T[i*2], T[i*2+1]);

  int m;
  scanf("%d", &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;

    data ans = query(1, 0, off, a, b+1);
    printf("%d\n", ans.cnt*2);
  }

  return 0;
}