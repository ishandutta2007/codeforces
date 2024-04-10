#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[100005];

int ssp[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
	}
	for (int i=1; i<=m; i++) {
		sort(e[i].begin(), e[i].end(), greater<int>());
		basic_string<int> tmp(e[i].size() + 1, 0);
		partial_sum(e[i].begin(), e[i].end(), tmp.begin() + 1);
		e[i] = tmp;

		for (int j=0; j<(int)e[i].size(); j++)
			if (e[i][j] > 0)
				ssp[j] += e[i][j];
	}

	cout << *max_element(ssp, ssp+100005) << '\n';

}