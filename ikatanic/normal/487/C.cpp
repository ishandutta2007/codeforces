#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100100;

int a[MAXN];
bool bio[MAXN];
int n;

int mul(int a, int b) {
  return (llint(a)*b)%n;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int main(void) {
  scanf("%d", &n);

  if (n == 4) {
    printf("YES\n1\n3\n2\n4\n");
    return 0;
  }

  for (int i = 2; i*i <= n; ++i)
    if (n%i == 0) {
      puts("NO");
      return 0;
    }

  puts("YES");
  printf("%d\n", 1);
  REP(i, n-1) {
    int cur = mul(powmod(i+1, n-2), i+2);
    if (cur == 0) cur = n;
    printf("%d\n", cur);
  }
  return 0;
}