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
int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
ll ans[32];
int main() {
	int t; scanf("%d", &t) ;
	while(t --) {
		int d, m, c;
		scanf("%d%d", &d, &mod);
		fill(ans, ans + 30, 0);
		for(c = 0; (1 << (c + 1)) <= d; c ++) ;
		for(int i = 0; i < c; i ++) ans[i] = (1ll << i) % mod;
		ans[c] = (d - (1ll << c) + 1) % mod;
		ll res = 1;
		for(int i = 0; i <= c; i ++) res = res * (ans[i] + 1ll) % mod;
		res = (res + mod - 1) % mod;
		printf("%lld\n", res); 
	} 
	return 0;
}