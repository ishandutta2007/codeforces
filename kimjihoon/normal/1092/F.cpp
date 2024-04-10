#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long 

ll a[200009], as = 0, ss[200009], rs = 0, ans = 0, r0, r1;
vector<int> v[200009];

void dfs0(int n, ll t, int p) {
	rs += a[n] * t;
	ss[n] = a[n];
	for (int i = 0; i < v[n].size(); i++)
		if (v[n][i] != p) {
			dfs0(v[n][i], t + 1, n);
			ss[n] += ss[v[n][i]];
		}
}

void dfs(int n, int p)
{
	ans = max(ans, rs);
	ll ts = rs;
	for (int i = 0; i < v[n].size(); i++) {
		if (v[n][i] == p) continue;
		rs -= ss[v[n][i]]; rs += as - ss[v[n][i]];
		dfs(v[n][i], n);
		rs = ts;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		as += a[i];
	}
	for (int i = 1; i < n; i++) {
		int p, q; cin >> p >> q;
		v[p].push_back(q); v[q].push_back(p);
	}
	dfs0(1, 0, -1); 
	dfs(1, -1);
	cout << ans << '\n';
	return 0;
}