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

const long long N = 2010;
const long long MOD = 1e9 + 7;
long long n, d, x, y, a[N], dp[N], ans;
vector <long long> v[N], g[N];

void dfs_ans(long long node, long long ant = -1) {
	// dbg(node);
	dp[node] = 1;
	for(auto i : v[node]) {
		if(i == ant) continue;
		dfs_ans(i, node);
		dp[node] *= (dp[i] + 1);
		dp[node] %= MOD;
	}
}

void dfs(long long node, long long st, long long ant = -1) {
	// dbg(node);
	for(auto i : g[node]) {
		if(i == ant || a[i] > d + a[st] || a[i] < a[st] || a[i] == a[st] && i < st) 
			continue;
		v[node].push_back(i);
		v[i].push_back(node);
		dfs(i, st, node);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> d >> n;

	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for(long long i = 1; i < n; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	for(long long i = 1; i <= n; i++) {
		memset(dp, 0, sizeof dp);
		for(long long j = 1; j <= n; j++)
			v[j].clear();

		dfs(i, i);
		dfs_ans(i);

		ans += dp[i];
		ans %= MOD;
		// dbg_v(dp, n + 1);
		// dbg(i, ans);
	}
	cout << ans << '\n';

}