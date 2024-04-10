#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long MOD = 1e9 + 7;
long long n, k, ans, x;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long pw(long long base, long long exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;
	long long ans = pw(base, exp / 2);
	ans *= ans;
	ans %= MOD;
	if(exp % 2 == 0) return ans;
	return (ans * base) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> x >> k;

	if(x == 0) {
		cout << "0\n";
		return 0;
	}

	x %= MOD;
	long long ans = ((pw(2, k + 1) * x) % MOD - pw(2, k)) % MOD + 1;
	ans %= MOD;
	if(ans < 0) ans += MOD;
	ans %= MOD;
	cout << ans << '\n';
}