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

// const long long N = ;
long long n, m, k, x, y;


const long long MOD = 998244353;
const long long N = 4005;
long long fact[N], invf[N], ans, dp1[N][N], dp2[N][N], f1[N], f2[N], free1, free2;

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
	return (1LL * (fact[n] * invf[k]) % MOD * invf[n - k]) % MOD;//invMod((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
}

long long perm_rep(vector <long long> v) {
	long long sum = 0;
	for(auto i : v) 
		sum += i;
	long long ans = fact[sum];
	for(auto i : v) 
		ans = (1LL * ans * invMod(fact[i])) % MOD;
	// dbg(v);
	// dbg(ans);
	return ans;
}


void pre() {
	fact[0] = 1;
	invf[0] = 1;
	for(long long i = 1; i < N; i++) {
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
		invf[i] = invMod(fact[i]);
	}
}

void compute(long long * f, long long dp[N][N], long long n)  {
	dp[0][0] = 1;
	for(long long i = 1; i <= n; i++) {
		for(long long j = 0; j <= n; j++)
			dp[i][j] = dp[i - 1][j];
		if(i > 1 && f[i] == f[i - 1] && f[i] == 0) {
			// dbg(i);
			for(long long j = 1; j <= n; j++) {
				dp[i][j] += dp[i - 2][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	pre();

	cin >> n >> m >> k;

	for(long long i = 1; i <= k; i++) {
		cin >> x >> y;
		f1[x] = 1;
		f2[y] = 1;
		cin >> x >> y;
		f1[x] = 1;
		f2[y] = 1;
	}

	for(long long i = 1; i <= n; i++)
		free1 += (f1[i] == 0);
	for(long long i = 1; i <= m; i++)
		free2 += (f2[i] == 0);

	compute(f1, dp1, n);
	// dbg_v(f1, n + 1);
	// for(int i = 0; i <= 5; i++)
	// 	for(int j = 0; j <= 5; j++)
	// 		cerr << dp1[i][j] << " \n"[j == 5];

	compute(f2, dp2, m);

	for(long long i = 0; i <= max(free1, free2); i++)
		for(long long j = 0; j <= max(free1, free2); j++) {
			if(2 * i + j > free1 || 2 * j + i > free2) continue;
			long long c1 = (dp1[n][i] * comb(free1 - 2 * i, j)) % MOD;
			long long c2 = (dp2[m][j] * comb(free2 - 2 * j, i)) % MOD;
			// dbg(i, j, c1, c2);
			// dbg(dp1[n][i], dp2[m][i]);
			long long mul = c1 * c2 % MOD;
			ans += ((mul * fact[i]) % MOD * fact[j]) % MOD;
			ans %= MOD;
		}
	cout << ans << '\n';

}