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

const int LG = 16;
const int N = 1<<LG;
const int MAX = 555;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

void fastAnd(int *A, int *B, int *C, int n) {
  if (n == 0) { C[0] = mul(A[0], B[0]); return; }
  int mid = 1<<(n-1);
  fastAnd(A+mid, B+mid, C+mid, n-1);
  REP(i, mid) A[i] = add(A[i], A[mid+i]), B[i] = add(B[i], B[mid+i]);
  fastAnd(A, B, C, n-1);
  REP(i, mid) A[i] = sub(A[i], A[mid+i]), B[i] = sub(B[i], B[mid+i]), C[i] = sub(C[i], C[mid+i]);
}

int f[MAX][N];
char s[MAX];

inline bool eval(int vals, int i, bool val_i) {
  if (vals & (1<<i)) return val_i;
  return !val_i;
}

void solve(int l, int r) {
  if (l >= r) return;
  if (l + 1 == r) {
    REP(i, 4) REP(val_i, 2) {
      if (s[l] == '?' || 
          (!val_i && s[l] == 'a' + i) ||
          (val_i && s[l] == 'A' + i)) {
        int mask = 0;
        REP(ms, 1<<4)
          if (eval(ms, i, val_i)) {
            mask |= 1<<ms;
          }
        f[l][mask]++;
      }
    }
    return;
  }

  if (s[l] != '(' || s[r-1] != ')') return;

  int bal = 1, pos = l + 1;
  while (bal && pos < r) {
    if (s[pos] == '(') bal++;
    if (s[pos] == ')') bal--;
    if (bal < 0) return;
    pos++;
  }

  if (pos == r) return;

  assert(bal == 0);
  for (int i = pos; i < r; ++i) {
    if (s[i] == '(') bal++; else
      if (s[i] == ')') bal--;
    if (bal < 0) return;
  }
  if (bal) return;

  if (pos-l < 2 || s[pos-1] != ')') return;
  if (r-pos-1 < 2 || s[pos+1] != '(') return;

  int L = l + 1;
  int R = pos + 2;
  solve(L, pos - 1);
  solve(R, r - 1);

  for (char c: {'&', '|'}) {
    if (s[pos] != '?' && c != s[pos]) continue;

    static int ta[N], tb[N], tc[N];
    REP(i, N) {
      if (c == '&') ta[i] = f[L][i], tb[i] = f[R][i];
      if (c == '|') ta[i] = f[L][i^(N-1)], tb[i] = f[R][i^(N-1)];
      tc[i] = 0;
    }
    
    fastAnd(ta, tb, tc, LG);
    REP(i, N)
      f[l][i] = add(f[l][i], c == '&' ? tc[i] : tc[i^(N-1)] );
  }
}

int main(void) {
  scanf("%s", s);
  solve(0, strlen(s));

  int k;
  scanf("%d", &k);
  int have = 0, mask = 0;
  REP(i, k) {
    int x, vals = 0;
    REP(j, 4) {
      scanf("%d", &x);
      if (x) vals |= 1<<j;
    }
    scanf("%d", &x);
    have |= 1<<vals;
    if (x) mask |= 1<<vals;
  }

  int ans = 0;
  REP(s, N)
    if ((s & have) == mask) ans = add(ans, f[0][s]);
  printf("%d\n", ans);
  return 0;
}