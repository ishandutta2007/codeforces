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

const int MAXN = 1000100;
const int inf = 1e9;

int a[MAXN];
int f1[MAXN], f2[MAXN];
int c1[MAXN], c2[MAXN];

vector<int> ans[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  int total1 = 0, total2 = 0;
  REP(i, n) {
    scanf("%d", a+i);
    if (a[i] == 1) f1[++total1] = i; else
      f2[++total2] = i;
    c1[i] = total1;
    c2[i] = total2;
  }

  int cnt = 0;
  FOR(t, 1, n+1) {
    int pos = 0, s1 = 0, s2 = 0;
    int cur1 = 0, cur2 = 0;
    bool ok = true;
    bool last = false;

    while (pos < n) {
      int next1 = cur1 + t <= total1 ? f1[cur1 + t] : inf;
      int next2 = cur2 + t <= total2 ? f2[cur2 + t] : inf;
      int next = min(next1, next2);
      if (next >= n) { ok = false; break; }
      
      if (next == next1) last = true, s1++; else
        s2++, last = false;
      
      if (next == next1) assert(cur1+t == c1[next]);
      if (next == next2) assert(cur2+t == c2[next]);

      cur1 = c1[next];
      cur2 = c2[next];
      pos = next + 1;
    }
    
    if (ok && s1 != s2)
      if ((s1 > s2) == last) {
        ans[max(s1, s2)].push_back(t);
        cnt++;
    }
  }

  
  printf("%d\n", cnt);
  REP(s, n+1) for (int t: ans[s]) printf("%d %d\n", s, t);
  return 0;
}