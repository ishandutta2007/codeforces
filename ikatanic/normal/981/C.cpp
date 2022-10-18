#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;

vector<int> E[MAX];

vector<int> v;

void dfs(int x, int dad = -1) {
  bool ok = false;
  for (int y: E[x]) {
    if (y == dad) continue;
    ok = true;
    dfs(y, x);
  }
  if (!ok) v.push_back(x);
}

int main(void) {
  int N;
  scanf("%d", &N);
  REP(i, N-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  vector<int> big;
  REP(i, N) {
    if (E[i].size() >= 3) {
      big.push_back(i);
    }
  }

  if (big.size() > 1) {
    puts("No");
    return 0;
  }

  int x = big.size() == 1 ? big[0] : 0;

  dfs(x);

  puts("Yes");
  printf("%d\n", (int)v.size());
  for (int y: v) printf("%d %d\n", x+1, y+1);
  return 0;
}