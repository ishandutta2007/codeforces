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

const int MAX = 500050;

int value[MAX], nxt[MAX];
bool asked[MAX];

void ask(int x) {
  if (asked[x]) return;
  asked[x] = true;
  printf("? %d\n", x);
  fflush(stdout);
  scanf("%d %d", &value[x], &nxt[x]);
}

int getValue(int x) {
  ask(x);
  return value[x];
}

int getNext(int x) {
  ask(x);
  return nxt[x];
}

void answer(int x) {
  printf("! %d\n", x);
  fflush(stdout);
  exit(0);
}


int main(void) {
  int n, start, x;
  scanf("%d %d %d", &n, &start, &x);

  int first = getValue(start);
  if (first >= x) answer(getValue(start));

  llint seed = 0;
  
  // first < x
  REP(it, 999) {
    seed = (seed * 1000003 + 10007) % 1000000007;
    int i = seed % n + 1;
    if (getValue(i) <= x && getValue(i) > getValue(start)) {
      start = i;
    }
  }

  while (start != -1 && getValue(start) < x) start = getNext(start);
  answer(start != -1 ? getValue(start) : -1);
  return 0;
}