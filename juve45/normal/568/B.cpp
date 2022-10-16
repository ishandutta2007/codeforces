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


const long long MOD = 1e9 + 7;
const int N = 4e3 + 6;
long long n, k, fact[N], dp[N][N], invf[N], p2[N];

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
	if(k == 0 || n == k) return 1;
	return (1LL * fact[n] * invf[k] % MOD) * invf[n - k] % MOD;
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
	p2[0] = 1;
	for(long long i = 1; i < N; i++) {
		fact[i] = (1LL * i * fact[i - 1]) % MOD;
		invf[i] = invMod(fact[i]);
		p2[i] = p2[i - 1] * 2 % MOD;
	}
}

// long long fdp(int n, int k) {
// 	if(n < 2 * k) return 0;
// 	return comb(n , k) * comb(n - k, k) * powMod(k, n - 2 * k);
// }

int main() {
	ios_base::sync_with_stdio(false);

	pre();
	cin >> n;
	// dp[1] = 1;

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
			dp[i][j] = (dp[i - 2][j - 1] * (i - 1) + dp[i - 1][j] * j) % MOD;

	long long ans = 0;
	for(int i = 1; i <= n; i++) 
		for(int j = 0; j <= n; j++) {
			// dbg(i, j, (powMod(2, i) - 1) * comb(n, i) * dp[n - i][j]);
			ans += ((p2[i] - 1) * comb(n, i) % MOD ) * dp[n - i][j] % MOD;
			ans %= MOD;
	}
	cout << ans << '\n';
}