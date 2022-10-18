#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  set<int> squares;
  REP(x, 1010) squares.insert(x * x);

  int n;
  scanf("%d", &n);

  vector<int> v;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    if (!squares.count(x)) v.push_back(x);
  }

  int ret = *max_element(v.begin(), v.end());
  printf("%d\n", ret);
  return 0;
}