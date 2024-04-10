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

vector<int> E[MAX];
int color[MAX];

void dfs(int x, int dad, int dad_color) {
  int cur = 0;
  for (int y: E[x])
    if (y != dad) {
      while (cur == color[x] || cur == dad_color) cur++;
      color[y] = cur++;
      dfs(y, x, color[x]);
    }
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  color[0] = 0;
  dfs(0, -1, -1);

  int k = *max_element(color, color + n) + 1;
  printf("%d\n", k);
  REP(i, n) printf("%d ", color[i]+1);
  printf("\n");
  
  return 0;
}