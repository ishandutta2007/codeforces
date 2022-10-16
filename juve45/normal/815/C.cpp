#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <long long> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const long long N = 100100;
const long long INF = 0x3f3f3f3f;

long long n, k, m, b, sz[N], d[N], c[N], a;
vector <long long> v[N], dp[N], cst[N];

void dfs(long long node) {

	sz[node] = 1;

	long long szmax = 0, ind = -1;

	for(auto i : v[node]) {
		dfs(i);
		sz[node] += sz[i];
		if(sz[i] > szmax) 
			szmax = sz[i], ind = i;
	}

	dp[node].resize(sz[node] + 2, INF);
	cst[node].resize(sz[node] + 2, INF);
	dp[node][0] = 0;
	cst[node][0] = 0;

	cst[node][1] = c[node];
	dp[node][1] = c[node] - d[node];

	if(ind == -1) return;

	for(long long i = 0; i <= sz[ind]; i++) {
		cst[node][i + 1] = min(cst[ind][i + 1], cst[ind][i] + c[node]);
		dp[node][i + 1] = dp[ind][i] + c[node] - d[node];
	}

	// dbg(node);
	// dbg(ind);
	// dbg(dp[ind]);
	// dbg(dp[node]);

	for(auto i : v[node]) {
		if(i == ind) continue;
		for(long long j = sz[node]; j >= 0; j--) {
			for(long long k = 0; k <= min(sz[i], j); k++) {
				if(j > k)
					dp[node][j] = min(dp[node][j], dp[node][j - k] + dp[i][k]);
				else if(k > 0)
					dp[node][j] = min(dp[node][j], dp[i][k - 1] + c[node] - d[node]);
				cst[node][j] = min(cst[node][j], cst[node][j - k] + cst[i][k]);
			}

			// if(dp[node][j + 1] == INF) break;
		}
	}

	for(long long i = 0; i <= sz[node]; i++) 
		dp[node][i] = min(dp[node][i], cst[node][i]);
	// dbg(dp[node]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> b;

	cin >> c[1] >> d[1];

	for(long long i = 2; i <= n; i++) {
		cin >> c[i] >> d[i] >> a;
		v[a].push_back(i);
	}

	dfs(1);
	/*
	dbg_v(sz, n + 1);
	dbg(v[6]);
	dbg(v[9]);
	dbg(v[11]);*/

	long long ans = 0;
	dbg(sz[1]);
	while(ans < sz[1] && dp[1][ans + 1] <= b) ans++;
	cout << ans << '\n';
}