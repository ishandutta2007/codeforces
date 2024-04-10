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
const long long MOD = 1e9 + 7;
long long n, ans, a, b;
long long dp[N];
vector <long long> v[N];


long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

long long invMod(long long a) {
	return powMod(a, MOD - 2);
}

void dfs(long long node, long long ant = -1) {

	dp[node] = 1;

	for(auto i : v[node]) {
		if(i == ant) continue;
		dfs(i, node);

		dp[node] *= dp[i] % MOD;
		dp[node] %= MOD;
	}

	if(ant == -1 || v[node].size() != 1)
		dp[node] *= 2;

	// dbg(node, dp[node]);
}


void dfs_ans(long long node, long long ant = -1, long long dp_up = 1) {

	if(ant == -1)
		ans += dp[node];
	else {
		ans += dp_up * dp[node] % MOD;
		if(v[node].size() == 1)
			ans += dp_up * dp[node] % MOD;
	}
	ans %= MOD;
	// dbg(node, ans, dp_up, dp[node]);

	for(auto i : v[node]) {
		if(i == ant) continue;

		long long i0 = invMod(dp[i]);
		long long dd0 = dp_up * (dp[node] * i0 % MOD) % MOD;
		if(ant ==  -1 && v[node].size() == 1)
			dd0 *= invMod(2), dd0 %= MOD;
	
		dfs_ans(i, node, dd0);
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
	dbg_ok;

	dfs_ans(1);

	cout << ans % MOD << '\n';
}