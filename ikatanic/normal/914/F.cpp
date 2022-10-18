#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100010;

bitset<MAX> b[26];
bitset<MAX> c;

char s[MAX];

int main(void) {
  scanf("%s", s);
  int n = strlen(s);
  REP(i, n) {
    b[s[i] - 'a'].set(i);
  }

  int m;
  scanf("%d", &m);
  REP(i, m) {
    int type;
    scanf("%d", &type);

    static char buf[MAX];

    if (type == 1) {
      int idx;
      scanf("%d %s", &idx, buf);
      idx--;

      b[ s[idx] - 'a' ].reset(idx);
      s[idx] = buf[0];
      b[ s[idx] - 'a' ].set(idx);
    } else {
      int l, r;
      scanf("%d %d %s", &l, &r, buf);
      --l;
      int m = strlen(buf);
      c.set();
      REP(i, m) {
        int ch = buf[i] - 'a';
        c &= b[ch] >> (l + i);
      }

      int k = r - l - m + 1;
      c <<= MAX - k;

      int ans = c.count();
      printf("%d\n", ans);
    }
  }
  return 0;
}