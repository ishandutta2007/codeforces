#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

llint sqr(int x) { return llint(x)*x; }

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);

  llint best = sqr(a) - sqr(b);
  int rk = 1;
  for (int k = 2; k <= a+1 && k <= b; ++k) {
    llint score = sqr((a-(k-2))) + k-2;
    int p = b/k, q = b%k;
    score -= (k-q)*sqr(p) + q*sqr(p+1);
    if (score > best) best = score, rk = k;
  }

  cout << best << endl;
  if (rk == 1) {
    cout << string(a, 'o') << string(b, 'x') << endl;
  } else {
    int big = a-(rk-2);
    int p = b/rk, q = b%rk;
    
    cout << string(p, 'x');
    REP(i, rk-1) {
      if (i == 0) cout << string(big, 'o'); else
        cout << 'o';
      cout << string(p, 'x');
      if (i+1 >= rk-q) cout << 'x';
    }
    cout << endl;
  }
  
  return 0;
}