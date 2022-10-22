#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 4e3 + 5, MAXK = 805, inf = MAXN * MAXN + MAXN;

int pref[MAXN][MAXN];

int w(int l, int r) {
   int ret = pref[r][r];
   if(l) {
      ret -= pref[l - 1][r];
      ret -= pref[r][l - 1];
      ret += pref[l - 1][l - 1];
   }
   return ret / 2;
}

int dp[MAXN][MAXK];

int j = 1;
void solve(int lo, int hi, int glo, int ghi) {
   if(lo > hi) return;
   int md = (lo + hi) / 2;

   if(md <= j) {
      solve(md + 1, hi, glo, ghi);
      return;
   }

   int ret = inf, pw = -1;
   for(int k = glo; k <= min(md - 1, ghi); ++k) {
      if(dp[k][j - 1] + w(k + 1, md) < ret) {
         ret = dp[k][j - 1] + w(k + 1, md);
         pw = k;
      }
   }
   dp[md][j] = ret;
   solve(lo, md - 1, glo, pw);
   solve(md + 1, hi, pw, ghi);
}

char s[MAXN][MAXN * 2];

int main() {

   int n, k; scanf("%d %d\n", &n, &k);
   rep(i, n) gets(s[i]);

   rep(i, n) rep(j, n) {
      pref[i][j] = s[i][j * 2] - '0';
      if(i) pref[i][j] += pref[i - 1][j];
      if(j) pref[i][j] += pref[i][j - 1];
      if(i && j) pref[i][j] -= pref[i - 1][j - 1];
   }
   rep(i, n) {
      dp[i][0] = w(0, i);
   }
   for(; j < k; ++j) {
      solve(0, n - 1, 0, n - 1);
   }
   cout << dp[n - 1][k - 1];
}