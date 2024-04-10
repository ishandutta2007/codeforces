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

int main(void) {
  char s[300100], t[300100], ans[300100];
  scanf("%s", s);
  scanf("%s", t);

  int n = strlen(s);
  sort(s, s + n);
  sort(t, t + n);
  
  int sl = 0, sr = (n+1)/2-1;
  int tl = n-n/2, tr = n-1;
  int rl = 0, rr = n-1;

  REP(i, n) {
    if (i % 2 == 0) {
      if (s[sl] < t[tr]) ans[rl++] = s[sl++];
      else ans[rr--] = s[sr--];
    } else {
      if (t[tr] > s[sl]) ans[rl++] = t[tr--];
      else ans[rr--] = t[tl++];
    }
  }
  ans[n] = 0;
  puts(ans);
  
  return 0;
}