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

const int N = 100100;
const int MOD = 1e9 + 7;
int n, k, a[N], bad, f[N], ans, dp[N][4], vf[1026];
map <int, int> mp;

bool good(int k) {
	while(k) {
		if(k % 10 != 7 && k % 10 != 4)
			return 0;
		k /= 10;
	}
	return 1;
}

int val(int k) {
	if(mp.count(k) == 0) {
		int s = mp.size();
		mp[k] = s;
	}
	return mp[k];
}

int powMod(int base, int exp) {
	if(exp == 0) return 1;
	if(exp == 1) return base;
	int tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (1LL * tmp * base) % MOD;
	return tmp;
}

int invMod(long long k) {
	return powMod(k % MOD, MOD - 2);
}

int comb(int k, int n) {
	if(k > n || k < 0) return 0;
	return (1LL * f[n] * invMod(1LL * f[n - k] * f[k])) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	f[0] = 1;
	for(int i = 1; i <= n; i++) 
		f[i] = (1LL * i * f[i - 1]) % MOD;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(good(a[i])){
			// dbg(a[i]);
			vf[val(a[i])]++;
		}
		else bad++;
	}

	// dbg_v(vf, n + 1);

	for(int i = 0; i <= 1; i++)
		dp[0][i] = 1;

	for(int j = 0; j < 1024; j++)
		for(int i = 1; i <= j + 1; i++)
			if(j > 0)
				dp[i][j % 2] = (1LL * dp[i][1 - (j % 2)] + 1LL * dp[i - 1][1 - (j % 2)] * vf[j]) % MOD;
			else dp[i][j % 2] = vf[j];

	// dbg(bad, dp[2][2], dp[2][1]);
	// dbg(dp[1][1], dp[1][0]);
	// dbg(k);
	// dbg(comb(k, bad));

	for(int i = 0; i <= k; i++) {
		ans += (1LL * dp[i][1] * comb(k - i, bad)) % MOD;
		// dbg(i, ans, dp[i][1023], comb(k - i, bad));
		ans %= MOD;
	}
	cout << ans << '\n';
}