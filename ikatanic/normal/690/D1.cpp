#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 105;

int N, M;
char m[MAX][MAX];

int main(void) 
{
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%s", m[i]);

  string s(m[N - 1]);
  s = "." + s + ".";

  int sol = 0;
  REP(i, M + 1)
    if (s[i] == '.' && s[i + 1] == 'B')
      ++sol;

  printf("%d\n", sol);

  return 0;
}