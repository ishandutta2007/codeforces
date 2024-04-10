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

const int MAXN = 1000010;

llint gcd(llint a, llint b) { return !b ? a : gcd(b, a%b); }

char a[MAXN], b[MAXN];
int cnt[MAXN];

int main(void)
{
  llint n, m;
  scanf("%I64d %I64d", &n, &m);
  scanf("%s", a);
  scanf("%s", b);
  
  int la = strlen(a), lb = strlen(b);
  int g = gcd(la, lb);
  llint l = llint(la)*lb/g;
  
  llint same = 0;
  for (int ch = 'a'; ch <= 'z'; ++ch) {
    for (int i = 0; i < g; ++i) {
      cnt[i] = 0;
      for (int j = i; j < lb; j += g)
        cnt[i] += (b[j] == ch);
    }

    for (int i = 0; i < la; ++i)
      if (a[i] == ch) same += cnt[i%g];
  }

  llint ans = (l - same)*(n*la/l);
  printf("%I64d\n", ans);
  return 0;
}