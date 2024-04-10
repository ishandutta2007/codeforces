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
typedef pair<int, int> par;
#define x first
#define y second

par a[300300];
int ans[300300];

int main(void)
{
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &a[i].x);
    a[i].y = i;
  }

  sort(a, a + n);

  int cnt = 1;
  REP(i, n) {
    cnt = max(cnt, a[i].x);
    ans[a[i].y] = cnt++;
  }

  REP(i, n) printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');

  return 0;
}