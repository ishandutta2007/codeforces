#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 300100;
const long long MOD = 1e9 + 7;
long long n, k, x[N], p2[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	p2[0] = 1;
	for(long long i = 1; i <= n; i++)
		p2[i] = (p2[i - 1] * 2) % MOD;

	for(long long i = 1; i <= n; i++)
		cin >> x[i];

	if(n == 1)
		return cout << "0\n", 0;

	sort(x + 1, x + n + 1);

	// for(long long i = n - 1; i > 0; i--) 
	// 	d[i] = (x[i + 1] - x[i]) * (n - i) + d[i + 1];

	long long sum = (x[n] - x[n - 1]) % MOD;
	long long ans = sum;
	for(long long i = n - 2; i > 0; i--) {
		long long d = x[i + 1] - x[i];
		sum = (sum * 2LL + (d * (p2[n - i] - 1)) % MOD) % MOD;
		ans += sum;
		ans %= MOD;
	}
	cout << ans << '\n';

}