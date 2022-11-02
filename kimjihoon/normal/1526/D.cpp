#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, ft[100009], a[100009], rc[256];
vector<int> v[4], p, pv, rv;
char rrc[4] = { 'A', 'T', 'O', 'N' };
long long mx = -1;
bool vs[4];

void up(int i)
{
	while (i <= n) {
		ft[i]++;
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

long long cc()
{
	for (int i = 0; i <= n; i++)
		ft[i] = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		up(p[i]);
		ans += i + 1 - sum(p[i]);
	}
	return ans;
}

void dfs(int pi)
{
	if (pi == 4) {
		p.clear();
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < v[pv[i]].size(); j++)
				p.push_back(v[pv[i]][j]);
		long long s = cc();
		if (mx < s) {
			mx = s; rv.clear();
			for (int i = 0; i < 4; i++)
				rv.push_back(pv[i]);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (vs[i]) continue;
		vs[i] = true; pv.push_back(i);
		dfs(pi + 1);
		vs[i] = false; pv.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	rc['A'] = 0; rc['T'] = 1; rc['O'] = 2; rc['N'] = 3;
	for (int ti = 0; ti < tc; ti++) {
		string s; cin >> s;
		n = s.length();
		for (int i = 0; i < 4; i++) {
			v[i].clear();
			vs[i] = false;
		}
		for (int i = 0; i < n; i++) 
			a[i + 1] = rc[s[i]];
		for (int i = 1; i <= n; i++) 
			v[a[i]].push_back(i);
		mx = -1; rv.clear(); pv.clear(); p.clear();
		dfs(0);
		for (int i = 0; i < rv.size(); i++)
			for (int j = 0; j < v[rv[i]].size(); j++)
				cout << rrc[rv[i]];
		cout << '\n';
	}
	return 0;
}