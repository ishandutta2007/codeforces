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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 102;
const int MOD = 1e9 + 9;
int n, dp[3][N][N * N], a[N], f[N];
long long fact[N];


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
	return (1LL * fact[n] * invMod((1LL * fact[k] * fact[n - k]) % MOD)) % MOD;
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
	for(long long i = 1; i < N; i++)
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
}


int main() {
	ios_base::sync_with_stdio(false);
	pre();
	int sum = 0, nrd = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(f[a[i]] == 0) nrd++;
		f[a[i]]++, sum += a[i];
	}
	if(nrd <= 2) return cout << n << '\n', 0;
	// dbg_v(f, 100);

	dp[0][0][0] = 1;
	dp[1][0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int k = 1; k <= i; k++)
			for(int j = 1; j <= 10000; j++)  {
				dp[i % 2][k][j] = dp[1 - i%2][k][j];
				
				if(a[i] <= j) {
					// dbg(1 - i%2, k - 1, j - a[i], dp[1 - i%2][k - 1][j - a[i]]);
					dp[i%2][k][j] += dp[1 - i%2][k - 1][j - a[i]];
				}
				dp[i%2][k][j] %= MOD;
				// if(dp[i%2][k][j] > 3) dp[i%2][k][j] = 3;
				// if(dp[i%2][k][j])
				// 	dbg(i, k, j, dp[i%2][k][j]);
			}
	// dbg_ok;
		// dbg(dp[0][2][8]);
	int ans = 1;
	for(int i = 1; i <= 100; i++)
		for(int k = 1; k <= f[i]; k++)
			if(dp[n%2][k][k * i] == comb(f[i], k) || dp[n%2][n-k][sum - k * i] == comb(f[i], f[i] - k)) ans = max(ans, k);
	cout << ans << '\n';

}