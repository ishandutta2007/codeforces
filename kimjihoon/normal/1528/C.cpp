#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[300009], pv[300009];
int n, ft[300009], sz[300009], cc[300009], ep[300009][20], ans = 0, s = 0, c = 0;
bool f[300009], lf[300009];

void up(int i, int w)
{
	while (i <= n) {
		ft[i] += w;
		i += (i & (-i));
	}
}

int sum(int i)
{
	int s = 0;
	while (i) {
		s += ft[i];
		i -= (i & (-i));
	}
	return s;
}

int ssum(int n)
{
	return sum(cc[n] + sz[n] - 1) - sum(cc[n] - 1);
}

int fp(int n)
{
	for (int i = 19; i >= 0; i--)
		if (ep[n][i] && !ssum(ep[n][i]))
			n = ep[n][i];
	n = ep[n][0];
	if (f[n]) return n;
	return 0;
}

void dfs0(int n)
{
	sz[n] = 1;
	c++; cc[n] = c;
	for (int i = 0; i < pv[n].size(); i++) {
		int tn = pv[n][i];
		dfs0(tn);
		sz[n] += sz[tn];
	}
}


void dfs(int n)
{
	int p = fp(n);
	if (p) {
		f[p] = false;
		up(cc[p], -1);
		s--;
	}
	if (!ssum(n)) {
		f[n] = true;
		up(cc[n], 1);
		s++;
	}
	ans = max(ans, s);
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		dfs(tn);
	}
	if (p) {
		f[p] = true;
		up(cc[p], 1);
		s++;
	}
	if (f[n]) {
		f[n] = false;
		up(cc[n], -1);
		s--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			pv[i].clear();
		}
		for (int i = 2; i <= n; i++) {
			int pr; cin >> pr;
			v[pr].push_back(i);
		}
		ep[1][0] = 0;
		for (int i = 2; i <= n; i++) {
			int pr; cin >> pr;
			pv[pr].push_back(i);
			ep[i][0] = pr;
		}
		for (int l = 0; l < 19; l++)
			for (int i = 1; i <= n; i++)
				ep[i][l + 1] = ep[ep[i][l]][l];
		s = 0; ans = 0; c = 0;
		dfs0(1); dfs(1);
		cout << ans << '\n';
	}
	return 0;
}