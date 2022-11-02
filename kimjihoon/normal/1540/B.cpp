#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dt[209], p[209][9];
vector<int> v[209];
long long ft[209], rt[209], t2[209], pp[209][209][2], md = 1000000007;

long long fp(long long n, long long k)
{
	long long ans = 1;
	while (k) {
		if (k & 1) ans = (ans * n) % md;
		k /= 2; n = (n * n) % md;
	}
	return ans;
}

void dfs(int n, int pr)
{
	p[n][0] = pr;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == pr) continue;
		dt[tn] = dt[n] + 1;
		dfs(tn, n);
	}
}

int lca(int a, int b)
{
	if (dt[a] > dt[b]) swap(a, b);
	int df = dt[b] - dt[a];
	for (int i = 8; i >= 0; i--)
		if (df >= (1 << i)) {
			df -= (1 << i);
			b = p[b][i];
		}
	if (a == b) return a;
	for (int i = 8; i >= 0; i--)
		if (p[a][i] != p[b][i]) {
			a = p[a][i]; b = p[b][i];
		}
	return p[a][0];
}

long long cb(long long n, long long k)
{
	return (((ft[n] * rt[k]) % md) * rt[n - k]) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	ft[0] = rt[0] = 1;
	for (int i = 1; i <= n; i++)
		ft[i] = (ft[i - 1] * i) % md;
	rt[n] = fp(ft[n], md - 2);
	for (int i = n - 1; i >= 1; i--)
		rt[i] = (rt[i + 1] * (i + 1)) % md;
	t2[0] = 1;
	for (int i = 1; i <= n; i++)
		t2[i] = (t2[i - 1] * 2) % md;
	for (int i = 1; i <= n; i++)
		for (int j = 1; i + j <= n; j++) {
			pp[i][j][1] = t2[i + j];
			pp[i][j][0] = cb(i + j - 1, i);
			for (int k = i + 1; k <= min(n, i + j); k++)
				pp[i][j][0] = (pp[i][j][0] + cb(i + j, k)) % md;
		}
	long long ansp = 0, ansq = 1;
	for (int rt = 1; rt <= n; rt++) {
		dfs(rt, 0);
		for (int l = 0; l < 8; l++)
			for (int i = 1; i <= n; i++)
				p[i][l + 1] = p[p[i][l]][l];
		long long ap = 0, aq = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++) {
				int t = lca(i, j);
				if (t == j) continue;
				if (t == i) ap = (ap + aq) % md;
				else {
					long long rd = pp[dt[i] - dt[t]][dt[j] - dt[t]][0], m = pp[dt[i] - dt[t]][dt[j] - dt[t]][1];
					ap = (ap * m + rd * aq) % md; aq = (aq * m) % md;
				}
			}
		aq = (aq * n) % md;
		ansp = (ansp * aq + ap * ansq) % md; ansq = (ansq * aq) % md;
	}
	cout << (ansp * fp(ansq, md - 2)) % md << '\n';
	return 0;
}