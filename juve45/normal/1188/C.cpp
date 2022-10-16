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

const int N = 1001;
const int MOD = 998244353;
int n, dp[2][N], a[N], k, f[100100], r[N];

int solve(int x) {

	for(int i = 1; i <= n; i++) {
		int j = upper_bound(a + 1, a + n + 1, a[i] - x) - a;
		j--;
		r[i] = j;
	}

	for(int j = 1; j <= k; j++) {
		for(int i = 1; i <= n; i++) 
			if(j == 1) dp[1][i] = 1;
			else dp[j%2][i] = dp[1 - j%2][r[i]];
		// dbg_v(dp[j%2], n + 1);
		for(int i = 2; i <= n; i++)
			dp[j%2][i] += dp[j%2][i - 1], dp[j%2][i] %= MOD;
	}
	return dp[k%2][n];
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);

	int mx = a[n] / (k - 1) + 1;
	// int mx = 11;
	for(int x = 0; x <= mx; x++)
		f[x] = solve(x);

	long long ans = 0;
	for(int x = 0; x < mx; x++) {
		f[x] -= f[x + 1];
		if(f[x] < 0) f[x] += MOD;
		ans += (1LL * x * f[x]) % MOD;
		ans %= MOD;
	}
	cout << ans << '\n';

}