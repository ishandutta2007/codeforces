#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 20;
const int MOD = 1000000007;

int n, dp[1<<N];

int pow_mod(int x, int k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % MOD;
		x = 1ll * x * x % MOD;
		k >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		dp[x]++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (1<<N); j++) {
			if (j>>i&1) continue;
			dp[j] += dp[j^(1<<i)];
		}
	}
	int ans = 0;
	for (int i = 1; i < (1<<N); i++) {
		int cnt = 0;
		for(int j = 0; j < N; j++)
			if (i>>j&1) cnt++;
		int tmp = (pow_mod(2, n) - pow_mod(2, dp[i]) + MOD) % MOD;
		if (cnt % 2) ans = (ans + tmp) % MOD;
		else ans = (ans - tmp + MOD) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}