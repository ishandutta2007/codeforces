#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

vector<int> E[MAXN];

double solve(int x, int d, int dad) {
  double ans = 1.0/d;
  for (int y: E[x])
    if (y != dad) ans += solve(y, d+1, x);
  return ans;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  double ans = solve(0, 1, -1);
  printf("%lf\n", ans);
  return 0;
}