#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, long long> > v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		v.clear();
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			int c = 1;
			while (a % m == 0) {
				a /= m;
				c *= m;
			}
			if (v.empty() || v.back().first != a) v.push_back(make_pair(a, c));
			else v.back().second += c;
		}
		int k; cin >> k;
		int pi = 0;
		bool f = true;
		for (int i = 1; i <= k; i++) {
			int a; cin >> a;
			if (!f) continue;
			int c = 1;
			while (a % m == 0) {
				a /= m;
				c *= m;
			}
			while (c) {
				if (pi >= v.size() || a != v[pi].first) {
					f = false;
					break;
				}
				if (c >= v[pi].second) {
					c -= v[pi].second;
					pi++;
				}
				else {
					v[pi].second -= c;
					break;
				}
			}
		}
		if (!f || pi < v.size()) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
	return 0;
}