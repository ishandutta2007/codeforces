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

const int MAX = 80;
const int inf = 1e9;

int f[MAX][MAX][MAX][2];

char a[MAX];
int x[MAX];

vector<int> v[3];

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", a);

  REP(i, n) {
    if (a[i] == 'V') {
      x[i] = 0;
    } else if (a[i] == 'K') {
      x[i] = 1;
    } else {
      x[i] = 2;
    }
    v[x[i]].push_back(i);
  }

  int n0 = v[0].size();
  int n1 = v[1].size();
  int n2 = v[2].size();
  
  REP(i, n0+1) REP(j, n1+1) REP(k, n2+1) REP(c, 2) f[i][j][k][c] = inf;

  f[0][0][0][0] = 0;
  REP(i, n0+1) REP(j, n1+1) REP(k, n2+1) REP(c, 2) {
    if (f[i][j][k][c] == inf) continue;
    
    int pos = i+j+k;
    int c0 = 0, c1 = 0, c2 = 0;
    REP(l, pos) {
      if (x[l] == 0) c0++;
      else if (x[l] == 1) c1++;
      else if (x[l] == 2) c2++;
    }

    vector<int> rem;
    int d0 = i - c0;
    int d1 = j - c1;
    int d2 = k - c2;

    for (int l = pos-1; l >= 0; --l) {
      if (x[l] == 0) {
        if (d0 < 0) rem.push_back(x[l]), d0++;
      }
      if (x[l] == 1) {
        if (d1 < 0) rem.push_back(x[l]), d1++;
      }
      if (x[l] == 2) {
        if (d2 < 0) rem.push_back(x[l]), d2++;
      }
    }


    reverse(rem.begin(), rem.end());

    FOR(l, pos, n) {
      if (x[l] == 0) {
        if (d0 > 0) d0--;
        else rem.push_back(x[l]);
      }
      if (x[l] == 1) {
        if (d1 > 0) d1--;
        else rem.push_back(x[l]);
      }
      if (x[l] == 2) {
        if (d2 > 0) d2--;
        else rem.push_back(x[l]);
      }
    }
    
    assert(d0 == 0 && d1 == 0 && d2 == 0);
    assert((int)rem.size() == n-pos);
    
    int next0 = -1, next1 = -1, next2 = -1;
    FOR(l, pos, n) {
      if (rem[l-pos] == 0 && next0 == -1) next0 = l;
      if (rem[l-pos] == 1 && next1 == -1) next1 = l;
      if (rem[l-pos] == 2 && next2 == -1) next2 = l;
    }

    
    if (i < n0) {
      f[i+1][j][k][1] = min(f[i+1][j][k][1], f[i][j][k][c] + abs(pos - next0));
    }
    if (j < n1 && !c) {
      f[i][j+1][k][0] = min(f[i][j+1][k][0], f[i][j][k][c] + abs(pos - next1));
    }
    if (k < n2) {
      f[i][j][k+1][0] = min(f[i][j][k+1][0], f[i][j][k][c] + abs(pos - next2));
    }
  }

  int ans = min(f[n0][n1][n2][0], f[n0][n1][n2][1]);
  printf("%d\n", ans);
  return 0;
}