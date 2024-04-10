#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define pb push_back
#define x first
#define y second

typedef long long ll;

const int MAX = 100;

int N;
char A[MAX][MAX];
char B[MAX][MAX];

int main(void) {
  ios_base::sync_with_stdio(false);
  
  cin >> N;
  REP(i, N) cin >> A[i];
  REP(i, N) REP(j, N) A[i][j] -= '0';

  int hx = 0, hy = 0;
  int lx = MAX, ly = MAX;

  REP(i, N) REP(j, N) {
    if (!A[i][j]) continue;
    hx = max(hx, i);
    hy = max(hy, j);
    lx = min(lx, i);
    ly = min(ly, j);
  }

  auto add = [&](int x1, int y1, int x2, int y2) {
    FOR(i, x1, x2+1)
      FOR(j, y1, y2+1)
        ++B[i][j];
  };
  
  add(lx, ly, hx, hy);
  add(lx+1, ly, hx-1, hy);
  add(lx, ly+1, hx, hy-1);
  add(lx+1, ly+1, hx-1, hy-1);

  REP(i, N) REP(j, N) {
    if (A[i][j] != B[i][j]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0; 
}