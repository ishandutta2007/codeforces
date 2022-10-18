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

const int MAX = 100100;

int main(void) {
  int n;
  scanf("%d", &n);

  vector<int> cnt(MAX, 0);
  
  REP(i, n) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }

  bool win = false;
  REP(i, MAX) win |= cnt[i] % 2;

  puts(win ? "Conan" : "Agasa");
  return 0;
}