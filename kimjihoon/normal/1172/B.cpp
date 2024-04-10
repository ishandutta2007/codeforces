#include <iostream>
#include <vector>
using namespace std;

long long d[200009], f[200009], c[200009], md = 998244353;
vector<int> v[200009];

void dfs(int n, int p)
{
	if (v[n].size() == 1) {
		d[n] = 1; c[n] = 1;
		return;
	}
	long long s = 1; c[n] = 1;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		dfs(tn, n);
		s = (s * d[tn]) % md;
		c[n] += c[tn];
	}
	if (n == 1)
		d[n] = (((s * f[v[n].size() - 1]) % md) * c[n]) % md;
	else
		d[n] = (s * f[v[n].size()]) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = (f[i - 1] * (long long)i) % md;
	v[1].push_back(0);
	dfs(1, 0);
	cout << d[1] << '\n';
	return 0;
}