#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1000100;
const int mod = 1e9 + 7;
const int H = 9937;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int pw[MAX];

char a[MAX], b[MAX];
map<char, int> M = { {'N', 0}, {'S', 1}, {'W', 2}, {'E', 3} };

int main(void) {
  pw[0] = 1;
  FOR(i, 1, MAX) pw[i] = mul(pw[i-1], H);

  int n;
  scanf("%d", &n); n--;
  scanf("%s", a);
  scanf("%s", b);

  REP(i, n) a[i] = M[a[i]], b[i] = M[b[i]];

  static int ha[MAX], hb[MAX];
  for (int i = n-1; i >= 0; --i) {
    ha[i] = add(mul(H, ha[i+1]), a[i]);
    hb[i] = add(mul(pw[n-i-1], b[i]^1), hb[i+1]);
   
    if (ha[i] == hb[i]) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");
  return 0;
}