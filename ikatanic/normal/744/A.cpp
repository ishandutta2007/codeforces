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
bool spec[MAX];
bool bio[MAX];

pair<int, bool> dfs(int x) {
  bio[x] = true;
  int sum = 1;
  bool f = spec[x];
  for (int y: E[x])
    if (!bio[y]) {
      auto p = dfs(y);
      sum += p.first;
      f |= p.second;
    }
  return {sum, f};
}

int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  REP(i, k) {
    int x;
    scanf("%d", &x); --x;
    spec[x] = true;
  }

  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  int total = 0;
  int no_sum = 0;
  int yes_best = 0;
  REP(i, n)
    if (!bio[i]) {
      pair<int, bool> c = dfs(i);

      if (c.second == false) {
        no_sum += c.first;
      } else {
        if (c.first > yes_best) {
          total += yes_best * yes_best;
          yes_best = c.first;
        } else {
          total += c.first * c.first;
        }
      }
    }

  total += (no_sum + yes_best) * (yes_best + no_sum);
  total -= n;
  total /= 2;
  total -= m;
  printf("%d\n", total);
  return 0;
}