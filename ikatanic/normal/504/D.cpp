#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int B = 2000;

bool bio[B];
bitset<B> who[B];
bitset<B> x, xwho, a[B];
char s[666];

bool solve() {
  REP(i, B)
    if (x.test(i) && bio[i])
      x ^= a[i], xwho ^= who[i];

  if (!x.any()) return true;
  
  
  for (int i = B-1; i >= 0; --i)
    if (!bio[i] && x.test(i)) {
      REP(j, B)
        if (bio[j] && a[j].test(i)) {
          a[j] ^= x;
          who[j] ^= xwho;
        }

      bio[i] = true;
      a[i] = x;
      who[i] = xwho;
      break;
    }
  return false;
}

int main(void) {
  int m;
  scanf("%d", &m);
  REP(i, m) {
    scanf("%s", s);
    int len = strlen(s);
    REP(i, len) s[i] -= '0';
    x.reset();
    
    int cur = 0;
    while (len > 0) {
      int nlen = 0, rem = 0;
      REP(j, len) {
        int d = rem*10 + s[j];
        if (nlen > 0 || d/2 > 0) s[nlen++] = d / 2;
        rem = d%2;
      }
      len = nlen;
      if (rem) x.set(cur);
      cur++;
    }
    
    xwho.reset();
    xwho.set(i);

    bool can = solve();
    vector<int> ans;
    if (can) {
      REP(j, i)
        if (xwho.test(j)) ans.push_back(j);
    }

    printf("%d ", (int)ans.size());
    if (ans.size()) for (int x: ans) printf("%d ", x);
    printf("\n");
  }
    
  return 0;
}