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
const int K = 50;
const int MOD = 1e9 + 7;
int n;

int dp[K + 1][N][N];

// dp[i][j][k] -> i perechi, j ultimul numar, k cea mai mare diferenta pana acum

void pre() {

	dp[0][0][0] = 1;

	// for(int j = 1; j < N; j++)
	// 	for(int k = 1; k <= K; k++)
	// 		dp[1][j][k] = 1;


		for(int k = 1; k < N; k++)
			dp[0][0][k] = (dp[0][0][k - 1] + dp[0][0][k]) % MOD;


		for(int j = 1; j < N; j++)
			for(int k = 0; k < N; k++) {
				int i = 0;
				if(k == 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k]) % MOD;
				else dp[i][j][k] = (3LL * MOD + dp[i][j][k] + dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i][j - 1][k - 1]) % MOD;
			}

	for(int i = 1; i < K; i++) {

		for(int j = i; j < N; j++)
			for(int k = i; k < N; k++) {

				if(j - k < 0) continue;
				
				dp[i][j][k] = (2LL * MOD + dp[i][j][k] + 1LL * dp[i - 1][j - k][k - 1] * i) % MOD;
				// dp[i][j][k] += dp[i][j - 1][k];


				// dp[i][j][k] += dp[i][j - 1][k];
				
				// for(int j1 = 0; j1 + k <= j; j1++)
				// 	for(int k1 = 0; k1 < k; k1++) {
				// 		dbg(i, j, k, j1, k1);
				// 		dp[i][j][k] += i * dp[i - 1][j1][k1];
				// 	}
				// dbg(i, j, k, dp[i][j][k]);
			}

		for(int j = i; j < N; j++)
			for(int k = i; k < N; k++) {
				dp[i][j][k] = (4LL * MOD + dp[i][j][k] + dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i][j - 1][k - 1]) % MOD;
			}
		// 		dp[i][j][k] += dp[i][j][k - 1];
	}

}	

int main() {
	ios_base::sync_with_stdio(false);
	pre(); int t, x, y;
	cin >> t;
	while(t--) {
		cin >> x >> y;
		if(y >= K) cout << 0 << '\n';
		else cout << dp[y][x][N - 1] << '\n';
	}
	// cin >> n;	
}