#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<vector<int>> a(n + 2);
	for (int v, i = 0; i < n; ++i) {
		cin >> v;
		a[v].push_back(i);
	}
	for (auto& v : a) reverse(v.begin(), v.end());
	int tmx = 0, pmx = 0;
	vector<int> res;
	while (1) {
		int i = 0;
		for (; 1; ++i) {
			while (a[i].size() && a[i].back() < pmx) a[i].pop_back();
			if (a[i].empty()) break;
			tmx = max(tmx, a[i].back() + 1);
			a[i].pop_back();
		}
		if (!i) {
			for (; tmx < n; ++tmx) res.push_back(0);
			break;
		}
		res.push_back(i);
		pmx = tmx;
	}
	cout << res.size() << "\n";
	for (int v : res) cout << v << " ";
	cout << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}