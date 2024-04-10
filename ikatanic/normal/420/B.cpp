#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

int s[MAXN];
vector<int> E[MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    char ch[5];
    int x;
    scanf("%s %d", ch, &x); --x;
    E[x].push_back(ch[0] == '+' ? +(i+1) : -(i+1));
  }
  m += 2;

  REP(i, n) {
    int last = 0;
    for (int tip: E[i])
      if (tip < 0) s[last]++, s[-tip]--, last = 0; else
        last = tip;
    if (last) s[last]++, s[m]--;
  }

  for (int i = 1; i <= m; ++i) s[i] += s[i-1];
  for (int i = 0; i <= m; ++i) {
    s[i] = (s[i] > 0);
    if (i > 0) s[i] += s[i-1];
  }

  static vector<int> ans;
  REP(i, n) {
    int tot = 0;
    int last = 0;
    for (int tip: E[i])
      if (tip < 0) tot += s[-tip-1] - (last-1 >= 0 ? s[last-1] : 0), last = 0; else
        last = tip;
    if (last) tot += s[m]-s[last-1];
    if (tot == s[m] || E[i].size() == 0) ans.push_back(i+1);
  }

  printf("%d\n", (int)ans.size());
  REP(i, (int)ans.size())
    printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');
  return 0;
}