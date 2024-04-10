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
long long n, m, comp[N], dp[N];

vector <long long> v[N], pr[N];

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

inline long long cnt(long long nr) { return m / nr; }

long long f(long long sub, long long nr) {
	long long ret = 0;
	long long dif = nr / sub;
	long long n = pr[dif].size();

	for(long long i = 0; i < (1 << n); i++) {
			// dbg(i);
			long long mul = 1;
			
			for(long long j = 0; j < n; j++)
				if(i & (1 << j))
					mul *= pr[dif][j];
		// dbg(i, mul, pr[dif]);
		if(__builtin_popcount(i) % 2 == 0)
			ret += cnt(mul * sub);
		else 
			ret -= cnt(mul * sub);
		// dbg(mul, ret);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> m;

	// dbg(invMod(2));
	// dbg(invMod(3));

	for(long long i = 1; i <= m; i++)
		for(long long j = 2 * i; j <= m; j+= i)
			v[j].push_back(i);

	for(long long i = 2; i <= m; i++)
		if(!comp[i]) {
			pr[i].push_back(i);
			for(long long j = 2 * i; j <= m; j+= i)
				pr[j].push_back(i), comp[j] = 1;
		}

	dp[1] = 0;
	for(long long i = 2; i <= m; i++) {
		dp[i] = 1;
		for(auto j : v[i]) {
			// dbg(i, j, f(j, i));
			dp[i] += ((invMod(m) * f(j, i) % MOD) * dp[j]) % MOD;
			dp[i] %= MOD;
		}
		dp[i] *= invMod(m - f(i, i));
		dp[i] %= MOD;
		dp[i] *= m;
		dp[i] %= MOD;
	}
	// dbg_v(dp, m + 1);
	long long ans = 0;
	for(long long i = 1; i <= m; i++) {
		ans += (invMod(m) * (dp[i] + 1)) % MOD;
		ans %= MOD;
	}
	cout << ans << '\n';
}