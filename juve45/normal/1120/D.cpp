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

const long long N = 300100;
long long n, use[N], ok[N], min_diff, c[N], cost, a, b, md[N], cnt, dp[N][2], gg[N];

vector <long long> v[N], ans;
set <pair<long long, long long> > s;

void dfs(long long node, long long ant = -1) {
	// dbg(node);
	long long sum = 0;

	if(v[node].size() == 1 && node != 1) {
		dp[node][0] = c[node];
		dp[node][1] = 0;
		return;
	}

	for(auto i : v[node])
		if(i != ant)
			dfs(i, node), sum += dp[i][0];

	dp[node][0] = sum;
	dp[node][1] = 0x3f3f3f3f3f3f3f3f;
	for(auto i : v[node])
		if(i != ant) {
			dp[node][0] = min(dp[node][0], sum - dp[i][0] + dp[i][1] + c[node]);
			dp[node][1] = min(dp[node][1], sum - dp[i][0] + dp[i][1]);
		}
}

void check(long long node, long long ant, long long zero, long long one) {
	// dbg(node, zero, one, dp[node][0], dp[node][1]);
	// ok[node] = 1;
	long long sum = 0;
	for(auto i : v[node]) 
		if(i != ant)
			sum += dp[i][0];

	if(v[node].size() == 1 && node != 1) {
		if(zero) ok[node] = 1;
		return;
	}

	long long cnt = 0, bad = -1;
	for(auto i : v[node]) {
		if(i == ant) continue;
		int add = 0;
		if(zero && dp[node][0] == sum - dp[i][0] + dp[i][1] + c[node]) add = 1, ok[node] = 1, gg[i] = 1, bad = i;
		if(one && dp[node][1] == sum - dp[i][0] + dp[i][1]) add = 1, gg[i] = 1, bad = i;
		cnt += add;
	}
	// dbg(node, zero, one, cnt, bad, sum);
	if(zero && sum == dp[node][0]) 
		cnt = 2;
	long long need = 0;
	for(auto i : v[node]) {
		if(i == ant) continue;
		check(i, node, (cnt >= 2 || bad != i), gg[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++)
		cin >> c[i];

	// dbg_ok;
	for(long long i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// for(long long i = 2; i <= n; i++)
	// 	if(v[i].size() == 1)
	// 		cost += c[i], ok[i] = 1;

	// dbg_ok;
	dfs(1);

	cout << dp[1][0] << ' ';
	cout.flush();
	check(1, -1, 1, 0);
	// dbg(cnt);
	// dbg(min_diff);
	// s.clear();

	// dfs(1, 0, -1);
	for(long long i = 1; i <= n; i++) 
		if(ok[i])
			ans.push_back(i);
		cout << ans << '\n';
	// cout << cost + min_diff << ' ' << ans << '\n';
}