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

const long long N = 200100;
set <pair<long long, long long> > s[N];
long long dp[N][2], sz[N], use[N], n, a, b, ans, odd;
vector <long long> v[N];

void dfs(long long node) {
	use[node] = 1;
	long long fth = -1;
	sz[node] = 1;
	dp[node][0] = 1;

	for(auto i : v[node]) 
		if(!use[i]) {
			dfs(i);
			odd += dp[node][0] * dp[i][0] + dp[node][1] * dp[i][1];
			ans += sz[i] * (n - sz[i]);
			dp[node][0] += dp[i][1];
			dp[node][1] += dp[i][0];
			sz[node] += sz[i];
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	// dbg(ans);
	// dbg(odd);
	ans += odd;
	cout << ans / 2 << '\n';
}