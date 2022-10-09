#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct grana {
	int y, i;
};

struct izbore {
	vector<int> eid;
	int i;

	bool operator< (const izbore& other) const {
		return eid.size() > other.eid.size();
	}
};

int n, m, k;
vector<grana> e[200005];
bool izbor[200005];
int d[200005];
vector<string> sol;

izbore v[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back({v, i});
		e[v].push_back({u, i});
	}

	{
		queue<int> q;
		q.push(1);
		fill(d+1, d+n+1, -1);
		d[1] = 0;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (grana g : e[x]) {
				if (d[g.y] == -1) {
					d[g.y] = d[x] + 1;
					q.push(g.y);
				}
			}
		}
	}

	for (int i=2; i<=n; i++) {
		for (grana g : e[i]) {
			if (d[g.y] == d[i] - 1) {
				v[i].eid.push_back(g.i);
			}
		}
	}

	for (int potez=0; potez<k; potez++) {
		// stampaj
		string s(m, '0');
		for (int i=2; i<=n; i++)
			s[v[i].eid[v[i].i] - 1] = '1';
		sol.push_back(s);

		// inkrementiraj ako moze
		int pos = 2;
		while (pos <= n && v[pos].i == (int)v[pos].eid.size()-1)
			pos++;

		if (pos == n+1)
			break;

		v[pos].i++;
		for (int t=2; t<pos; t++)
			v[t].i = 0;
	}

	cout << sol.size() << '\n';
	for (string s : sol)
		cout << s << '\n';

}