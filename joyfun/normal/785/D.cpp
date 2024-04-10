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

const int N = 200005;
const int mod = 1e9+7;
char s[N];
int f[N], rf[N], n;

int pow_mod(int x, int k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return ans;
}

int C(int n, int m) {
	if (n < m || n < 0 || m < 0) return 0;
	return 1ll * f[n] * rf[m] % mod * rf[n - m] % mod;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f[0] = 1; for (int i = 1; i < N; i++) f[i] = 1ll * f[i - 1] * i % mod;
	rf[N - 1] = pow_mod(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; i--) rf[i] = 1ll * rf[i + 1] * (i + 1) % mod;
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++) r += s[i] == ')';
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			l++;
			ans = (ans + C(l + r - 1, r - 1)) % mod;
		} else r--;
	}
	printf("%d\n", ans);
	return 0;
}