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
const int H2 = 10007;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 3;
const int MAX = 200010;

typedef pair<int, int> par;

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

int pwrs1[26], pwrs2[26];
int nxt[MAX][26];
int match[26];

par get_hash() {
  int h1 = 0, h2 = 0;
  REP(k, 26) {
    h1 = add(h1, mul(pwrs1[k], match[k]+'a', mod1), mod1);
    h2 = add(h2, mul(pwrs2[k], match[k]+'a', mod2), mod2);
  }
  return {h1, h2};
}

int main(void) {
  pw1[0] = pw2[0] = 1;
  FOR(i, 1, MAX) {
    pw1[i] = mul(pw1[i-1], H1, mod1);
    pw2[i] = mul(pw2[i-1], H2, mod2);
  }

  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", a);
  scanf("%s", b);

  h1[0] = h2[0] = 0;
  REP(i, m) {
    h1[i+1] = add(mul(h1[i], H1, mod1), b[i], mod1);
    h2[i+1] = add(mul(h2[i], H2, mod2), b[i], mod2);
  }
  par hash = {h1[m], h2[m]};

  vector<int> ans;
  REP(i, m) {
    pwrs1[a[i]-'a'] = add(pwrs1[a[i]-'a'], pw1[m-i-1], mod1);
    pwrs2[a[i]-'a'] = add(pwrs2[a[i]-'a'], pw2[m-i-1], mod2);
  }

  REP(k, 26) nxt[n][k] = n;
  for (int i = n-1; i >= 0; --i) {
    REP(j, 26) nxt[i][j] = nxt[i+1][j];
    nxt[i][a[i]-'a'] = i;
  }
  
  for (int i = 0; i + m <= n; ++i) {
    REP(k, 26) match[k] = -1;

    REP(k, 26)
      if (nxt[i][k] < i + m) {
        match[k] = b[nxt[i][k] - i] - 'a';
      }

    REP(k, 26)
      if (match[k] != -1) match[ match[k] ] = k;
    REP(k, 26)
      if (match[k] == -1) match[k] = k;
    
    bool ok = true;
    REP(k, 26)
      ok &= k == match[ match[k] ];
    
    if (ok && get_hash() == hash) ans.push_back(i);

    int c = a[i] - 'a';
    pwrs1[c] = sub(pwrs1[c], pw1[m-1], mod1);
    pwrs2[c] = sub(pwrs2[c], pw2[m-1], mod2);
    
    REP(k, 26) {
      pwrs1[k] = mul(pwrs1[k], H1, mod1);
      pwrs2[k] = mul(pwrs2[k], H2, mod2);
    }
    
    if (i + m < n) {
      int nc = a[i + m] - 'a';
      pwrs1[nc] = add(pwrs1[nc], 1, mod1);
      pwrs2[nc] = add(pwrs2[nc], 1, mod2);
    }
  }
  
  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x+1);
  printf("\n");
  return 0;
}