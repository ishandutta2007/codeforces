#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 200020;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return llint(a) * b % mod;
}

int p[MAX], pr[MAX];
int f[MAX], up[MAX];
vector<int> E[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", p+i); --p[i];
    E[p[i]].push_back(i);
  }

  for (int i = n-1; i >= 0; --i) {
    f[i] = 1;
    for (int y: E[i])
      f[i] = mul(f[i], add(1, f[y]));
  }

  up[0] = 1;
  REP(i, n) {
    printf("%d ", mul(f[i], up[i]));
    pr[0] = up[i];
    REP(j, (int)E[i].size())
      pr[j + 1] = mul(pr[j], add(1, f[ E[i][j] ]));

    int suf = 1;
    for (int j = (int)E[i].size()-1; j >= 0; --j) {
      up[E[i][j]] = add(1, mul(suf, pr[j]));
      suf = mul(suf, add(1, f[ E[i][j] ]));
    }
  }
  printf("\n");
  return 0;
}