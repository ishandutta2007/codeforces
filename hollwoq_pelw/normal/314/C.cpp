#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}	
}

const int N = 1e6 + 5, mod = 1e9 + 7;

int n, dp[N / 10 + 5], last[N], bit[N];

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

inline void sadd(int &a, int b) {
	if ((a += b) >= mod) a -= mod;
}

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

inline void update(int p, int v) {
	for (; p < N; p += p & -p)
		sadd(bit[p], v);
}

inline int query(int p) {
	int r = 0;
	for (; p > 0; p -= p & -p)
		sadd(r, bit[p]);
	return r;
}

void solve_case() {
	cin >> n;

	int res = 0;

	update(1, 1);

	for (int i = 1, a; i <= n; i++) {
		cin >> a;
		dp[i] = mul(query(a), a);
		update(a, dp[i]);
		sadd(res, dp[i]);
		if (last[a] && dp[last[a]]) {
			update(a, mod - dp[last[a]]);
			sadd(res, mod - dp[last[a]]);
		}
		last[a] = i;
	}

	cout << res << '\n';
}