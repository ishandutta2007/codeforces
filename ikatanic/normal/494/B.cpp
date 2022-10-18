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

const int MAXN = 100100;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

char text[MAXN];
char pattern[MAXN];
int fail[MAXN];
int last_match[MAXN];
int f[MAXN], fsum[MAXN];
int fsumsum[MAXN];

int main(void) {
  scanf("%s", text);
  scanf("%s", pattern);
  int text_len = strlen(text);
  int pattern_len = strlen(pattern);

  fail[0] = 0;
  FOR(i, 1, pattern_len) {
    fail[i] = fail[i-1];
    while (fail[i] && pattern[i] != pattern[fail[i]]) fail[i] = fail[ fail[i]-1 ];
    if (pattern[i] == pattern[fail[i]]) fail[i]++;
  }

  int match = 0, last = -1;
  REP(i, text_len) {
    while (match && pattern[match] != text[i]) match = fail[match-1];
    if (pattern[match] == text[i]) match++;
    if (match == pattern_len) {
      last = i - pattern_len + 1;
      match = fail[match-1];
    }
    last_match[i] = last;
  }

  f[0] = fsum[0] = fsumsum[0] = 1;
  FOR(i, 1, text_len + 1) {
    f[i] = 0;
    if (last_match[i-1] != -1) f[i] = add(f[i], fsumsum[last_match[i-1]]);
    fsum[i] = add(fsum[i-1], f[i]);
    fsumsum[i] = add(fsumsum[i-1], fsum[i]);
  }
  
  int ans = sub(fsum[text_len], 1);
  printf("%d\n", ans);
  return 0;
}