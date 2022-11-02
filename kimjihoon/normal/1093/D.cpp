#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int vs[300009];
ll ep[300009], r[2];
vector<int> v[300009];
bool f;

void dfs(int n, int t)
{
	vs[n] = t; r[t]++;
	for (int i = 0; i < v[n].size(); i++) {
		if (vs[v[n][i]] != -1) {
			if (vs[v[n][i]] == t)
				f = false;
			continue;
		}
		dfs(v[n][i], (t + 1) % 2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	ep[0] = 1;
	for (int i = 1; i <= 300000; i++)
		ep[i] = (ep[i - 1] * 2) % 998244353;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			vs[i] = -1; v[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b; a--; b--;
			v[a].push_back(b); v[b].push_back(a);
		}
		ll ans = 1; f = true;
		for (int i = 0; i < n; i++) {
			if (vs[i] != -1) continue;
			r[0] = r[1] = 0;
			dfs(i, 0);
			if (!f) {
				cout << 0 << '\n';
				break;
			}
			ans = (ans * (ep[r[0]] + ep[r[1]])) % 998244353;
		}
		if (f)
			cout << ans << '\n';
	}
	return 0;
}