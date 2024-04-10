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
long long n, x[N], d[N], up[22][N], ggcd[22][N], ans, a, b;
vector <long long> v[N];

long long getd(long long node, long long g) {
	// dbg(node, g);
	for(long long i = 20; i >= 0; i--)
		if(__gcd(g, ggcd[i][node]) == g) {
			// dbg(i, node, ggcd[i][node]);
			node = up[i][node];
		}
	return node;
}


void dfs(long long node, long long ant = 0, long long dpt = 1) {

	d[node] = dpt;
	up[0][node] = ant;
	ggcd[0][node] = x[node];

	for(long long i = 1; i <= 20; i++) {
		up[i][node] = up[i - 1][up[i - 1][node]];
		ggcd[i][node] = __gcd(ggcd[i - 1][node], ggcd[i - 1][up[i - 1][node]]);
	}

	long long cnode = node;
	long long g = x[node];
	// dbg(up[0][node], up[1][node]);
	// dbg(ggcd[0][node], ggcd[1][node]);
	while(cnode >= 1) {
		long long nnode = getd(cnode, g);
		// dbg(cnode, nnode, g);
		ans += ((g % MOD) * (d[cnode] - d[nnode])) % MOD;
		ans %= MOD;
		g = __gcd(g, x[nnode]);
		cnode = nnode;
	}
	// dbg(node, ans);
	// dbg(ans);
	for(auto i : v[node])
		if(i != ant)
			dfs(i, node, dpt + 1);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(long long i = 1; i <= n; i++)
		cin >> x[i];

	for(long long i = 1; i< n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << ans % MOD << '\n';
}