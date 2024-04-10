#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 100100;
long long n, k, in[N], use[N], lvl[N], d[N], m, a, b, c, q, mp[N], dmin[N][44], pre[44][44];
vector <pair<long long, long long> > v[N], g[N];
vector <long long> st, up[N];
vector <pair<long long, pair<long long,long long> > > edges;
set<long long> nodes;

int ok = 0;
template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

long long lca(long long a, long long b) {
	int ok2 = 0;
	if(ok && a > 4811 && a <= 4812) cout << a << ' ' << b << ' ' << lvl[a] << ' ' << lvl[b] << endl, ok2 = 1;
	if(lvl[a] > lvl[b])
		swap(a, b);

	if(lvl[a] != lvl[b])
		for(int last = (long long) up[b].size() - 1; last >= 0; last--)
			if(lvl[b] - (1 << last) >= lvl[a])
				b = up[b][last];

	if(ok2) cout << "okkk " << a << ' ' << b << ' ' << lvl[a] << ' ' << lvl[b] << endl;

	if(a == b)
		return a;

	for(int last = (long long) up[a].size() - 1;last >= 0;last--)
		if(up[a].size() > last && up[a][last] != up[b][last]) {
			a = up[a][last], b = up[b][last];
		}
	return up[a][0];
}

long long dist_arb(long long a, long long b) {
	return d[a] + d[b] - 2 * d[lca(a, b)];
}

void dfs(long long node, long long level) {

	in[node] = 1;
	use[node] = 1;
	lvl[node] = level;

	for(long long i = 0; (1 << i) <= st.size(); i++)
		up[node].push_back(st[st.size() - (1 << i)]);

	st.push_back(node);

	for(auto p : v[node]) {
		if(in[p.st] && lvl[p.st] < lvl[node] - 1) {
			edges.push_back({p.nd, {node, p.st}});
			nodes.insert(p.st);
			nodes.insert(node);
		} else if(!use[p.st]) {
			d[p.st] = d[node] + p.nd;
			dfs(p.st, level + 1);
			// g[node].push_back(p);
		}
	}

	in[node] = 0;
	st.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(long long i = 1; i <= m; i++) {
		cin >> a >> b>> c;
		// if(a == 1 && b == 5721) ok = 1;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	d[1] = 0;
	dfs(1, 1);

	if(ok) cout << "OK" << endl;

	long long nr = 0;
	for(auto i : nodes) 
		mp[i] = ++nr;

	for(long long i = 1; i <= n; i++) {
		for(auto j : nodes)
			dmin[i][mp[j]] = dist_arb(i, j);
	}

	if(ok) cout << "OK" << endl;

	for(auto i : nodes)
		for(auto j : nodes)
			pre[mp[i]][mp[j]] = dist_arb(i, j);

	for(auto p : edges)
		pre[mp[p.nd.st]][mp[p.nd.nd]] = pre[mp[p.nd.nd]][mp[p.nd.st]] = min(pre[mp[p.nd.st]][mp[p.nd.nd]], p.st);

	for(long long i = 1; i <= nr; i++)
		for(long long j = 1; j <= nr; j++)
			for(long long k = 1; k <= nr; k++)
				if(pre[j][k] > pre[j][i] + pre[i][k])
					pre[j][k] = pre[j][i] + pre[i][k];

	cin >> q;
	for(long long ii = 1; ii <= q; ii++) {
		cin >> a >> b;
		long long ans = dist_arb(a, b);
		for(long long i = 1; i <= nr; i++)
			for(long long j = 1; j <= nr; j++)
				ans = min(ans, pre[i][j] + dmin[a][i] + dmin[b][j]);
		cout << ans << '\n';
	}
}