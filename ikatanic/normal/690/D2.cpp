#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 1000005;
const int mod = 1e6 + 3;

int mul(int a, int b) { return (llint)a * b % mod; }
int add(int a, int b) { return (a + b) % mod; }

int power(int a, int b) {
  int ret = 1;
  for (int i = 0; (1 << i) <= b; ++i) {
    if (((b >> i) & 1) == 1)
      ret = mul(ret, a);
    a = mul(a, a);
  }
  return ret;
}

int inv(int x) { return power(x, mod - 2); }

int fact[MAX];
int ifact[MAX];

int choose(int n, int k) {
  return mul(fact[n], mul(ifact[n - k], ifact[k]));
}

int main(void) 
{
  fact[0] = ifact[0] = 1;
  FOR(i, 1, MAX) {
    fact[i] = mul(fact[i - 1], i);
    ifact[i] = inv(fact[i]);
  }

  int n, C;
  scanf("%d%d", &n, &C);

  int sol = 0;
  FOR(i, 1, n + 1) 
    sol = add(sol, choose(i + C - 1, C - 1));

  printf("%d\n", sol);

  return 0;
}