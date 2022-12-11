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
const int mod = 998244353;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, k, pos[N], a[N];
bool tag[N];
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i); pos[a[i]] = i;
	}
	ll res = 0;
	int pre = -1, ans = 1;
	for(int i = 1; i <= n; i ++) {
		if(a[i] >= n - k + 1) {
			res += a[i];
			if(~ pre) {
				int sz = i - pre - 1;
				ans = (ll) ans * (sz + 1ll) % mod;
			}
			pre = i;
		}
	}
	printf("%lld %d\n", res, ans);
	return 0;
}