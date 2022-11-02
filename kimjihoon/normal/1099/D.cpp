#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100009];
int p[100009];
long long s[100009], a[100009], ans = 0;
bool f = true;

void dfs(int n)
{
	if (s[n] != -1) {
		if (n == 1) a[n] = s[n];
		else a[n] = s[n] - s[p[n]];
		ans += a[n];
		for (int i = 0; i < v[n].size(); i++) {
			dfs(v[n][i]);
			if (!f)
				return;
		}
		return;
	}
	if (v[n].size() == 0) {
		a[n] = 0;
		return;
	}
	long long mn = s[v[n][0]];
	for (int i = 1; i < v[n].size(); i++)
		mn = min(mn, s[v[n][i]]);
	long long t = mn - s[p[n]];
	if (t < 0) {
		f = false;
		return;
	}
	a[n] = t; s[n] = s[p[n]] + a[n];
	ans += a[n];
	for (int i = 0; i < v[n].size(); i++) {
		dfs(v[n][i]);
		if (!f)
			return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		v[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	dfs(1);
	if (!f) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}