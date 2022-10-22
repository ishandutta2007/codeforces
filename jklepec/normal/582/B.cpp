#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}

const int MAXN = 105, MAXL = 30;

int n, t;
int a[MAXN];
int dp[MAXN][MAXN], ndp[MAXN][MAXN]; // [l][r]
int best[MAXL][MAXN][MAXN];

void build_dp() {
   REP(i, n) {
      memcpy(ndp, dp, sizeof dp);
      FOR(l, 1, a[i] + 1) {
         ndp[l][a[i]] ++;
         FOR(r, a[i] + 1, n + 1) {
            ndp[l][r] = max(ndp[l][r], ndp[l][a[i]]);
         }
      }
      memcpy(dp, ndp, sizeof dp);
   }
}

void Merge(int (&x)[MAXN][MAXN], int (&y)[MAXN][MAXN]) {
   memset(ndp, 0, sizeof ndp);
   FOR(l, 1, n + 1) {
      FOR(r, l, n + 1) {
         FOR(k, l, r + 1) {
            ndp[l][r] = max(ndp[l][r], x[l][k] + y[k][r]);
         }
      }
   }
}

int sol[MAXN][MAXN];
int actual[3 * MAXN];
vector<int> saz, v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   cin >> n >> t;
   REP(i, n) {
      cin >> a[i];
      saz.push_back(a[i]);
   }
   sort(saz.begin(), saz.end());
   int cookie = 1;
   REP(i, saz.size()) {
      if(!i || saz[i] != saz[i - 1]) actual[saz[i]] = cookie++;
   }
   REP(i, n) a[i] = actual[a[i]];

   build_dp();
   memcpy(best[0], dp, sizeof dp);

   FOR(i, 1, MAXL) {
      Merge(best[i - 1], best[i - 1]);
      memcpy(best[i], ndp, sizeof ndp);
   }

   int tmp = 0;
   for(; t; t /= 2, tmp ++) {
      if(t % 2)
         v.push_back(tmp);
   }

   for(auto x : v) {
      Merge(sol, best[x]);
      memcpy(sol, ndp, sizeof sol);
   }

   cout << sol[1][n];
}