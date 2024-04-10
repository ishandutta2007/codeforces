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

const int MAX = 2020;

bitset<MAX> b[MAX];
bitset<MAX> c[MAX];
int n, m;

void output(bitset<MAX> b[MAX]) {
  REP(i, n) {
    REP(j, n) {
      if (b[i].test(j)) putchar('1'); else putchar('0');
    }
    putchar('\n');
  }
  putchar('\n');
  
}

int main(void) {
  vector<pair<int, int>> v;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;
    v.push_back({x, y});
    b[y][x] = 1;
  }

  REP(i, n) c[i].set(i);
  
  REP(i, n) {
    int k = -1;
    FOR(j, i, n)
      if (b[j].test(i)) { k = j; break; }
    assert(k != -1);

    swap(b[i], b[k]);
    swap(c[i], c[k]);

    REP(j, n)
      if (i != j && b[j].test(i)) {
        b[j] ^= b[i];
        c[j] ^= c[i];
      }
  }

  for (auto& p: v) {
    if (c[p.first].test(p.second)) puts("NO");
    else puts("YES");
  }
  return 0;
}