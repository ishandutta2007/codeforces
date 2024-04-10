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

const int MAX = 50500;
// varijable u prvom retku
// transzicijska po stupcima i mnozi s desna

int mod;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}
int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

struct matrix {
  static const int M = 2;
  int a[M][M];
  matrix() { REP(i, M) REP(j, M) a[i][j] = 0; }
  
  int* operator[] (int i) { return a[i]; }
  friend matrix operator* (matrix a, matrix b) {
    matrix r;
    REP(i, M) REP(j, M) REP(k, M) 
      r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
    return r;
  }
};

matrix power(matrix a, llint b) {
  assert(b > 0); b--;
  matrix r = a;
  while (b > 0) {
    if (b&1) r = r*a;
    a = a*a, b /= 2;
  }
  return r;
}

struct Info {
  llint i;
  int v;
  friend bool operator< (const Info& a, const Info& b) {
    return a.i < b.i;
  }
} diff[MAX];

int s[MAX];
int N, M;

const int off = 1<<16;
matrix T[2*off];
matrix id;

matrix calc(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return id;
  if (lo >= a && hi <= b) return T[i];
  return calc(i*2, lo, (lo+hi)/2, a, b) * calc(i*2+1, (lo+hi)/2, hi, a, b);
}

int getS(llint i) {
  auto j = lower_bound(diff, diff + M, (Info){i, -1}) - diff;
  if (0 <= j && j < M && diff[j].i == i) return diff[j].v;
  return s[i % N];
}

matrix getM(llint i) {
  matrix r;
  r[0][0] = getS(i + 1);
  r[0][1] = 1;
  r[1][0] = getS(i);
  r[1][1] = 0;
  return r;
}

matrix calcProd(llint l, llint r) {
  llint bl = l/N, br = r/N;
  if (bl == br) return calc(1, 0, off, l%N, r%N + 1);
  matrix a = calc(1, 0, off, l%N, N);
  if (br-bl-1 > 0) a = a * power(calc(1, 0, off, 0, N), br - bl - 1);
  a = a * calc(1, 0, off, 0, r%N + 1);
  return a;
}

int main(void) {
  id[0][0] = id[1][1] = 1;
  id[1][0] = id[0][1] = 0;

  llint K;
  scanf("%lld %d", &K, &mod);
  scanf("%d", &N);
  REP(i, N) scanf("%d", &s[i]);
  scanf("%d", &M);
  REP(i, M) scanf("%lld %d", &diff[i].i, &diff[i].v);

  REP(i, N) s[i] %= mod;
  REP(i, M) diff[i].v %= mod;

  sort(diff, diff + M);

  if (K <= 1) {
    printf("%lld\n", K % mod);
    return 0;
  }
  if (mod == 1) {
    printf("0\n");
    return 0;
  }

  K -= 2;
  // calc M(0) * M(1) * ... * M(K)

  REP(i, off) T[off + i] = id;
  REP(i, N) {
    T[off + i][0][0] = s[(i+1)%N];
    T[off + i][0][1] = 1;
    T[off + i][1][0] = s[i];
    T[off + i][1][1] = 0;
  }

  for (int i = off-1; i > 0; --i)
    T[i] = T[i*2] * T[i*2+1];

  vector<llint> invalid;
  REP(i, M) {
    invalid.push_back(diff[i].i);
    invalid.push_back(diff[i].i - 1);
  }
  sort(invalid.begin(), invalid.end());
  invalid.erase(unique(invalid.begin(), invalid.end()), invalid.end());
  while (!invalid.empty() && invalid.back() > K) invalid.pop_back();

  matrix a;
  a[0][0] = 1;
  a[0][1] = a[1][0] = a[1][1] = 0;

  llint last = -1;
  for (llint i: invalid) {
    if (last + 1 <= i - 1) a = a * calcProd(last + 1, i - 1);
    a = a * getM(i);
    last = i;
  }
  if (last + 1 <= K) a = a * calcProd(last + 1, K);
  printf("%d\n", a[0][0]);
  return 0;
}