#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << '['; for(auto e : v) out << e << ' '; return out << ']';}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <ynt> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const int N = 1010;
const int ONE = 4011;
const int ZERO = 4010;
const int MOD = 998244353;

int n, k, m, a, b, use[4 * N], pw2[4 * N];
vector <int> v[4 * N];
// 0 si ONE sunt nodurile fixate.
string s;

void add_egde(int a, int b) {
	v[a].push_back(b);
	v[b].push_back(a);
}

bool bip(int node, int col) {
	use[node] = col;
	for(auto i : v[node])
		if(!use[i]) {
			if(!bip(i, 3 - col))
				return 0;
		}
		else if(use[i] == col){
			dbg(i);
			dbg(node);
			return 0;
		}
	return 1;
}

bool isBipartite() {
	memset(use, 0, sizeof use);
	if(!bip(ZERO, 1)) {
		dbg_v(use, 22);
		return 0;
	}
	for(int i = 0; i < n; i++)
		if(!use[i] && !bip(i, 1))
			return 0;
		else if(!use[2 * n + i] && !bip(2 * n + i, 1))
			return 0;
	memset(use, 0, sizeof use);
	return 1;
}

int dfs(int node) {
	use[node] = 1;
	int ret = 1;
	for(auto i : v[node])
		if(!use[i])
			ret += dfs(i);
	return ret;
}

void gen_graph() {
	for(int i = 0;i < 4 * N; i++) 
		v[i].clear();

	add_egde(ONE, ZERO);

	add_egde(ZERO, 0);
	add_egde(ONE, n);

	for(int i = 0; i < n; i++) {
		add_egde(i, i + n);
		add_egde(2 * n + i, 3 * n + i);

		if(s[i] == '1')
			add_egde(i, 2 * n + i),
			add_egde(i + n, 3 * n + i);
		else if(s[i] == '0')
			add_egde(i, 3 * n + i),
			add_egde(i + n, 2 * n + i);
	}
}

int solve(int k) {
	gen_graph();

	int ceva = n - k;

	for(int i = 0; i < ceva; i++) {
		add_egde(ONE, 2 * n + i);
		add_egde(ZERO, 3 * n + i);
	}

	add_egde(ZERO, 2 * n + ceva);
	add_egde(ONE, 3 * n + ceva);

	// adauga nodurile de palindrom
	for(int i = 0; i < k; i++) 
		if(i != k - i - 1)
			add_egde(2 * n + ceva + i, 3 * n + ceva + k - i - 1);
	
		// de la i la k - i - 1
	for(int i = 0; i < n; i++) 
		if(i != n - i - 1)
			add_egde(i, n + n - i - 1);

	// dbg(v[ONE]);
	// dbg(v[ZERO]);
	// dbg(v[0]);
	// dbg(v[1]);
	// dbg(v[2]);
	// dbg(v[3]);
	// dbg(v[4]);
	// dbg(v[8]);
	// dbg(v[18]);
	// dbg(v[17]);

	if(!isBipartite()) return 0;
	dfs(ZERO);
	long long ans = 1, nrc = 0;
	for(int i = 0; i < n; i++) {
		if(!use[i])
			nrc++, dfs(i);
			// ans = (1LL * ans * pw2[dfs(i) / 2]) % MOD;
		if(!use[2 * n + i])
			nrc++, dfs(2 * n + i);
			// ans = (1LL * ans * pw2[dfs(2 * n + i) / 2]) % MOD;
	}
	ans = ans * pw2[nrc];
	ans %= MOD;
	// dbg(k, ans);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	pw2[0] = 1;
	for(int i = 1; i < 2 * N; i++)
		pw2[i] = (2LL * pw2[i - 1]) % MOD;

	cin >> s;
	n = s.size();
	long long ans = 0;
	for(int k = n - 1; k > 0; k--)
		ans = (ans + solve(k)) % MOD;
	cout << ans << '\n';
}