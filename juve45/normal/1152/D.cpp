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
const int MOD = 1e9 + 7;
int n, dp[N][N], ans[2];

bool valid(int level, int diff) {
	if(diff < 0) return 0;
	if(2 * n - level < diff) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n;

	dp[1][1] = 1;
	ans[0] = 1;
	for(int i = 1; i <= 2 * n; i++) {
		for(int j = 0; j <= n; j++) {
			
			ans[i % 2] = (ans[i % 2] + dp[i][j]) % MOD;

			if(valid(i + 1, j + 1))
				dp[i + 1][j + 1] += dp[i][j],
				dp[i + 1][j + 1] %= MOD;;
			if(valid(i + 1, j - 1))
				dp[i + 1][j - 1] += dp[i][j],
				dp[i + 1][j - 1] %= MOD;
		}
		// dbg(i, ans[0], ans[1]);
	}
	cout << ans[1] << '\n';
}