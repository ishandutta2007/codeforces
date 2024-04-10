#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int t, l, r;
ll dp[5000005];
int prm[5000005];
int pw[5000005];

int main() {
	t = read(), l = read(), r = read();
	pw[0] = 1;
	rep(i, r - l) pw[i + 1] = 1LL * pw[i] * t % mod;
	for (int i = 2; i <= r; ++ i) prm[i] = -1;
	for (int i = 2; i * i <= r; ++ i) if (!~prm[i]) {
		for (int j = i * i; j <= r; j += i) if (!~prm[j]) prm[j] = i;
	}
	for (int i = 2; i <= r; ++ i) {
		if (!~prm[i]) dp[i] = 1LL * i * (i - 1) / 2;
		else dp[i] = dp[prm[i]] * (i / prm[i]) + dp[i / prm[i]];
	}
	int ans = 0;
	for (int i = l; i <= r; ++ i) {
		ans += 1LL * pw[i - l] * (dp[i] % mod) % mod;
		if (ans >= mod) ans -= mod;
	}
	printf("%d\n", ans);
	return 0;
}