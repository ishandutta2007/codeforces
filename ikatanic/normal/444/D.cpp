#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> par;

const int MAXN = 200100;
const int MAX = 30*30*30*30;

char s[MAXN];

vector<int> v[MAX];
map<par, int> ans;

int decode(char *s, int k) {
  if (k == 0) return 0;
  return decode(s, k-1)*27 + (*(s+k-1) - 'a' + 1);
}

int solve(int a, int b, int la, int lb) {
  if (ans.count({a, b})) return ans[{a, b}];
  if (ans.count({b, a})) return ans[{b, a}];
  if (v[a].size() == 0 || v[b].size() == 0) return -1;
  
  if (v[a].size() > v[b].size()) swap(a, b), swap(la, lb);
  
  int best = 1e9;
  for (int x: v[a]) {
    int i = lower_bound(v[b].begin(), v[b].end(), x) - v[b].begin();
    
    auto eval = [&] (int y) {
      return max(x + la, y + lb) - min(x, y);
    };
    
    if (i < (int)v[b].size()) best = min(best, eval(v[b][i]));
    if (i-1 >= 0) best = min(best, eval(v[b][i-1]));
  }
  
  ans[{a, b}] = best;
  return best;
}

int main(void) {
  scanf("%s", s);
  int n = strlen(s);
  REP(i, n)
    for (int j = 1; j <= 4 && i+j <= n; ++j) {
      int h = decode(s+i, j);
      v[h].push_back(i);
    }
  
  int q;
  scanf("%d", &q);
  REP(i, q) {
    char a[10], b[10];
    scanf("%s %s", a, b);
    int qa = decode(a, strlen(a));
    int qb = decode(b, strlen(b));
    printf("%d\n", solve(qa, qb, strlen(a), strlen(b)));
  }
  
  return 0;
}