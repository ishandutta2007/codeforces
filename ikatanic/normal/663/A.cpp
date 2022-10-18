#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int sign = 1;
  char s[111];
  vector<int> v;
  while (scanf("%s", s) == 1) {
    if (s[0] == '+') { sign = +1; continue; }
    if (s[0] == '-') { sign = -1; continue; }
    if (s[0] == '=') break;
    if (sign > 0) {
      v.push_back(+1);
    }
    else {
      v.push_back(-1);
    }
  }

  scanf("%s", s);
  int n = stoi(s);

  vector<int> A, B;
  REP(i, (int)v.size())
    if (v[i] == +1) A.push_back(i);
    else B.push_back(i);

  int a = A.size();
  int b = B.size();

  auto output = [&] (vector<int>& ans) {
    puts("Possible");
    int tot = 0;
    REP(i, (int)v.size()) {
      if (i > 0) {
        if (v[i] == 1) printf("+ ");
        else printf("- ");
      }
      printf("%d ", ans[i]);
      assert(1 <= ans[i] && ans[i] <= n);
      tot += v[i] * ans[i];
    }
    assert(tot == n);
    printf("= %s\n", s);
    exit(0);
  };

  auto test = [&] (int x, int y) {
    if (y == 0) {
      int sa = x*a;
      int sb = sa - n;
      if (sb < b || sb > b*n) return;
      
      vector<int> ans(v.size());
      REP(i, a) ans[A[i]] = x;
      REP(i, b) {
        ans[B[i]] = min(n, sb - (b - i - 1));
        sb -= ans[B[i]];
      }
      output(ans);
    } else {
      int sb = y*b;
      int sa = n + sb;
      if (sa < a || sa > a*n) return;
      
      vector<int> ans(v.size());
      REP(i, b) ans[B[i]] = y;
      REP(i, a) {
        ans[A[i]] = min(n, sa - (a - i - 1));
        sa -= ans[A[i]];
      }
      output(ans);
    }
  };

  test(1, 0);
  test(n, 0);
  test(0, 1);
  test(0, n);

  puts("Impossible");
  return 0;
}