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

const int MAX = 300300 * 31;

struct Node {
  int t[2];
  int cnt;
} m[MAX];

int alloc = 1;

int main(void) {
  int N;
  scanf("%d", &N);
  vector<int> A(N);
  REP(i, N) scanf("%d", &A[i]);

  int root = alloc++;
  REP(i, N) {
    int x;
    scanf("%d", &x);

    int cur = root;
    for (int j = 29; j >= 0; --j) {
      m[cur].cnt++;
      int b = (x >> j) & 1;
      if (m[cur].t[b] == 0) {
        m[cur].t[b] = alloc++;
      }
      cur = m[cur].t[b];
    }
    m[cur].cnt++;
  };

  REP(i, N) {
    int P = A[i];
    int cur = root;
    for (int j = 29; j >= 0; --j) {
      m[cur].cnt--;

      int c = (A[i] >> j) & 1;
      int b = (m[cur].t[c] && m[ m[cur].t[c] ].cnt > 0) ? c : (c ^ 1);
      assert(m[cur].t[b] && m[ m[cur].t[b] ].cnt);
      cur = m[cur].t[b];
      P ^= (b << j);
    }
    m[cur].cnt--;

    printf("%d ", P);
  }
  printf("\n");
  return 0;
}