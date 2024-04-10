#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	vector<pair<int, int>> a, b;

	int amaxl = -1e9;
	int bmaxl = -1e9;
	int aminr = +2e9;
	int bminr = +2e9;

	cin >> n;
	a.resize(n);
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
		amaxl = max(amaxl, a[i].first);
		aminr = min(aminr, a[i].second);
	}

	cin >> m;
	b.resize(m);
	for (int i=0; i<m; i++) {
		cin >> b[i].first >> b[i].second;
		bmaxl = max(bmaxl, b[i].first);
		bminr = min(bminr, b[i].second);
	}

	// a pre b
	int sol;

	sol = max(amaxl - bminr, bmaxl - aminr);
	if (sol < 0) {
		sol = 0;
	}

	cout << sol;

}