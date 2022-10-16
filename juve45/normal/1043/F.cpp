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

const int N = 300100;
const int MAX = 300000;
const int MOD = 1e9 + 7;

int n, v[N], a[N], dp[11][N], f[N];

int powMod(int base, int exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;
	int tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (1LL * tmp * base) % MOD;
	return tmp;
}

int invMod(int k) {
	return powMod(k, MOD - 2);
}

int comb(int n, int k) {
	if(k > n) return 0;
	return 1LL * f[n] * invMod((1LL * f[k] * f[n - k]) % MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	f[0] = 1;
	for(int i = 1; i <= MAX; i++)
		f[i] = (1LL * i * f[i - 1]) % MOD;

	for(int i = 1; i <= n; i++) cin >> a[i], dp[1][a[i]]++;

	for(int i = 1; i <= MAX; i++)
		for(int j = i; j <= MAX; j += i)
				v[i] += dp[1][j];

	// dbg(comb(3, 2));

		// dbg_v(dp[1], 20);
	if(dp[1][1] == 1) return cout << "1\n", 0;
	for(int i = 2; i < 9; i++) {
		for(int j = MAX; j >= 1; j--)  {
			dp[i][j] = comb(v[j], i);
			// dbg(i, j, dp[i][j]);
			for(int k = 2 * j; k <= MAX; k += j)
				dp[i][j] = (dp[i][j] + MOD - dp[i][k]) % MOD;
		}
		// dbg(i);
		// dbg_v(dp[i], 20);
		if(dp[i][1])
			return cout << i << '\n', 0;
	}
	cout << "-1\n";

}