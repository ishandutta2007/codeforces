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

const int MAX = 1000100;

bool bad[MAX];
int a[MAX];
int n;

bool check(int i) {
  if (i+1 == n) return true;
  if (i%2 == 0) return a[i] < a[i+1];
  return a[i] > a[i+1];
}

set<pair<int, int>> S;

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  
  REP(i, n-1)
    if (!check(i)) bad[i] = bad[i+1] = true;

  vector<int> v;
  REP(i, n) 
    if (bad[i]) v.push_back(i);

  if ((int)v.size() <= 10) {
    for (int i: v) {
      REP(j, n) {
        if (i == j) continue;

        swap(a[i], a[j]);
        bool ok = true;
        for (int k: v) {
          if (k > 0) ok &= check(k-1);
          ok &= check(k);
        }
        for (int k = max(0, j-2); k <= min(n-1, j+2); ++k) ok &= check(k);
        if (ok) S.insert(minmax(i, j));
        swap(a[i], a[j]);
      }
    }
  }

  printf("%d\n", (int)S.size());
  return 0;
}