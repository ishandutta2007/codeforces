	#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const long long MOD = 998244353;
long long n, k, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	ans = n;
	for(long long i = 1; i <= n; i++) {
		ans *= i;
		ans %= MOD;
	}
	// dbg(ans);
	long long p = 1;
	for(long long i = n; i >= 2; i--) {
		p *= i;
		// dbg(p);
		p %= MOD;
		ans -= p;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	cout << ans << '\n';

}