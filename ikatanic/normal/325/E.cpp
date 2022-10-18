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

const int MAXN = 100100;

int dad[MAXN];
int ans[MAXN];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  dad[findset(x)] = findset(y);
}

int main(void) {
  int n;
  scanf("%d", &n);
  if (n&1) {
    puts("-1");
    return 0;
  }
  REP(i, n) dad[i] = i;
  REP(i, n/2) {
    ans[i] = (i*2)%n;
    merge(i, (i*2)%n);
    ans[n/2 + i] = (i*2+1)%n;
    merge(n/2 + i, (i*2+1)%n);
  }

  REP(i, n/2)
    if (findset(i) != findset(n/2 + i)) {
      merge(i, n/2 + i);
      swap(ans[i], ans[n/2+i]);
    }

  int cur = 0;
  REP(i, n) {
    printf("%d ", cur);
    cur = ans[cur];
  }
  printf("%d\n", cur);
  return 0;
}