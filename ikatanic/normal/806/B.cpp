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

const int MAX = 120;
const int inf = 1e9;

int a[MAX][5];
int val[5][6];
int c[5];
int solvers[5];
int n;

bool ret;


void rec(int i, int rem) {
  if (ret) return;
  
  if (i == 5) {
    int score[2];
    REP(i, 2) {
      score[i] = 0;
      REP(j, 5) {
        if (a[i][j] == -1) continue;
        int value = (c[j] + 1) * 500;
        
        score[i] += value;
        score[i] -= value/250 * a[i][j];
      }
    }
    if (score[0] > score[1]) ret = true;
    return;
  }
  
  REP(j, 6) {
    if (val[i][j] <= rem) {
      c[i] = j;
      rec(i+1, rem);
    }
  }
}

bool can(int R) {
  REP(i, 5) REP(j, 6) val[i][j] = inf;
  
  REP(i, 5) REP(c, 2) REP(k, R+1) {
    if (c == 1 && a[0][i] == -1) continue;
    if (c == 0 && k > 0) continue;
    
    llint p = solvers[i] + k*c;
    llint q = n + R;

    int score = 0;
    REP(j, 6) {
      if (p*(1<<(j+1)) > q || j == 5) {
        score = j;
        break;
      }
    }
    val[i][score] = min(val[i][score], k);
  }

  ret = false;
  rec(0, R);
  return ret;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    REP(j, 5) {
      scanf("%d", &a[i][j]);
      if (a[i][j] != -1) solvers[j]++;
    }
  }


  const int M = 4000;
  int k = 0;
  while (k < M && !can(k)) k++;

  if (k == M) {
    puts("-1");
  } else {
    printf("%d\n", k);
  }
  return 0;
}