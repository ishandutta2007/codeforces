#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t[300009], p[300009], mn[300009], mx[300009], lc = 0;
vector<int> v[300009];

void dfs(int n)
{
	if (v[n].size() == 0) {
		mn[n] = 1; mx[n] = lc;
		return;
	}
	if (t[n] == 0) { mn[n] = lc, mx[n] = lc + 1; }
	else { mn[n] = 0, mx[n] = 1; }
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		dfs(tn);
		if (t[n] == 0) {
			mn[n] = min(mn[n], mn[tn]);
			mx[n] -= lc - mx[tn] + 1;
		}
		else {
			mn[n] += mn[tn];
			mx[n] = max(mx[n], mx[tn]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		v[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (v[i].size() == 0)
			lc++;
	dfs(1);
	cout << mx[1] << '\n';
	return 0;
}