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

const int MAX = 5050;

int a[MAX];
int c[MAX];
int ans[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &a[i]);
    --a[i];
  }
  
  REP(i, n) {
    REP(j, n) c[j] = 0;
    int best = 0;
    FOR(j, i, n) {
      c[a[j]]++;
      if (c[a[j]] > c[best] || (c[a[j]] == c[best] && a[j] < best)) best = a[j];
      ans[best]++;
    }
  }

  REP(i, n) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}