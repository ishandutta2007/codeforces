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

const int N = 2019;
int n, zero;
double a[2 * N], sum, ans = 1e9;

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n;
	for(int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
		a[i] -= floor(a[i]);
		if(fabs(a[i]) <= 1e-5) zero++;
		sum += a[i];
	}

	for(int i = n; i >= max(0, n - zero); i--) {
		ans = min(ans, abs(sum - i));
	}
	cout << fixed << setprecision(3) << ans << '\n';


	// dp[0][0] = 0;
	// for(int i = 1; i <= 2 * n; i++) {
	// 	for(int j = 0; j <= n; j++) {
	// 		if(j > 0)
	// 			dp[i][j] = min(dp[i - 1][j] + a[i] - floor(a[i]), dp[i - 1][j - 1] + ceil(a[i]) - a[i]);
	// 		else
	// 			dp[i][j] = dp[i - 1][j] + a[i] - floor(a[i]);
	// 		dbg(i, j, dp[i][j]);	
	// 	}
	// }
	// cout << dp[2 * n][n] << '\n';
}