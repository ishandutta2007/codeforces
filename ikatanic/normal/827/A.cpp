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

const int MAX = 2000100;

char ans[MAX];
char s[MAX];
pair<int, char*> eq[MAX];

int main(void) {
  int n;
  scanf("%d", &n);

  char* cur = s;
  int ans_len = 0;
  REP(i, n) {
    int k;
    scanf("%s %d", cur, &k);
    int len = strlen(cur);
    REP(i, k) {
      int x;
      scanf("%d", &x); --x;
      eq[x] = max(eq[x], {len, cur});
      ans_len = max(ans_len, x + len);
    }
    cur += len;
  }

  REP(i, ans_len) {
    if (eq[i].first == 0) {
      ans[i] = 'a';
    } else {
      ans[i] = *eq[i].second;
      eq[i + 1] = max(eq[i + 1], {eq[i].first - 1, eq[i].second + 1});
    }
  }
  ans[ans_len] = '\0';
  puts(ans);
  return 0;
}