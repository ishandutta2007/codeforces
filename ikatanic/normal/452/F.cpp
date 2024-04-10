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

const int offset = 1<<19;
const int mod = 1e9 + 7;
const int H = 9973;

int pw[offset];

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

struct data {
  int h, hr, len;
} T[2*offset];

data empty = {0, 0, 0};

data merge(data a, data b) {
  data c;
  c.h = add(mul(a.h, pw[b.len]), b.h);
  c.hr = add(mul(b.hr, pw[a.len]), a.hr);
  c.len = a.len + b.len;
  return c;
}

void update(int x) {
  x += offset;
  T[x].h = T[x].hr = 1;
  for (x /= 2; x; x /= 2)
    T[x] = merge(T[x*2], T[x*2+1]);
}

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return empty;
  if (lo >= a && hi <= b) return T[i];
  data left = query(i*2, lo, (lo + hi) / 2, a, b);
  data right = query(i*2+1, (lo + hi) / 2, hi, a, b);
  return merge(left, right);
}

int main(void) {
  pw[0] = 1;
  FOR(i, 1, offset)
    pw[i] = mul(pw[i-1], H);
  
  FOR(i, offset, 2*offset)
    T[i].len = 1;
  for (int i = offset-1; i > 0; --i)
    T[i] = merge(T[i*2], T[i*2+1]);

  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x); --x;
    
    int len = min(x, n-x-1);
    data left = query(1, 0, offset, x-len, x);
    data right = query(1, 0, offset, x+1, x+len+1);
    if (left.h != right.hr) {
      puts("YES");
      return 0;
    }
    update(x);
  }
  
  puts("NO");
  return 0;
}