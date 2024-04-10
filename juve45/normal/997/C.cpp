#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long MOD = 998244353;
const long long N = 1001000;
long long n, k, pow3[N], comb[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long powMod(long long base, long long exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;
	long long ret = powMod(base, exp / 2);
	ret = (ret * ret) % MOD;
	if(exp % 2) ret = (ret * base) % MOD;
	return ret;
}

long long invMod(long long k) {
	return powMod(k, MOD - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	pow3[0] = 1;
	for(long long i = 1; i <= n; i++) {
		pow3[i] = (pow3[i - 1] * 3) % MOD;
	}


	comb[0] = 1;
	long long ans = 0, sgn = 1;
	for(long long i = 1; i <= n; i++) {
		// dbg(invMod(i));
		comb[i] = (((comb[i - 1] * (n - i + 1)) % MOD) * invMod(i)) % MOD;
	}
	sgn = -1;
	ans = powMod((MOD + pow3[n] - 3) % MOD, n);
	// dbg(ans);
	for(long long i = 1; i <= n; i++) {
		long long a = pow3[n - i];
		long long b = (3 * powMod(a - 1, n) + (pow3[i] - 3) * (powMod(a, n) )) % MOD;
		// dbg(a);
		// dbg(b);
		// dbg(comb[i]);
		ans +=  (sgn * (comb[i] *b) % MOD) % MOD;
		ans %= MOD;
		if(ans < 0) ans += MOD;
		sgn = -sgn;
		// dbg(ans);
	}
	cout << (powMod(3, n * n) - ans + MOD) % MOD << '\n';
}