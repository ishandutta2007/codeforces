#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <stack>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int a[100100];
int n;

stack<int> S;

int solve() {
  int ans = 0;
  REP(i, n) {
    while (!S.empty() && a[i] > S.top()) ans = max(ans, a[i]^S.top()), S.pop();
    S.push(a[i]);
  }
  while (!S.empty()) S.pop();
  return ans;
}

int main(void)
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  
  int ans = solve();
  reverse(a, a + n);
  ans = max(ans, solve());
  printf("%d\n", ans);
  return 0;
}