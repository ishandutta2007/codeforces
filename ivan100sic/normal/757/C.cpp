#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int n, m;
int g[1000005], gg = 1;

long long f[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


	cin >> n >> m;

	for (int i=1; i<=m; i++) {
		g[i] = 1;
	}

	for (int i=1; i<=n; i++) {

		map<int, int> c;
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			c[y]++;
		}

		map<int, vector<int>> b;
		for (auto p : c) {
			b[p.second].push_back(p.first);
		}


		for (auto p : b) {
			// p.second je jedna nova grupa
			map<int, int> mapping;

			for (int x : p.second) {
				if (mapping[g[x]]) {
					g[x] = mapping[g[x]];
				} else {
					g[x] = mapping[g[x]] = ++gg;
				}
			}
		}
	}

	//cerr << __LINE__ << '\n';

	{
		map<int, int> c;
		for (int i=1; i<=m; i++) {
			c[g[i]]++;
		}
		
		long long sol = 1;
		const long long MOD = 1'000'000'007;

		f[1] = 1;
		for (int i=2; i<=m; i++) {
			f[i] = (f[i-1] * i) % MOD;
		}

		for (auto p : c) {
			sol = sol * f[p.second] % MOD;
		}

		cout << sol;

	}

}