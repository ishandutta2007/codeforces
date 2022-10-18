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
typedef pair<int, int> par;

const int MAXN = 100100;

int a[MAXN], b[MAXN];
int c[MAXN], p[MAXN];
int ans[MAXN], r[MAXN];

int n, m, s;

bool can(int k) {
  static set<par> S;
  S.clear();

  int cost = 0, j = n;
  for (int i = m-1; i >= 0 && cost <= s; i -= k) {
    while (j > 0 && b[r[j-1]] >= a[p[i]]) {
      j--;
      S.insert(make_pair(c[r[j]], r[j]));
    }
    
    if (S.size() == 0) return false;
    
    par w = *S.begin();
    S.erase(S.begin());
    cost += w.first;

    for (int l = i; l > i-k && l >= 0; --l)
      ans[p[l]] = w.second;
  }
  
  return cost <= s;
}

int main(void)
{
  scanf("%d %d %d", &n, &m, &s);
  REP(i, m) scanf("%d", a+i);
  REP(i, n) scanf("%d", b+i);
  REP(i, n) scanf("%d", c+i);
  REP(i, m) p[i] = i;
  REP(i, n) r[i] = i;

  sort(p, p + m, [] (const int &x, const int &y) {
      return a[x] < a[y];
    }
  );
  sort(r, r + n, [] (const int &x, const int &y) {
      return b[x] < b[y];
    }
  );
 
  if (!can(m)) { puts("NO"); return 0; }

  int lo = 0, hi = m+1;
  while (lo < hi) {
    int mid = (lo + hi)/2;
    if (can(mid)) hi = mid; else
      lo = mid+1;
  }

  can(lo);

  puts("YES");
  REP(i, m) printf("%d%c", ans[i]+1, i == m-1 ? '\n' : ' ');
  
  return 0;
}