#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 152;

int a[MAXN];
int dummy[6][2];

int x[MAXN];
int ret[MAXN];
int add[MAXN];

bool ok;
int fin;

void calc(int k) {
  ok = true;
  memset(ret, 0, sizeof ret);
  REP(i, MAXN - 1) {
    ret[i] += x[i] * dummy[k][1];
  }
  REP(i, MAXN - 1) {
    ret[i + 1] += x[i] * dummy[k][0];
  }
  REP(i, MAXN - 1) {
    ret[i] += add[i];
  }
  REP(i, MAXN) {
    if(ret[i] != 0)
      fin = ret[i];
    if(abs(ret[i]) > 1)
      ok = false;
  }
}

int A[MAXN];
int B[MAXN];

int main() {
  int n; cin >> n;

  dummy[0][0] = -1;

  dummy[1][0] = 1;

  dummy[2][0] = 1;
  dummy[2][0] = 1;

  dummy[3][0] = -1;
  dummy[3][0] = -1;

  dummy[4][0] = -1;
  dummy[4][0] = 1;

  dummy[5][0] = 1;
  dummy[5][0] = -1;

  A[0] = -1;

  bool found;

  REP(i, n) {
    found = false;
    REP(j, 2) {
      memcpy(x, A, sizeof x);
      memcpy(add, B, sizeof add);
      calc(j);
      if(ok) {
        if(A[n - 1] == fin) {
          found = true;

          memcpy(B, A, sizeof A);
          memcpy(A, ret, sizeof A);

          break;
        }
      }
    }
    if(found) continue;
    REP(j, 2) {
      memcpy(x, A, sizeof x);
      memcpy(add, B, sizeof add);
      calc(j);
      if(ok) {
        memcpy(B, A, sizeof A);
        memcpy(A, ret, sizeof A);

        break;

      }
    }
  }

  int glob = 1;
  if(fin == -1)
    glob = -1;

  int k1 = 0;
  REP(i, MAXN) {
    if(A[i] != 0) k1 = i;
  }

  if(A[k1] == -1) glob = -1;

  cout << k1 << endl;
  REP(i, k1 + 1)
    cout << A[i] * glob << " ";

  cout << endl;
  int k2 = 0;
  REP(i, MAXN) {
    if(B[i] != 0) k2 = i;
  }
  glob = 1;
  if(B[k2] == -1) glob = -1;

  cout << k2 << endl;
  REP(i, k2 + 1)
    cout << B[i] * glob << " ";
}