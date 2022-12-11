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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int cnt[N], n, m;
ll num[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x); cnt[x % m] ++; num[x % m] = x;
	}
	ll ans = 1;
	for(int i = 0; i < m; i ++) if(cnt[i] > 1) ans = 0;
	for(int i = 0; i < m; i ++) if(cnt[i]) {
		for(int j = i + 1; j < m; j ++) if(cnt[j]) {
			ans = ans * abs(num[i] - num[j]) % m;
		}
	}
	printf("%lld\n", ans % m);
	return 0;
}