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

const int N = 100005;
const int mod = 1e9+7;
int n, c[N], b[N];

int pow_mod(int x, int k) {
	if (k < 0) return 0;
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		c[x]++;
	}
	for (int i = 1; i < N; i++) c[i] += c[i - 1];
	int tot = 0;
	for (int i = 1; i < N; i++) {
		int bn = 0;
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				b[++bn] = j - 1;
				if (i / j != j) b[++bn] = i / j - 1;
			}
		}
		sort(b + 1, b + bn + 1);
		int ans = 1;
		for (int j = 1; j <= bn; j++) {
			int cc = c[b[j + 1]] - c[b[j]];
			if (j == bn) {
				cc = n - c[b[j]];
				ans = 1ll * ans * (pow_mod(j, cc) - pow_mod(j - 1, cc) + mod) % mod;
			}
			else ans = 1ll * ans * pow_mod(j, cc) % mod;
		}
		tot += ans; if (tot >= mod) tot -= mod;
	}
	printf("%d\n", tot);
	return 0;
}