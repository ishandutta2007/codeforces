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

vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> days = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main(void) {
  char a[111], b[111];
  scanf("%s", a);
  scanf("%s", b);

  int x = 0, y = 0;
  REP(i, 7) {
    if (days[i] == a) x = i;
    if (days[i] == b) y = i;
  }

  for (int i = 0; i < 11; ++i) {
    if ((x + months[i]) % 7 == y) { puts("YES"); return 0; }
  }
  puts("NO");
  return 0;
}