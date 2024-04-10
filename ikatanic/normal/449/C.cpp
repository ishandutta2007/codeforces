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

const int MAXN = 100100;

int p[MAXN];
vector<int> v[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  
  FOR(i, 2, n+1)
    if (p[i] == 0) {
      for (int j = i; j <= n; j += i)
        if (!p[j]) p[j] = i;
    }

  static vector<pair<int, int>> ans;
  for (int i = n; i > 1; --i)
    if (p[i] == i) {
      static vector<int> v; v.clear();
      for (int j = i; j <= n; j += i)
        if (p[j] == i) v.push_back(j);
      
      if ((v.size()&1) && i > 2) {
        if (i*2 > n) {
          assert(v.size() == 1);
          continue;
        }
        v.push_back(i*2);
        p[i*2] = i;
      }
      
      if (i > 2) assert(v.size()%2 == 0);

      REP(j, (int)v.size()/2)
        ans.push_back({v[j*2], v[j*2+1]});
    }

  printf("%d\n", (int)ans.size());
  for (auto p: ans)
    printf("%d %d\n", p.first, p.second);
        
  return 0;
}