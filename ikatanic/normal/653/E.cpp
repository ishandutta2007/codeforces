#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 300300;

vector<int> E[MAX];
vector<int> v[MAX];
vector<int> unvisited;

void dfs(int x, int c) {
  vector<int> w;
  vector<int> nunvisited;
  v[c].push_back(x);
  for (int y: unvisited) {
    if (binary_search(E[x].begin(), E[x].end(), y)) {
      nunvisited.push_back(y);
      continue;
    }
    w.push_back(y);
  }
  unvisited = nunvisited;
  for (int y: w) dfs(y, c);
}

void impossible() {
  puts("impossible");
  exit(0);
}

int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  REP(i, n) sort(E[i].begin(), E[i].end());
  FOR(i, 1, n) unvisited.push_back(i);

  int c = 0;
  while (unvisited.size()) {
    int x = unvisited.back();
    unvisited.pop_back();
    dfs(x, c++);
  }

  if (c > k) impossible();

  int total = 0;
  REP(i, c) {
    bool ok = false;
    for (int x: v[i]) {
      if (!binary_search(E[0].begin(), E[0].end(), x)) {
        ok = true;
        total++;
      }
    }
    if (!ok) impossible();
  }

  if (total < k) impossible();
  puts("possible");
  return 0;
}