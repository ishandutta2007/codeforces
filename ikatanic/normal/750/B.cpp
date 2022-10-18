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

void answer(bool good) {
  puts(good ? "YES" : "NO");
  exit(0);
}

int main(void) {
  int n;
  int cur = 0;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    char dir[11];
    scanf("%d %s", &x, dir);

    if (cur == 0 && dir[0] != 'S') answer(false);
    if (cur == 20000 && dir[0] != 'N') answer(false);

    if (dir[0] == 'S') {
      if (cur + x > 20000) answer(false);
      cur += x;
    }
    if (dir[0] == 'N') {
      if (cur - x < 0) answer(false);
      cur -= x;
    }
  }
  
  answer(cur == 0);
    
  return 0;
}