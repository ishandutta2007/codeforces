#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 42000;
int p[maxn], M[maxn], loop[maxn];
vector<int> g[maxn];
int n, m, q;
vector<array<int, 2>> f(10);
char mat[maxn];
int id(int i, int j) {
	return i*m + j;
}
int best;
string s;
void dfs(int v, int pos) {
	if(pos != s.size()) pos += s[pos] == mat[v];
	best = max(best, pos);
	//cout << v << " " << pos << endl;
	for(auto i : g[v]) dfs(i, pos);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[id(i, j)];
	for(auto &i : f) cin >> i[0] >> i[1];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			int tx = i + f[mat[id(i, j)]-'0'][0];
			int ty = j + f[mat[id(i, j)]-'0'][1];
			if(min(tx, ty) < 0 || tx >= n || ty >= m) p[id(i, j)] = id(i, j);
			else p[id(i, j)] = id(tx, ty);
		}
	vector<int> vis(maxn);
	for(int t = 1, i = 0; i < n*m; i++, t++) if(!vis[i]) {
		vector<int> trace;
		int x = i;
		while(!vis[x]) {
			vis[x] = t;
			trace.push_back(x);
			x = p[x];
		}
		trace.push_back(x);
		if(vis[trace.back()] == t) {
			vector<int> cycle;
			do {
				loop[trace.back()] = 1;
				cycle.push_back(trace.back());
				trace.pop_back();
			} while(trace.back() != x);
			int msk = 0;
			for(auto i : cycle) msk |= 1<<(mat[i]-'0');
			for(auto i : cycle) M[i] = msk;
		}
	}
	//for(int i = 0; i < n*m; i++) cout << loop[i] << " ";cout << endl;
	//for(int i = 0; i < n*m; i++) cout << p[i] << " ";cout << endl;
	for(int i = 0; i < n*m; i++) if(!loop[i]) g[p[i]].push_back(i);
	while(q--) {
		cin >> s;
		reverse(all(s));
		vector<int> a(1<<10);
		int curmsk = 0;
		for(int i = 0; i <= s.size(); i++) {
			a[curmsk] = i;
			if(i != s.size()) curmsk |= 1<<(s[i]-'0');
		}
		for(int i = 1; i < 1<<10; i<<=1)
			for(int j = 0; j < 1<<10; j++)
				if(j&i) a[j] = max(a[j], a[i^j]);
		best = 0;
		for(int i = 0; i < n*m; i++) if(loop[i]) dfs(i, a[M[i]]);
		cout << (best == s.size() ? "YES\n" : "NO\n");
	}
}