#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
                      
int main(void) {
  int cnt = 0;
  for (int p: primes) {
    if (p*p > 100) break;
    
    int pw = 1;
    while (cnt < 2) {
      pw *= p;
      printf("%d\n", pw);
      fflush(stdout);
      char buf[10];
      scanf("%s", buf);

      if (buf[0] == 'y') {
        cnt++;
      } else {
        break;
      }
    }
  }

  if (cnt > 1) {
    puts("composite");
  } if (cnt == 0) {
    puts("prime");
  } else {
    for (int p: primes) {
      if (p*p > 100) {
        printf("%d\n", p);
        fflush(stdout);
        char buf[10];
        scanf("%s", buf);
        if (buf[0] == 'y') {
          puts("composite");
          return 0;
        }
      }
    }
    puts("prime");
  }
  return 0;
}