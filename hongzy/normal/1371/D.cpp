#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
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
ll S(ll n) {
	return n * (n + 1) / 2;
}
int n, k, ans[N][2];
char s[310][310];
ll calc() {
	static ll x[310], y[310];
	rep(i, 1, n) x[i] = y[i] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(s[i][j] == '1') {
				x[i] ++; y[j] ++;
			}
		}
	}
	ll mxr = *max_element(x + 1, x + n + 1);
	ll mnr = *min_element(x + 1, x + n + 1);
	ll mxc = *max_element(y + 1, y + n + 1);
	ll mnc = *min_element(y + 1, y + n + 1);
	return (mxr - mnr) * (mxr - mnr) + (mxc - mnc) * (mxc - mnc);
}
int main() {
	int t; cin >> t;
	while(t --) {
		cin >> n >> k;
		rep(i, 1, n) {
			rep(j, 1, n) s[i][j] = '0';
			s[i][n + 1] = 0;
		}
		int la = n - 1;
		rep(i, 1, k) {
			la = (la + 1) % n;
			ans[i][0] = la + 1;
		}
		int c = 0;
		per(i, n, 1) {
			int p = i;
			rep(j, 1, n) {
				ans[++ c][1] = p;
				if(c == k) break ;
				p = p == n ? 1 : p + 1;
			}
		}
		rep(i, 1, k) s[ans[i][0]][ans[i][1]] = '1';
		printf("%lld\n", calc());
		rep(i, 1, n) puts(s[i] + 1);
	}
	return 0;
}