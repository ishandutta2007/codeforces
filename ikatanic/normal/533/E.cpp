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

const int H1 = 9973;
const int H2 = 1000003;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 3;
const int MAX = 100010;

typedef pair<int, int> par;

const int mod = 1e9 + 7;

int add(int a, int b, int mod) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b, int mod) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b, int mod) {
  return llint(a)*b % mod;
}

int pw1[MAX], pw2[MAX];
int h1[MAX], h2[MAX];
char a[MAX], b[MAX];

void gen(char *s, int n, vector<par> &v) {
  v.clear();
  h1[0] = h2[0] = 0;
  REP(i, n) {
    h1[i+1] = add(mul(h1[i], H1, mod1), s[i], mod1);
    h2[i+1] = add(mul(h2[i], H2, mod2), s[i], mod2);
  }
  
  REP(i, n+1) REP(k, 26) {
    int ha = sub(h1[n], mul(h1[i], pw1[n-i], mod1), mod1);
    ha = add(ha, mul(h1[i], pw1[n-i+1], mod1), mod1);
    ha = add(ha, mul(pw1[n-i], k+'a', mod1), mod1);

    int hb = sub(h2[n], mul(h2[i], pw2[n-i], mod2), mod2);
    hb = add(hb, mul(h2[i], pw2[n-i+1], mod2), mod2);
    hb = add(hb, mul(pw2[n-i], k+'a', mod2), mod2);

    v.push_back({ha, hb});
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

int main(void) {
  pw1[0] = pw2[0] = 1;
  FOR(i, 1, MAX) {
    pw1[i] = mul(pw1[i-1], H1, mod1);
    pw2[i] = mul(pw2[i-1], H2, mod2);
  }

  int n;
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  
  static vector<par> va, vb;
  gen(a, n, va);
  gen(b, n, vb);

  int ptr = 0, ans = 0;
  for (par p: vb) {
    while (ptr < (int)va.size() && va[ptr] < p) ptr++;
    ans += ptr < (int)va.size() && va[ptr] == p;
  }
  
  printf("%d\n", ans);
  return 0;
}