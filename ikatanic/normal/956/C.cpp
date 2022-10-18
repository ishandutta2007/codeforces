#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int N;
  scanf("%d", &N);

  vector<int> m(N);
  REP(i, N) scanf("%d", &m[i]);

  stack<int> S;
  vector<bool> marked(N, false);
  int count = 0;
  REP(i, N) {
    S.push(i);

    while (m[i] >= count) {
      assert(!S.empty());
      marked[S.top()] = true;
      S.pop();
      count++;
    }

  }

  llint ret = 0;
  count = 0;
  REP(i, N) {
    count += marked[i];
    ret += count - m[i] - 1;
  }

  printf("%lld\n", ret);
  return 0;
}