#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 15;
const int MAXK = 500005;
const int MAXL = 11;
const int inf = 1e9;
 
int f[1<<MAXN][110];
int nextC[MAXK][MAXN];
int invCnt[1<<MAXN][MAXN];
llint w[MAXK];
llint a[MAXN];

llint readWord() {
  static char s[15];
  scanf("%s", s);
  llint ans = 0;
  int len = strlen(s);
  REP(i, len)
    ans = ans*27 + s[i]-'a'+1;
  return ans;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) a[i] = readWord();

  int invMax = n*(n-1)/2 + 1;
  REP(s, (1<<n)) REP(i, n) {
    invCnt[s][i] = 0;
    REP(j, n)
      if ((s&(1<<j)) && j > i) invCnt[s][i]++;
  }

  int m;
  scanf("%d", &m);

  int bestp = -1, ind;
  REP(i, m) {
    int k;
    scanf("%d", &k);
    REP(j, k) w[j] = readWord();

    static map<llint, int> M;
    M.clear();
    for (int j = k; j >= 0; --j) {
      if (j < k) M[w[j]] = j;
      REP(i, n)
        nextC[j][i] = M.count(a[i]) ? M[a[i]] : inf;
    }
    
    REP(s, (1<<n)) REP(j, invMax) f[s][j] = inf;
    f[0][0] = 0;
    REP(s, (1<<n)) REP(j, invMax)
      if (f[s][j] < inf) {
        REP(i, n)
          if (!(s&(1<<i)))
            f[s|(1<<i)][j + invCnt[s][i]] = min(f[s|(1<<i)][j + invCnt[s][i]], nextC[f[s][j]][i] + 1);
      }

    REP(j, invMax)
      if (f[(1<<n)-1][j] < inf && invMax-j > bestp) bestp = invMax-j, ind = i;
  }

  if (bestp == -1) puts("Brand new problem!"); else {
    printf("%d\n", ind+1);
    printf("[:");
    REP(i, bestp)
      printf("|");
    printf(":]\n");
  }
  return 0;
}