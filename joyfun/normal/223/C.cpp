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

const int N = 2005;
const int mod = 1e9+7;
int n, k, a[N], b[N];

int pow_mod(int x, int k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	b[1] = 1;
	for (int i = 2; i <= n; i++)
		b[i] = 1ll * b[i - 1] * (k + i - 2) % mod * pow_mod(i - 1, mod - 2) % mod;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = i, k = 1; j >= 1; j--, k++) 
			sum = (sum + 1ll * a[j] * b[k] % mod) % mod;
		printf("%d ", sum);
	}
	return 0;
}