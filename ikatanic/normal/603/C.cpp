#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;

int a[MAX];

int gr(int x, int k) {
  if (k % 2 == 0) {
    if (x <= 2) return x;
    return (x+1)%2;
  }

  if (x == 0 || x == 2) return 0;
  if (x == 1 || x == 3) return 1;
  if (x == 4 || x == 6) return 2;
  if (x % 2) return 0;
  return gr(x/2, k) == 1 ? 2 : 1;
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    ans ^= gr(x, k);
  }
    
  puts(!ans ? "Nicky" : "Kevin");
  return 0;
}