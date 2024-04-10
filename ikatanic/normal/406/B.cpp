#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAX = 1000100;
const int s = 1000000;

int x[MAX], y[MAX];
bool taken[MAX];
bool bio[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", x+i);
    taken[x[i]] = true;
  }

  int cnt = 0, m = 0;
  REP(i, n)
    if (!bio[x[i]]) {
      if (taken[s-x[i]+1]) {
        bio[s-x[i]+1] = true;
        cnt++; 
      } else {
        y[m++] = s-x[i]+1;
        taken[s-x[i]+1] = true;
      }
    }

  for (int i = 1; i <= s && cnt > 0; ++i)
    if (!taken[i] && !taken[s-i+1]) {
      y[m++] = i;
      y[m++] = s-i+1;
      taken[i] = taken[s-i+1] = true;
      cnt--;
    }

  printf("%d\n", m);
  REP(i, m)
    printf("%d%c", y[i], i < m-1 ? ' ' : '\n');
  return 0;
}