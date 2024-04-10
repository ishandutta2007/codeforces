#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sz;
bool r[1009];
vector<int> v[1009];

void dfs(int n, int p)
{
	if (r[n]) return;
	r[n] = true; sz--;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		if (tn == p || r[tn]) continue;
		dfs(tn, n);
	}
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
	sz = n;
	while (sz > 2) {
		int p[3];
		for (int i = 1; i <= n; i++) {
			if (!r[i] && v[i].size() >= 2) {
				p[1] = i;
				p[0] = v[i][0]; p[2] = v[i][1];
				break;
			}
		}
		cout << "? " << p[0] << " " << p[2] << endl;
		int t; cin >> t;
		vector<int> tv;
		for (int i = 0; i < v[t].size(); i++) {
			int tn = v[t][i];
			if (tn == p[0] || tn == p[1] || tn == p[2]) continue;
			tv.push_back(v[t][i]);
		}
		v[t] = tv;
		r[t] = true;
		for (int i = 0; i < 3; i++) {
			if (t == p[i]) continue;
			dfs(p[i], -1);
		}
		r[t] = false;
	}
	if (sz == 2) {
		int a = 1, b = 1;
		for (int i = 1; i <= n; i++) {
			if (!r[i]) {
				a = i; b = v[i][0];
				break;
			}
		}
		cout << "? " << a << " " << b << endl;
		int t; cin >> t;
		cout << "! " << t << endl;
	}
	else {
		int a = 1;
		for (int i = 1; i <= n; i++) {
			if (!r[i]) {
				a = i;
				break;
			}
		}
		cout << "! " << a << endl;
	}
	return 0;
}