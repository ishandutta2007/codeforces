#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
long long s[200009][2];
int p[200009], l[200009], r[200009], c[200009];
int pl[200009], pr[200009], ds[200009], sz[200009];
bool rm[200009];
vector<int> v[200009];

int uf(int n)
{
	if (ds[n] == n) return n;
	return ds[n] = uf(ds[n]);
}

void up(int n)
{
	pr[n] = n + 1;
	if (rm[n - 1])
		ds[uf(n - 1)] = n;
	if (rm[n + 1]) {
		int ua = uf(n + 1);
		pr[n] = pr[ua];
		ds[ua] = n;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int pi = 0; pi < 2; pi++) {
			for (int i = 1; i <= n; i++) {
				int a; cin >> a;
				s[i][pi] = s[i - 1][pi] + a;
			}
		}
		int k = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1][0] == s[i - 1][1]) {
				k++;
				sz[k] = 0;
			}
			p[i] = k; sz[k]++;
		}
		for (int i = 0; i <= k + 1; i++) {
			v[i].clear();
			rm[i] = false;
			ds[i] = pl[i] = pr[i] = i;
		}
		for (int i = 0; i < m; i++) {
			c[i] = 0;
		}
		while (!q.empty()) q.pop();
		for (int i = 0; i < m; i++) {
			cin >> l[i] >> r[i];
			if (s[l[i] - 1][0] != s[l[i] - 1][1]) {
				c[i]++;
				v[p[l[i]]].push_back(i);
			}
			if (s[r[i]][0] != s[r[i]][1]) {
				c[i]++;
				v[p[r[i]]].push_back(i);
			}
			if (!c[i]) {
				q.push(i);
			}
			l[i] = p[l[i]]; r[i] = p[r[i]];
		}
		if (s[n][0] != s[n][1]) {
			cout << "NO" << '\n';
			continue;
		}
		while (!q.empty()) {
			int hn = q.front(); q.pop();
			int pn = l[hn];
			while (true) {
				pn = pr[uf(pn)];
				if (pn > r[hn]) break;
				rm[pn] = true;
				for (int i = 0; i < v[pn].size(); i++) {
					c[v[pn][i]]--;
					if (!c[v[pn][i]]) q.push(v[pn][i]);
				}
				up(pn);
			}
		}
		bool ff = true;
		for (int i = 1; i <= k; i++)
			if (!rm[i] && sz[i] > 1) {
				ff = false;
				break;
			}
		if (ff) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}