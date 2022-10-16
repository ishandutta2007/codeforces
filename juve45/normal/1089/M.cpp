#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(x) cerr<<#x": "<<(x)<<endl
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define INF 2000000010
#define MOD 1000000007
#define ST_SIZE 1048600
#define QMAX 
#define NMAX 12

template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}

template<typename T>
ostream& operator <<(ostream &out, const vector<T> &v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

int comp[NMAX];
bool vis[NMAX], used[NMAX][NMAX];
vector<int> ord, nodes[NMAX];
vector<int> adj[NMAX], adjt[NMAX];
char ans[3 * 9 + 5][5][81 * 3 + 5];

void dfs(int v) {
	vis[v] = true;
	
	for(auto u : adj[v]) if(!vis[u]) dfs(u);
	ord.push_back(v);
}

void dfst(int v, int nrcomp) {
	vis[v] = false;
	comp[v] = nrcomp;
	nodes[nrcomp].push_back(v);
	
	for(auto u : adjt[v]) if(vis[u]) dfst(u, nrcomp);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int i, j, k, n, m, x, y, z, nrc, p;
	
	cin >> n;
	for(m = 0, i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j) {
			cin >> x;
			if(x) {
				++m;
				// dbg(i);
				// dbg(j);
				adj[i].push_back(j);
				adjt[j].push_back(i);
			}
		}
	
	for(i = 1; i <= n; ++i) if(!vis[i]) dfs(i);
	reverse(all(ord));
	
	nrc = 0;
	for(auto v : ord) if(vis[v]) dfst(v, ++nrc);
	
	x = max(n, m * 3);
	y = 4;
	z = 2 * nrc;
	
	memset(ans, '.', sizeof ans);
	
	for(i = 2; i <= z; i += 2)
		for(j = 1; j <= y; ++j)
			for(k = 1; k <= x; ++k) ans[i][j][k] = '#';
	
	for(i = 1; i <= nrc; ++i)
		for(j = 0; j < nodes[i].size(); ++j) ans[2 * i - 1][1][j + 1] = '0' + nodes[i][j];
	
	// dbg_v(comp + 1, n);
	// dbg(adj[2]);
	
	p = 2;
	for(int ii = 1; ii <= n; ++ii)
		for(auto j : adj[ii]) {
			int v = comp[ii];
			int u = comp[j];
			if(v == u || used[v][u]) continue;
			used[v][u] = true;
			
			ans[2 * v][3][p] = '.';
			for(i = v + 1; i < u; ++i) {
				ans[2 * i][3][p] = '.';
				for(j = 2; j <= 4; ++j)
					for(k = p - 1; k <= p + 1; ++k)
						if(j != 3 || k != p) {
							ans[2 * i - 1][j][k] = '#';
						}
			}
			
			p += 3;
		}
	
	cout << x << ' ' << y << ' ' << z << '\n';
	for(i = 1; i <= z; ++i, cout << '\n')
		for(j = 1; j <= y; ++j, cout << '\n')
			for(k = 1; k <= x; ++k) cout << ans[i][j][k];
	
	return 0;
}