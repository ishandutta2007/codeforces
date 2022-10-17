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

const long long N = 255;
long long n, k, dp[N][N];


const long long MOD = 1e9 + 7;
// const long long N = 1e5 + 6;
long long fact[N * N], invf[N * N], pk[N* N], pk1[N* N];

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
	return (1LL * (fact[n] * invf[k] % MOD) * invf[n - k] % MOD);// invMod((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
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
	pk[0] = 1;
	pk1[0] = 1;
	for(long long i = 1; i < N * N; i++) {
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
		invf[i] = invMod(fact[i]);
		pk[i] = pk[i - 1] * k % MOD;
		pk1[i] = pk1[i - 1] * (k - 1) % MOD;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	pre();

	dp[0][0] = 1;
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= n; j++) {
			// dbg(i, j);
			// dp[i][j] = powMod(k, i - 1) * powMod(k, j - 1) * dp[i - 1][j - 1];
			if(i == 1 || j == 1)  {
				dp[i][j] = 1;
				continue;
			}

			// dp[i][j] += dp[i][j - 1];
			for(long long ii = 0; ii <= i; ii++) {
				long long mm = comb(i, ii) * pk[i - ii] % MOD;
				if(ii == 0)
					mm -= comb(i, ii) * pk1[i-ii] % MOD, mm += MOD, mm %= MOD;

				dp[i][j] += (dp[i - ii][j - 1] * mm % MOD) * pk1[ii * (j - 1)] % MOD;
				dp[i][j] %= MOD;
				// dbg(i, j, ii, mm, dp[i][j], dp[i - ii][j - 1]);
			}



				// for(long long jj = 0; jj < j; jj++) {
				// 	long long mul = k;
				// 	if(ii == 0 || jj == 0) mul = 1;
				// 	long long mm = comb(i - 1, ii) * comb(j - 1, jj) * powMod(k - 1, i - 1 - ii) * powMod(k - 1, j - 1 - jj) * mul * powMod(k, ii * jj);
				// 	dbg(i, j, ii, jj, mm);
				// 	dp[i][j] += dp[i - 1 - ii][j - 1 - jj] * mm;
				// 	dbg(i, j, ii, jj, dp[i][j]);
				// }
					// if(ii != 0 || jj != 0)
		}

	cout << dp[n][n];
}