#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 100100
#define NMAX 
#define MMAX 

using namespace std;


const long long MOD = 1000000009;
long long n, k, a, b;

long long sk[DMAX], sgn[DMAX], pa[DMAX], pb[DMAX];
string s;
long long ans;


template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long pw(long long base, long long exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;
	long long aux = pw(base, exp / 2);
	if(exp % 2) return (((aux * aux) % MOD) * base) % MOD;
	return (aux * aux) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b >> k;

	cin >> s;

	pa[0] = 1;
	pb[0] = 1;
	for(long long i = 1; i <= k; i++) {
		pa[i] = (pa[i - 1] * a) % MOD;
		pb[i] = (pb[i - 1] * b) % MOD;
	}


	for(long long i = 0; i < k; i++)
		if(s[i] == '-') sgn[i] = -1;
		else sgn[i] = 1;

	for(long long i = 0; i < k; i++) {
		sk[i] = (sgn[i] * pa[k - i - 1] * pb[i]) % MOD;
		if(sk[i] < 0) sk[i] += MOD;
	}

	// dbg_v(sk, k + 1);

	for(long long i = 0; i < k; i++)
		sk[i] += sk[i - 1],
		sk[i] %= MOD;

	if(k > 10000 || n < 100000) {
		for(long long i = 1; i <= (n + 1) / k; i++) {
			ans += (((sk[k - 1] * pw(a, n + 1 - k * i)) % MOD) * pw(b, k * (i - 1))) % MOD;
			ans %= MOD;
		}
	}
	else {
		long long n1 = (n + 1) / k;
		long long ans2 = 0;
		long long bkt = sqrt(n1);
		long long X = 0;

		for(long long i = 0; i < bkt; i++)
			X += (pw(a, (bkt - i) * k) * pw(b, i * k)), 
			X %= MOD;

		// dbg(bkt);
		// dbg(n1);
		// dbg(X);

		int i;


		for(i = 0; i < n1; i++) {
			if(i + bkt < n1) {

				ans2 += ((X * pw(a, (n1 - i - bkt - 1) * k) ) % MOD)* pw(b, i * k) % MOD;
				ans2 %= MOD;
				i += bkt;
				i--;
				continue;
			}
			ans2 += pw(a, (n1 - i - 1) * k) * pw(b, i * k);
			ans2 %= MOD;
		}

		// for(i = 0; i < n1; i += bkt) {
		// 	ans2 += (((X * pw(a, (n1 - 1 - i - bkt) * k)) % MOD) * pw(b, i * k)) % MOD;
		// }
		// // for(long long i = 0; i < n1 / bkt - 1; i++) {
		// // 	ans2 += (X * (pw(b, i * bkt * k) % MOD)* pw(a, (n1 - bkt * (i + 1) - 1)) * k) % MOD;
		// // 	ans2 %= MOD;
		// // }
		// dbg(ans2);
		// dbg(i);
		// i -= bkt;
		// for(; i < n1; i++) {
		// 	ans2 += pw(a, (n1 - i - 1) * k) * pw(b, i * k);
		// 	ans2 %= MOD;
		// }
		// dbg(ans2);
		ans += sk[k - 1] * ans2;
		ans %= MOD;
	}

	cout << ans << '\n';

}