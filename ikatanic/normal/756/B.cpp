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

int main(void) {
  int n;
  scanf("%d", &n);

  vector<int> costs(n+1, 0);
  vector<int> t(n);
  int ptr1 = 0, ptr2 = 0;
  REP(i, n) {
    scanf("%d", &t[i]);

    while (ptr1 < i && t[ptr1] + 90 <= t[i]) ptr1++;
    while (ptr2 < i && t[ptr2] + 1440 <= t[i]) ptr2++;

    costs[i+1] = min(
      costs[i] + 20,
      min(
        costs[ptr1] + 50,
        costs[ptr2] + 120
      )
    );
    printf("%d\n", costs[i+1]-costs[i]);
  }
  
  return 0;
}