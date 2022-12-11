#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, m, p, a[N], b[N];
void check(int i) {
	ll x = 0;
	for(int j = 0; j <= i; j ++) if(j <= n && i - j <= m) {
		(x += (ll) a[j] * b[i - j] % p) %= p;
	}
	if(x) {
		printf("%d\n", i);
		exit(0);
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &p); n --, m --;
	for(int i = 0; i <= n; i ++) scanf("%d", a + i);
	for(int i = 0; i <= m; i ++) scanf("%d", b + i);
	check(0); int x = 0;
	for(int i = 0; i <= n; i ++) {
		if(a[i] % p != 0) {
			x += i; break ;
		}
	}
	for(int i = 0; i <= m; i ++) {
		if(b[i] % p != 0) {
			x += i; break ;
		}
	}
	check(x);
	return 0;
}