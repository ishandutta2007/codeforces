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
long long n, a, b, c, dp[N][4], ans;
vector <pair<long long, long long>> v[N];

void dfs(long long node, long long ant = -1) {
	// dbg(node);
	for(auto i : v[node])
		if(i.st != ant) {
			dfs(i.st, node);
			if(i.nd == 0) {
				dp[i.st][0]++;
				ans += dp[node][0] * (dp[i.st][0] + dp[i.st][2] + dp[i.st][1]);
				ans += dp[i.st][0] * (dp[node][0] + dp[node][2] + dp[node][1]);
				dp[node][0] += dp[i.st][0];
				dp[node][2] += dp[i.st][2] + dp[i.st][1];
			} else {
				dp[i.st][1]++;
				ans += (dp[node][0] + dp[node][1] + dp[node][3]) * dp[i.st][1];
				ans += (dp[i.st][3] + dp[i.st][0] + dp[i.st][1]) * dp[node][1];
				dp[node][1] += dp[i.st][1];
				dp[node][3] += dp[i.st][3] + dp[i.st][0];
			}
		}
	ans += 2 * (dp[node][0] + dp[node][1]) + dp[node][2] + dp[node][3];
	// dbg(node, dp[node][0], dp[node][1], dp[node][2], dp[node][3], ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	dfs(1);
	cout << ans << '\n';
}