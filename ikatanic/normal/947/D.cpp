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

bool can(int sa, int sb, int ta, int tb) {
  if (sb > tb || sa < ta) return false;

  if ((sb == 0 && tb > 0) || (sa % 3 != ta % 3)) {
    if (sa == 0 || sa == ta) return false;
    sa = ta;
    sb += 2;
  }

  if (sb > tb) return false;

  return (tb - sb) % 2 == 0;
}

void calc(char* S, int* sa, int* sb) {
  int N = strlen(S);
  int ca = 0, cb = 0;
  REP(i, N) {
    if (S[i] == 'A') {
      ca++;
    } else {
      ca = 0;
      cb++;
    }
    sa[i] = ca;
    sb[i] = cb;
  }
}

const int MAX = 100100;

char S[MAX], T[MAX];
int sa[MAX], sb[MAX];
int ta[MAX], tb[MAX];

int main(void) {
  scanf("%s", S);
  scanf("%s", T);

  calc(S, sa, sb);
  calc(T, ta, tb);

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    --a, --b, --c, --d;

    int v_sa = min(b - a + 1, sa[b]);
    int v_sb = sb[b] - (a == 0 ? 0 : sb[a - 1]);
    int v_ta = min(d - c + 1, ta[d]);
    int v_tb = tb[d] - (c == 0 ? 0 : tb[c - 1]);

    putchar(can(v_sa, v_sb, v_ta, v_tb) ? '1' : '0');
  }
  putchar('\n');
  return 0;
}