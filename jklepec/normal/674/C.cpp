#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;

const lf inf = 1e30 + 5;
const int MAXN = 2e5 + 5, MAXK = 55;

lf dp[MAXN][MAXK];

lf sum[MAXN], pref[MAXN], sve[MAXN];
lf calc(int l, int r) {
   lf ret = sve[r];
   if(l) {
      ret -= sve[l - 1];
      ret -= sum[l - 1] * (pref[r] - pref[l - 1]);
   }
   return ret;
}

int j;
void solve(int lo, int hi, int glo, int ghi) {
   if(lo > hi) return;
   int md = (hi + lo) / 2;
   int p = glo; lf mn = inf;
   if(md == 0) {
      mn = 0;
   }
   else if(md < j) {
      mn = inf;
   }
   else if(md == j) {
      mn = j + 1;
   }
   else {
      for(int i = glo; i <= min(ghi, md - 1); ++i) {
         lf tmp = dp[i][j - 1] + calc(i + 1, md);
         if(tmp < mn || mn < 0) {
            mn = tmp;
            p = i;
         }
      }
   }
   dp[md][j] = mn;
   solve(md + 1, hi, p, ghi);
   solve(lo, md - 1, glo, p);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n, k; cin >> n >> k;
   rep(i, n) {
      lf x; cin >> x;
      sum[i] = x + (i ? sum[i - 1] : 0);
      sve[i] = sum[i] / x + (i ? sve[i - 1] : 0);
      pref[i] = 1 / x + (i ? pref[i - 1] : 0);
   }

   for(int i = 0; i < n; ++i) {
      dp[i][0] = calc(0, i);
   }
   for(j = 1; j < k; ++j) {
      solve(0, n - 1, 0, n - 1);
   }
   cout << fixed << setprecision(6) << dp[n - 1][k - 1];
}