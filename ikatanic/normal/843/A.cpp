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

const int MAX = 100100;

vector<int> E[MAX];
bool bio[MAX];
vector<int> v;

void dfs(int x) {
  if (bio[x]) return;
  v.push_back(x);
  bio[x] = true;
  for (int y: E[x]) dfs(y);
}

int main(void) {
  int n;
  scanf("%d", &n);

  vector<pair<int, int>> a;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    a.push_back({x, i});
  }
  
  sort(a.begin(), a.end());
  REP(i, n) {
    E[i].push_back(a[i].second);
    E[a[i].second].push_back(i);
  }

  vector<vector<int>> ret;
  REP(i, n) {
    if (!bio[i]) {
      v.clear();
      dfs(i);
      ret.push_back(v);
    }
  }

  printf("%d\n", (int)ret.size());
  for (auto& v: ret) {
    printf("%d", (int)v.size());
    for (int x: v) printf(" %d", x+1);
    printf("\n");
  }
  
  return 0;
}