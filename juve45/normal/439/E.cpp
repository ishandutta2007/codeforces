#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long MOD = 1e9 + 7;
const long long N = 100100;
long long n = 6, s, MAX = 31, nr, f[N];
map<pair<long long, long long>, long long> dp;
vector <long long> d[N];

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long a) {
	return powMod(a, MOD - 2);
}

long long comb(long long n, long long k) {
	return (1LL * f[n] * invMod((1LL * f[k] * f[n - k]) % MOD)) % MOD;
}

long long F(long long n, long long f) {
	if(n < f) return 0;
	// dbg(n, f);
	if(dp.count({n, f})) 
		return dp[{n, f}];
	
	long long ans = comb(n - 1, f - 1);
	for(auto i : d[n]) {
		ans -= F(n / i, f);
		ans %= MOD;
	}

	dp[{n, f}] = ans;
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);

	f[0] = 1;
	for(long long i = 1; i < N; i++)
		f[i] = (i * f[i - 1]) % MOD;

	for(long long i = 2; i < N; i++)
		for(long long j = i; j < N; j += i)
			d[j].push_back(i);

	// dbg(F(6, 2));
	// dbg(F(7, 2));
		long long q, a, b;
		cin >> q;
		for(long long i = 1; i <= q; i++) {
			cin >> a >> b;
			cout << (F(a, b) + MOD) % MOD << '\n';
		}
	// dbg(nr);
}