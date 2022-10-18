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

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

const int MAXN = 55;
const int MAXM = 1010;

bitset<MAXM> b[MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &m, &n);
  REP(i, n) {
    char s[MAXM];
    scanf("%s", s);
    REP(j, m) if (s[j] == '1') b[i].set(j);
  }

  vector<bool> bio(m, 0);
  vector<int> szs;
  REP(i, m) {
    if (!bio[i]) {
      static bitset<MAXM> a;
      REP(j, m) a.set(j);
      REP(j, n) {
        if (b[j].test(i)) {
          a &= b[j];
        } else {
          a &= ~b[j];
        }
      }

      int cnt = 0;
      REP(j, m) {
        if (a.test(j)) {
          bio[j] = true;
          cnt++;
        }
      }
      assert(bio[i]);
      szs.push_back(cnt);
    }
  }

  vector<vector<int>> C(m+1, vector<int>(m+1, 0));
  REP(i, m+1) {
    C[i][0] = 1;
    FOR(j, 1, i+1) C[i][j] = add(C[i-1][j], C[i-1][j-1]);
  }

  vector<int> bell(m+1, 0);
  bell[0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < i; ++j) {
      bell[i] = add(bell[i], mul(C[i-1][j], bell[i-1-j]));
    }
  }

  int ans = 1;
  for (int x: szs) {
    ans = mul(ans, bell[x]);
  }
  printf("%d\n", ans);
  return 0;
}