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
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <long long> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 200100;
const long long MOD = 998244353;
long long n, k, m, a, b, p, dp[N][4];
vector <long long> v[N];

void dfs(long long node) {
	// dbg(node);
	if(v[node].size() > 0) dp[node][0] = 1;
	else dp[node][2] = 1;

	for(auto i : v[node]) {
		dfs(i);
		dp[node][2] = dp[node][2] * (dp[i][0] + dp[i][2]) % MOD +
									dp[node][2] * (dp[i][1] + dp[i][2]) % MOD +
									dp[node][1] * (dp[i][1] + dp[i][2]) % MOD;
		dp[node][2] %= MOD;
		dp[node][1] = dp[node][1] * (dp[i][0] + dp[i][2]) % MOD + 
							  	dp[node][0] * (dp[i][1] + dp[i][2]) % MOD;
		dp[node][1] %= MOD;
		dp[node][0] = dp[node][0] * (dp[i][0] + dp[i][2]) % MOD;
	}
	// dbg(node);
	// dbg(dp[node][0], dp[node][1], dp[node][2]);
}

int main() {
	ios_base::sync_with_stdio(false);


	cin >> n;

	for(long long i = 2; i <= n; i++) {
		cin >> p;
		v[p].push_back(i);
	}

	dfs(1);

	cout << (dp[1][0] + dp[1][2]) % MOD << '\n';

}