#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 1e5+5;
int m, n, a[N], AA;
ll A;
unordered_set<int> H;

int pow_mod(int x, int k, int mod) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * k % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return ans;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {x = 1; y = 0; return a;}
	ll d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int b[N];

bool ck(int x, int d) {
	int w = x;
	int BB = (1ll * n * x % m * x + 1ll * n * (n - 1) % m * d % m * x + 1ll * (n - 1) * n * (n + n - 1) / 6 % m * d % m * d % m) % m;
	if (AA != BB) return false;
	for (int i = 1; i <= n; i++) {
		if (!H.count(w)) return false;
		w += d; if (w >= m) w -= m;
	}
	return true;
}

int judge(int d) {
	ll c = A - 1ll * n * (n - 1) / 2 * d;
	ll x, y;
	ll gd = exgcd(n, m, x, y);
	if (c % gd) return -1;
	int X = (1ll * c / gd % m * x % m + m) % m;
	if (ck(X, d)) return X;
	return -1;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), A += a[i], H.insert(a[i]), b[i] = a[i], AA = (AA + 1ll * a[i] * a[i] % m) % m;
	sort(a + 1, a + 1 + n);
	if (n == 1) {
		printf("%d 0\n", a[1]);
	} else if (n > m) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			int d = ((b[i] - b[1]) % m + m) % m;
			int tmp = judge(d);
			if (tmp != -1) {
				printf("%d %d\n", tmp, d);
				return 0;
			}
		}
		printf("-1\n");
	}
	return 0;
}