#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 300300;

int ans[MAXN];
set<int> S;

int main(void)
{
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) S.insert(i);
  REP(i, m) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    --l, --r, --x;
    
    auto lo = S.lower_bound(l);
    static vector<int> v;
    
    v.clear();
    for (auto it = lo; it != S.end() && *it <= r; ++it)
      if (*it != x) v.push_back(*it);
    
    for (auto p : v)
      ans[p] = x, S.erase(p);
    ans[x] = -1;
  }
  
  REP(i, n)
    printf("%d%c", ans[i]+1, i == n-1 ? '\n' : ' ');
  return 0;
}