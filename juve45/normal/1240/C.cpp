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

const long long N = 500100;
long long n, dp[N][2], k, a, b, c, q;
vector <pair<long long, long long>> v[N];

void dfs(long long node, long long ant = -1) {
	// dbg(node);
	dp[node][0] = dp[node][1] = 0;
	long long off = 0;
	vector <long long> dif;
	for(auto i : v[node]) {
		if(i.st == ant) continue;
		dfs(i.st, node);
		off += dp[i.st][0];
		dif.push_back(dp[i.st][1] - dp[i.st][0] + i.nd);
	}
	// dbg(node);	

	sort(dif.begin(), dif.end(), greater<long long>());

	dp[node][0] += off;
	dp[node][1] += off;
	for(long long i = 0; i < min(k - 1, (long long) dif.size()); i++) {
		dp[node][0] += max(dif[i], 0LL);
		dp[node][1] += max(dif[i], 0LL);
	}
	// dbg(node);
	if(k <= dif.size())
		dp[node][0] += max(dif[k - 1], 0LL);
}

void solve() {

	cin >> n >> k;
	for(long long i = 1; i<= n; i++) v[i].clear();

	for(long long i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	dfs(1);

	cout << dp[1][0] << '\n';
}



int main() {
	ios_base::sync_with_stdio(false);

	cin >> q;

	while(q--) solve();
}