#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

llint gcd(llint a, llint b) {
  return !b ? a : gcd(b, a % b);
}

int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  REP(i, n) { scanf("%d", &v[i]); --v[i]; }

  vector<int> w = v;
  sort(w.begin(), w.end());
  REP(i, n) {
    if (w[i] != i) {
      puts("-1");
      return 0;
    }
  }
  
  vector<bool> bio(n, false);
  llint ans = 1;
  REP(i, n) {
    if (!bio[i]) {
      int len = 0;
      int x = i;
      while (!bio[x]) {
        bio[x] = true;
        x = v[x];
        len++;
      }

      if (len % 2) {
        ans = ans * len / gcd(ans, len);
      } else {
        ans = ans * (len / 2) / gcd(ans, len/2);
      }
    }
  }

  printf("%lld\n", ans);
  return 0;
}