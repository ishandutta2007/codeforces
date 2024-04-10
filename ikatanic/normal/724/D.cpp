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

char s[111111];
int n, m;
int cnt[26];

int main(void) {
  scanf("%d", &m);
  scanf("%s", s);
  n = strlen(s);
  REP(i, n) {
    cnt[s[i]-'a']++;
  }

  string ans = s;
  sort(ans.begin(), ans.end());
  
  REP(i, 26) {
    string nans = "";
    REP(j, i) REP(k, cnt[j]) nans.push_back('a' + j);

    bool ok = true;
    int prev = -1;
    REP(j, n + 1)
      if (j == n || s[j]-'a' < i) {
        int last = -1;
        int ptr = prev + 1;
        for (int x = prev + 1; x + m <= j; ++x) {
          while (ptr < x + m) {
            if (s[ptr]-'a' == i) last = ptr;
            ptr++;
          }
          if (last < x) { ok = false; break; }

          nans.push_back('a' + i);
          x = last;
        }
        
        prev = j;
      }

    if (ok) {
      ans = min(ans, nans);
    }
  }
  
  puts(ans.c_str());
  return 0;
}