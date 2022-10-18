#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

int a[MAX];
int r[MAX];
llint pre[MAX];
bool can[MAX];


int main(void) {
  int c, n;
  scanf("%d %d", &c, &n);
  REP(i, n) scanf("%d", &a[i]);
  a[n++] = c + 1;
  sort(a, a + n);

  pre[0] = 0;
  REP(i, n) pre[i + 1] = pre[i] + a[i];
  
  int rem = c;
  for (int i = n-1; i >= 0; --i) {
    r[i] = rem;
    if (a[i] <= rem) rem -= a[i];
  }

  assert(rem == 0);
 
  can[0] = true;
  REP(i, n - 1) {
    auto test = [&] (int x) {
      int lo = 0, hi = i + 1;
      while (lo < hi) {
        int mid = lo + (hi - lo + 1)/2;
        if (pre[i+1] - pre[i+1-mid] <= x) lo = mid;
        else hi = mid - 1;
      }
      x -= pre[i+1] - pre[i+1-lo];
      return can[x];
    };
   
    FOR(x, a[i], a[i+1])
      if (x < r[i] && !test(r[i] - x)) {
        printf("%d\n", x);
        return 0;
      }

    for (int j = a[i+1]-1; j >= a[i]; --j)
      can[j] = test(j);
  }

  puts("Greed is good");
  return 0;
}