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

const long long N = 300100;
long long n, a[N], dp[N][11], ans, fre;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		// if(a[i] <= 2) free += a[i];
		long long nr = min(fre, a[i] / 2LL);
		ans += nr;
		
		fre -= nr;
		a[i] -= nr * 2;

		ans += a[i] / 3;
		fre += a[i] % 3;
		// dbg(i, ans, fre);
	}
	cout << ans << '\n';
	return 0;

	// for(long long i = 1; i <= 8; i++)
	// 	dp[0][i] = -1e18;

	// for(long long i = 1; i <= n; i++) {
	// 	for(long long j = 0; j <= 8; j++)
	// 		for(long long k = 0; k <= 8; k++) {
	// 			long long nr = a[i], c2 = 0;

	// 			if(j >= k) nr -= (j - k);
	// 			else c2 = min(nr, 2 * k);

	// 			long long nr = a[i] - j;
	// 			long long c2 = min(nr, 2 * k);
	// 			long long rest = max(0LL, k - c2);

	// 			long long c3 = max(nr - c2, 0LL);

	// 			dp[i][j] = max(dp[i][j], dp[i - 1][k] + c2 / 2 + c3 / 3);
	// 			if(i == n) ans = max(ans, dp[i][j]);
	// 		}
	// }
	// cout << ans << '\n';
}