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
int n, dp[N][333], a[N], m, s, e, b[N], ans;
vector <int> v[N];

int cost(int pos, int val) {
	if(pos > m) return 1e8;

	int ret = *upper_bound(v[val].begin(), v[val].end(), pos);
	// dbg(pos, val, ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n >> m >> s >> e;

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++) {
		cin >> b[i]; 
		v[b[i]].push_back(i);
	}
	for(int i = 1; i <= 1e5; i++)
		v[i].push_back(1e9);

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= min(i, 300); j++) {
			if(j == 0)
				dp[i][j] = 0;
			else
				dp[i][j] = min(dp[i - 1][j], cost(dp[i - 1][j - 1], a[i]));

			// dbg(i, j, dp[i][j]);
			if(i + dp[i][j] + j * e <= s)
				ans = max(ans, j);
		}
	}
	cout << ans << '\n';
}