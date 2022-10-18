#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int mod = 1e9 + 7;
const int MAXN = 220;
const int MAXK = 520;

string p[MAXN];
int val[MAXN], slj[MAXN][22];

int f[2][3][MAXN][MAXK];
int n, b, k, m;

enum {DIRA, MANJI, VECI};

int solve(int len, int a[MAXN], bool eq) {
  auto update = [] (int &x, int y) {
    if ((x += y) >= mod) x -= mod;
  };
  
  int ans = 0;
  f[0][DIRA][0][0] = 1;
  
  REP(i, len+1) {
    int now = i&1, next = now^1; 
    REP(d, 3) REP(pr, m) REP(s, k+1)
      if (f[now][d][pr][s]) {
        int &r = f[now][d][pr][s];

        if (i < len) update(ans, r); else {
          if (d == MANJI || (d == DIRA && eq)) update(ans, r);
        }

        if (i < len)
          REP(c, b) {
            if (i == 0 && c == 0) continue;

            int nd = d;
            if (d == DIRA) {
              if (c < a[i]) nd = MANJI; else
                if (c > a[i]) nd = VECI;
            }
            
            int npr = slj[pr][c];
            if (s + val[npr] <= k)
              update(f[next][nd][npr][s + val[npr]], r);
          }
        r = 0;
      }
  }
  
  return ans;
}

int main(void) {
  scanf("%d %d %d", &n, &b, &k);
  
  int l[MAXN], r[MAXN];
  int lenl, lenr;

  scanf("%d", &lenl);
  REP(i, lenl) scanf("%d", l+i);

  scanf("%d", &lenr);
  REP(i, lenr) scanf("%d", r+i);

  string a[MAXN];
  int v[MAXN];
  set<string> S;
  REP(i, n) {
    int len, x;
    scanf("%d", &len);
    REP(j, len) {
      scanf("%d", &x);
      a[i].push_back('a' + x);
    }
    REP(j, len+1)
      S.insert(a[i].substr(0, j));
    scanf("%d", v+i);
  }

  string p[MAXN];
  m = 0;
  for (string s: S) p[m++] = s;

  REP(i, n) REP(j, m)
    if (p[j].size() >= a[i].size())
      if (p[j].substr(p[j].size() - a[i].size()) == a[i]) val[j] += v[i];

  REP(j, m) REP(c, b) {
    string s = p[j];
    s.push_back('a' + c);
    while (S.find(s) == S.end()) s.erase(s.begin());
    slj[j][c] = -1;
    REP(w, m)
      if (p[w] == s) slj[j][c] = w;
    assert(slj[j][c] != -1);
  }

  int ans = solve(lenr, r, true) - solve(lenl, l, false);
  if (ans < 0) ans += mod;

  printf("%d\n", ans);
  return 0;
}