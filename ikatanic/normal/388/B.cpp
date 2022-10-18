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

int a[1010][1010];

void edge(int x, int y) {
  a[x][y] = a[y][x] = 1;
}

int main(void) {
  int k;
  scanf("%d", &k);

  int cnt = 2;
  int l1 = 0, l2 = 0, l3 = cnt++;
  REP(j, 30) {
    if (k&(1<<j)) edge(l1, l3), edge(l2, l3);
    int n1 = cnt++, n2 = cnt++, n3 = cnt++;
    edge(l1, n1), edge(l2, n1);
    edge(l1, n2), edge(l2, n2);
    edge(l3, n3);
    l1 = n1, l2 = n2, l3 = n3;
  }

  edge(l3, 1);

  printf("%d\n", cnt);
  REP(i, cnt) REP(j, cnt+1)
    printf("%c", j == cnt ? '\n' : (a[i][j] ? 'Y' : 'N'));
  return 0;
}