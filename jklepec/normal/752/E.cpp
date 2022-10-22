#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
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

const int MAX = 1e7, MAXN = 1e6;
int dp[MAX];

int n, k;
int a[MAXN];

bool ok(int md) {
   memset(dp, 0, sizeof dp);
   dp[md] = 1;
   for(int i = md + 1; i <= MAX; ++i) {
      dp[i] = max(dp[i / 2] + dp[i - i / 2], 1);
   }
   ll uk = 0;
   rep(i, n) {
      uk += dp[a[i]];
      if(uk >= k) return true;
   }
   return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   cin >> n >> k;
   rep(i, n) cin >> a[i];

	int lo = 0, hi = MAX;

	while(lo < hi) {
      int md = (lo + hi + 1) / 2;
      if(ok(md)) lo = md;
      else hi = md - 1;
	}
	cout << (lo == 0 ? -1 : lo);
}