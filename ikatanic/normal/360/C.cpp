#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define VAR(name, val) __typeof(val) name = (val)
#define FORC(it, V) for(VAR(it, (V).begin()); it != (V).end(); ++it)
#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 2002;
const int mod = 1000000007;

int dp[MAXN][MAXN];
int f[MAXN];
int n, k;

char s[MAXN];

int countLarger(int i) {
  return 25-(s[i]-'a');
}

int g(int i, int d) {
  return (n-(i+d))*(d+1);
}

void add(int i, int j, int d, int k) {
  dp[i][j] = (dp[i][j] + llint(d)*k)%mod;
}

int main(void)
{
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  
  dp[0][k] = 1;
  for (int i = 0; i <= n; ++i)
    for (int j = k; j >= 0; --j) {
      if (i > 0) add(i, j, f[j], 25-countLarger(i-1));
      if (dp[i][j] == 0 || i == n) continue;
      
      int lod = 0, hid = n-i-1;
      while (lod <= hid && g(i, lod) <= j) {
	add(i+lod+1, j-g(i, lod), dp[i][j], countLarger(i+lod));
	lod++;
      }
      while (hid >= lod && g(i, hid) <= j) {
	add(i+hid+1, j-g(i, hid), dp[i][j], countLarger(i+hid));
	hid--;
      }
      
      add(n, j, dp[i][j], 1);
      f[j] = (f[j] + dp[i][j])%mod;
    }

  printf("%d\n", dp[n][0]);
  return 0;
}