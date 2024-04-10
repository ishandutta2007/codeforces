#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int mod = 1e9 + 7;

map<int, int> M;

int pow(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return (llint(a)*pow(a, b-1))%mod;
  llint tmp = pow(a, b/2);
  return (tmp*tmp)%mod;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    for (int j = 2; j*j <= x; ++j)
      while (x%j == 0) M[j]++, x /= j;
    if (x > 1) M[x]++;
  }

  int ans = 1;
  for (auto p: M) {
    int k = p.second;
    int a = 1, b = 1;
    for (int i = 1; i <= k; ++i) {
      a = (llint(a)*(n+k-i))%mod;
      b = (llint(b)*i)%mod;
    }
    ans = (llint(ans)*a)%mod;
    ans = (llint(ans)*pow(b, mod-2))%mod;
  }

  printf("%d\n", ans);

  return 0;
}