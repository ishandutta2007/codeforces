#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 1000009;
vector<int> v[N];
vector<vector<int> > g;
stack<int> st;
int d[N], c, rc;
bool gn[N], vs[N];

int scc(int n)
{
	c++; d[n] = c;
	st.push(n);
	int r = c;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (!d[tn]) r = min(r, scc(tn));
		else if (!gn[tn]) r = min(r, d[tn]);
	}
	if (d[n] == r) {
		g.push_back(vector<int>());
		while (true) {
			int pn = st.top(); st.pop();
			g.back().push_back(pn);
			gn[pn] = true;
			if (pn == n) break;
		}
	}
	return r;
}

void dfs(int n)
{
	vs[n] = true; rc++;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (!vs[tn])
			dfs(tn);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			v[i].clear(); d[i] = 0;
			vs[i] = false; gn[i] = false;
		}
		g.clear();
		c = 0;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			if (a != b) v[a].push_back(b);
		}
		for (int i = 1; i <= n; i++)
			if (!d[i])
				scc(i);
		if (g.size() <= 1) {
			cout << "No" << '\n';
			continue;
		}
		cout << "Yes" << '\n';
		rc = 0;
		dfs(g[0].back());
		if (rc == n) {
			for (int i = 1; i <= n; i++)
				vs[i] = false;
			dfs(g[1].back());
		}
		cout << rc << " " << n - rc << '\n';
		for (int i = 1; i <= n; i++)
			if (vs[i])
				cout << i << " ";
		cout << '\n';
		for (int i = 1; i <= n; i++)
			if (!vs[i])
				cout << i << " ";
		cout << '\n';
	}
	return 0;
}