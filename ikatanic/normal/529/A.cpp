#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 2000200;
const int off = 1<<21;
const int mod = 1e9 + 9;
const int H = 9973;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int h[MAXN], pw[MAXN];

struct data {
  int op, cl;
} T[2*off];

data operator + (const data &a, const data &b) {
  int m = min(a.op, b.cl);
  return {a.op + b.op - m, a.cl + b.cl - m};
}
data dummy = {0, 0};

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return dummy;
  if (lo >= a && hi <= b) return T[i];
  return query(i*2, lo, (lo+hi)/2, a, b) + query(i*2+1, (lo+hi)/2, hi, a, b);
}

char s[MAXN];

inline int get_hash(int i, int len) {
  return sub(h[i + len], mul(h[i], pw[len]));
}

bool cmp(int i, int j, int len) {
  int lo = 0, hi = len;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (get_hash(i, mid) == get_hash(j, mid)) lo = mid; else
      hi = mid - 1;
  }

  return s[i + lo] == '(';
}

int main(void) {
  scanf("%s", s);
  int n = strlen(s);
  REP(i, n) s[n+i] = s[i];
  
  pw[0] = 1;
  h[0] = 0;
  REP(i, 2*n) {
    h[i+1] = add(mul(h[i], H), s[i]);
    pw[i+1] = mul(pw[i], H);
  }

  FOR(i, off, 2*off)
    if (i-off < 2*n) {
      if (s[i-off] == '(') T[i] = {1, 0}; else
        T[i] = {0, 1};
    } else 
      T[i] = dummy;
  
  for (int i = off-1; i > 0; --i)
    T[i] = T[i*2] + T[i*2+1];
  
  int best = 4*n;
  int bestop = -1;
  int bestcl = -1;
  int ind = -1;
  
  REP(i, n) {
    data a = query(1, 0, off, i, i + n);
    int len = n + a.op + a.cl;
    if (len < best || (len == best && cmp(i, ind, n))) {
      best = len;
      bestop = a.op;
      bestcl = a.cl;
      ind = i;
    }
  }
  
  REP(i, bestcl) putchar('(');
  REP(i, n) putchar(s[ind + i]);
  REP(i, bestop) putchar(')');
  putchar('\n');
  return 0;
}