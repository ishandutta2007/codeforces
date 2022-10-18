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

const int MAXN = 100000;

bool bio[MAXN];
int a[MAXN];

int main(void) {
  int n, t;
  scanf("%d %d", &n, &t);
  REP(i, n-1) scanf("%d", a+i);
  
  bio[0] = true;
  REP(i, n)
    if (bio[i]) bio[i + a[i]] = true;
  puts(bio[t-1] ? "YES" : "NO");
  return 0;
}