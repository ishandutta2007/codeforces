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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, cnt, use[N], m, sz[N], p[N], a, b, ok;

vector <int> ans, v[N], g[N];

void dfsc(int node) {
	use[node] = 1;
	sz[node] = p[node];
	if(p[node]) ok = 1;

	for(auto i : v[node])
		if(!use[i]) {
			g[node].push_back(i);
			dfsc(i);
			sz[node] += sz[i];
		}
}

void dfs(int node, int par = -1) {
	// dbg(node);
	p[node] ^= 1;

	ans.push_back(node);
	
	for(auto i : g[node]) 
		if(sz[node]) {
			p[node] ^= 1;
			dfs(i, node);
			ans.push_back(node);
		}
	
	if(p[node] && par != -1) {
		ans.push_back(par);
		p[par] ^= 1;
		ans.push_back(node);
		p[node] ^= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
		cin >> p[i];

	int cand = 0;
	for(int i = 1; i <= n; i++) 
		if(!use[i]) {
			ok = 0;
			dfsc(i);
			if(ok && cand) return cout << "-1\n", 0;
			else if(ok) cand = i;
		}

	// dbg(cand);
	// dbg(g[cand]);
	dfs(cand);
	// dbg(ans);	
	if(p[cand])
		ans.pop_back();
	cout << ans << '\n';
}