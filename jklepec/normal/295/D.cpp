#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

using namespace std;

typedef long long ll;

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

const int MAXN = 2020;

int n, m;
int dp[MAXN][MAXN], dpm[MAXN][MAXN], rast[MAXN], strt[MAXN];

void postavi(int red) {
   int k = m - 1;
   REP(i, m - 1) {
      rast[i] = mul(dp[red][i], k);
      strt[i] = dp[red][i];
      if(i) strt[i] = add(strt[i], strt[i - 1]);
      if(i) rast[i] = add(rast[i], rast[i - 1]);
      k --;
   }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   cin >> n >> m;

   FOR(i, 0, m - 1) {
      dp[0][i] = 1;
      dpm[0][i] = 1;
   }

   postavi(0);
   FOR(i, 1, n) {
      FOR(j, 0, m - 1) {
         dp[i][j] = 1;
         dp[i][j] = add(rast[j], dp[i][j]);
         dp[i][j] = sub(dp[i][j], mul(strt[j], m - 2 - j));
         dpm[i][j] = 1;
         if(j) {
            dpm[i][j] = add(rast[j - 1], dpm[i][j]);
            dpm[i][j] = sub(dpm[i][j], mul(strt[j - 1], m - 2 - j));
         }
      }
      postavi(i);
   }

   int sol = 0;
   FOR(i, 0, n) {
      FOR(j, 0, m - 1) {
         sol = add(sol, mul(m - 1 - j, mul(dpm[i][j], dp[n - i - 1][j])));
      }
   }
   cout << sol;
}