#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

const int N = 100100;
const int MOD = 1e9 + 7;

int n, k, x, y, dp[N][2], cnt[N], c[N], p[N];
string s;

vector <int> v[N];

void dfs(int node) {
	
	dp[node][0] = 1;
	dp[node][1] = c[node];
	vector <int> x[2];
	int dl[v[node].size() + 4][2], dr[v[node].size() + 5][2];

	x[0].push_back(1);
	x[1].push_back(1);
	for(auto i : v[node]) {
		dfs(i);
		x[0].push_back(dp[i][0]);
		x[1].push_back(dp[i][1]);
	}
	x[0].push_back(1);
	x[1].push_back(1);

	for(auto j : {0, 1}) {
		dl[0][j] = 1;
		dr[v[node].size() + 1][j] = 1;

		for(int i = 1; i <= v[node].size(); i++) 
			dl[i][j] = (1LL * dl[i - 1][j] * x[j][i]) % MOD;
		for(int i = v[node].size(); i > 0; i--) 
			dr[i][j] = (1LL * dr[i + 1][j] * x[j][i]) % MOD;
	}


	for(int i = 0; i < v[node].size(); i++) {
		int e = v[node][i];
		if(c[node])
			dp[node][1] = (1LL * dp[node][1] * dp[e][0]) % MOD,
			dp[node][0] = (1LL * dp[node][0] * dp[e][0]) % MOD;
			// dp[node][0] += dp[e][1] * dl[i][0] * dr[i + 2][0];
		else
			dp[node][0] = (1LL * dp[node][0] * dp[e][0]) % MOD,
			dp[node][1] += ((1LL * (1LL * dp[e][1] * dl[i][0]) % MOD) * dr[i + 2][0]) % MOD,
			dp[node][1] %= MOD;
	}
	if(!c[node]) 
		dp[node][0] = (dp[node][0] + dp[node][1]) % MOD;

}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;

	for(int i = 2; i <= n; i++) {
		cin >> p[i];
		p[i]++;
		v[p[i]].push_back(i);
	}

	for(int i = 1; i <= n; i++)
		cin >> c[i];

	dfs(1);	
	
	cout << dp[1][1] << '\n';
}