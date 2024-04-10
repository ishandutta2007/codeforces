#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int c[100009], g = 0;
vector<int> v[100009];
long long ans[100009], md = 998244353;

void dfs(int n, int p, int t)
{
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p) continue;
		dfs(tn, n, t);
	}
	if (c[n] % t == 0)
		c[p]++;
	else
		c[n]++;
	g = gcd(g, c[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			ans[i] = 0;
		}
		ans[1] = 1;
		for (int i = 0; i < n - 1; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
			ans[1] = (ans[1] * 2) % md;
		}
		for (int i = 2; i <= n; i++) {
			if ((n - 1) % i != 0)
				continue;
			for (int j = 0; j <= n; j++)
				c[j] = 0;
			g = 0;
			dfs(1, 0, i);
			if (c[0] && g == i) {
				ans[i] = 1;
				ans[1] = (ans[1] + md - 1) % md;
			}
		}
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}