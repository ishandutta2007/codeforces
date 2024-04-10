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
int T, n, x, a[N];
int main() {
	scanf("%d", &T);
	while(T --) {
		scanf("%d%d", &n, &x);
		int res = 0;
		for(int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
		}
		sort(a + 1, a + n + 1, greater<int>());
		ll sum = 0;
		for(int i = 1; i <= n; i ++) {
			sum += a[i];
			if(sum >= 1ll * x * i) {
				res = i;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}