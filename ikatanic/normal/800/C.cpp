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

pair<llint, llint> extended_euclid(llint a, llint b) {
  if (b == 0) return {1, 0};
  int k = a / b;
  auto p = extended_euclid(b, a - k*b);
  return {p.second, p.first - k * p.second};
}

int division(int x, int y, int m) {
  int g = __gcd(m, y);
  assert(x % g == 0);
  llint ret = extended_euclid(m / g, y / g).second % m;
  ret = (ret * (x / g)) % m;
  if (ret < 0) ret += m;
  return ret;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  if (m == 1) {
    assert(n == 0);
    printf("1\n0\n");
    return 0;
  }

 
  vector<bool> bio(m, false);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    bio[x] = true;
  }


  vector<vector<int>> rems(m);
  FOR(i, 1, m)
    if (!bio[i]) rems[ __gcd(i, m) ].push_back(i);

  
  vector<int> f(m, 0);
  vector<int> r(m, -1);
  f[1] = 0;
  int best = 1;
  FOR(i, 1, m) {
    f[i] += rems[i].size();

    if (f[i] > f[best]) {
      best = i;
    }
    
    for (int j = 2; j*i < m; ++j) {
      if (f[i] > f[j*i]) {
        f[j*i] = f[i];
        r[j*i] = i;
      }
    }
  }

  vector<int> prefs;
  for (int x = best; x != -1; x = r[x]) {
    for (int y: rems[x]) prefs.push_back(y);
  }

  reverse(prefs.begin(), prefs.end());
  vector<int> ans;
  int prev = 1;
  for (int p : prefs) {
    ans.push_back(division(p, prev, m));
    prev = p;
  }

  if (!bio[0]) {
    ans.push_back(0);
  }

  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  printf("\n");

  return 0;
}