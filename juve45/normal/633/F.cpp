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

const long long N = 100100;
long long n, dp[N][4], a[N], x, y;
vector <long long> v[N];

void dfs(long long node, long long ant = -1) {
	// dbg(node);
	for(auto i : v[node])
		if(i != ant)
			dfs(i, node);

	dp[node][0] = a[node];
	dp[node][1] = a[node];
	dp[node][2] = a[node];
	dp[node][3] = a[node];
	long long max3 = 0;

	for(auto i : v[node]) {
		if(i == ant) continue;
		// if(node == 1) {
		// 	dbg_v(dp[node], 4);
		// 	dbg_v(dp[i], 4);
		// }
		dp[node][0] = max({dp[node][0], dp[i][0], 
			dp[i][2] + dp[node][1], 
			dp[node][2] + dp[i][1], 
			dp[node][3] + dp[i][3]});
		dp[node][2] = max({dp[node][2], dp[i][1] + dp[node][1], dp[i][2] + a[node], dp[node][1] + dp[i][3], max3 + dp[i][1] + a[node]});
		dp[node][3] = max({dp[node][3], dp[i][3], dp[i][1] + dp[node][1]});
		dp[node][1] = max(dp[node][1], dp[i][1] + a[node]);
		max3 = max(max3, dp[i][3]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin >> a[i];

	for(long long i = 1; i< n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);
	// dbg_v(dp[5], 4);
	// dbg_v(dp[4], 4);
	// dbg_v(dp[2], 4);
	// dbg_v(dp[3], 4);
	// dbg_v(dp[1], 4);
	cout << dp[1][0];
}