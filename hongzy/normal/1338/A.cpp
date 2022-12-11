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
int n, a[N], b[N];
int mxb(int u) {
	for(int i = 30; i >= 0; i --) {
		if(u >> i & 1) {
			return i + 1;
		}
	}
	return 0;
}
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
			b[i] = i == 1 ? a[1] : max(b[i - 1], a[i]);
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			ans = max(ans, mxb(b[i] - a[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}