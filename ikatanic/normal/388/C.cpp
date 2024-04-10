#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int main(void) {
  int n;
  scanf("%d", &n);
  
  vector<int> v;

  int ans1 = 0, ans2 = 0;
  REP(i, n) {
    int m;
    scanf("%d", &m);

    static int a[101];
    REP(i, m) scanf("%d", a+i);

    REP(i, m/2) 
      ans1 += a[i], ans2 += a[m-i-1];
    if (m%2 == 1) v.push_back(a[m/2]);
  }

  sort(v.begin(), v.end(), greater<int>());
  REP(i, (int)v.size())
    if (i%2 == 0) ans1 += v[i]; else
      ans2 += v[i];
  printf("%d %d\n", ans1, ans2);
  return 0;
}