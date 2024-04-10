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

const int MAX = 200200;

int a[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", a+i);
    a[i] += i;
  }

  sort(a, a + n);
  REP(i, n-1)
    if (a[i] == a[i+1]) {
      puts(":(");
      return 0;
    }
  
  REP(i, n) printf("%d ", a[i] - i);
  
  return 0;
}