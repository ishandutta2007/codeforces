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

const long long N = 1010;
// const long long M = 2521;
const long long MOD = 2520;
// const long long MOD = 12;
const long long M = MOD + 10;
long long n, w[N][M], use[N][M], ans[N][M], m[N], k[N], take, q, a, b, res_ans;
vector <pair<long long, long long> > cache;
bitset<N> v;

void dfs(long long node, long long col) {
	col %= MOD;
	if(col < 0) col += MOD;
	// dbg(node, col);
	if(ans[node][col] != -1) {
		res_ans = ans[node][col];
		return;
	}

	
	if(use[node][col]) {
		v[node] = 1;
		use[node][col] = 0;
		return;
	}
	
	cache.push_back({node, col});
	use[node][col] = 1;

	long long nn = w[node][col % m[node]];
	dfs(nn, col + k[nn]);
	
	if(res_ans) return;

	if(use[node][col] == 0) {
		take = 0;
	} else if(take) {
		v[node] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> k[i];
		k[i] %= MOD;
	}

	for(long long i = 1; i <= n; i++) {
		cin >> m[i];
		for(long long j = 0; j < m[i]; j++)
			cin >> w[i][j];
	}

	memset(ans, -1, sizeof ans);

	for(long long i = 1; i <= n; i++)
		for(long long j = 0; j < MOD; j++) 
	// for(long long i = 4; i <= 4; i++)
	// 	for(long long j = 9; j < 11; j++) 
			if(ans[i][j] == -1) {
				// memset(use, 0, sizeof use);
				v.reset();
				cache.clear();
				take = 1;
				res_ans = 0;

				dfs(i, j);

				if(res_ans) ans[i][j] = res_ans;
				else ans[i][j] = v.count();
				// dbg(res_ans);
				// dbg(cache);
				for(auto ii : cache) {
					ans[ii.st][ii.nd] = ans[i][j];
					use[ii.st][ii.nd] = 0;
				}
			}

	cin >> q;

	for(long long i = 1; i <= q; i++) {
		cin >> a >> b;
		b += k[a];
		b %= MOD;
		if(b < 0) b += MOD;
		// dbg(a, b);
		cout << ans[a][b] << '\n';
		// for(long long i = 1; i <= n; i++)
		// if(v[a])
	}

}