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

bool bio[MAX];

vector<int> tour;
void dfs(int x) {
  bio[x] = true;
  tour.push_back(x);
  for (int y: E[x])
    if (!bio[y]) {
      dfs(y);
      tour.push_back(x);
    }
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

  dfs(0);

  assert((int)tour.size() <= 2*n);

  int one = (2*n + k-1) / k;
  REP(i, k) {
    int lo = one*i;
    int hi = one*(i+1);

    vector<int> v;
    for (int j = lo; j < hi && j < (int)tour.size(); ++j) {
      v.push_back(tour[j]);
    }
    if (v.size() == 0) v.push_back(0);
    printf("%d", (int)v.size());
    for (int x: v) printf(" %d", x+1);
    printf("\n");
  }
  return 0;
}