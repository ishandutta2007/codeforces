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

const int N = 53;
int n;
string ss[55];
int dp[N][N][N][N], w[N][N], s[N][N];

int solve(int x, int y, int xx, int yy) {
	if(dp[x][y][xx][yy] == -1) {
		// dbg(x, y, xx, yy);
		dp[x][y][xx][yy] = max(xx - x + 1, yy - y + 1);

		if(s[xx][yy] - s[xx][y - 1] - s[x - 1][yy] + s[x - 1][y - 1] == 0) {
			dp[x][y][xx][yy] = 0;
			return 0;
		}

		for(int l = x; l <= xx; l++) {
				// dbg(l);
				// dbg(s[l][yy], s[l][y - 1]);
			if(s[l][yy] - s[l][y - 1] - s[l - 1][yy] + s[l - 1][y - 1] == 0) {
				dp[x][y][xx][yy] = min(dp[x][y][xx][yy], solve(x, y, l - 1, yy) + solve(l + 1, y, xx, yy));				
			}
		}

		for(int l = y; l <= yy; l++)
			if(s[xx][l] - s[x - 1][l] - s[xx][l - 1] + s[x - 1][l - 1] == 0)
				dp[x][y][xx][yy] = min(dp[x][y][xx][yy], solve(x, y, xx, l - 1) + solve(x, l + 1, xx, yy));				
	}
	return dp[x][y][xx][yy];

}

int main() {
	ios_base::sync_with_stdio(false);


	cin >> n;
	


	for(int i = 1; i <= n; i++) {
		cin >> ss[i];
		ss[i] = "." + ss[i] + ".";
	}



	for(int i = 1; i <= n; i++)
		for(int j= 1; j <= n; j++)
			if(ss[i][j] == '.')
				w[i][j] = 0;
			else w[i][j] = 1;

	for(int i = 1; i <= n; i++)
		s[i][0] = w[i][0] + s[i - 1][0];
	for(int i = 1; i <= n; i++)
		s[0][i] = w[0][i] + s[0][i - 1];

	for(int i = 1; i<= n; i++) {
		for(int j = 1; j <= n; j++) {
			s[i][j] = w[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j -1];
		}
	}

	memset(dp,-1, sizeof dp);
	cout << solve(1, 1, n, n) << '\n';

	dbg(dp[1][1][4][1]);
}