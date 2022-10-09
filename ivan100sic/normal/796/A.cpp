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

	int n, m, k;

	cin >> n >> m >> k;
	vector<int> a(n);

	m--;

	for (int& x : a) {
		cin >> x;
	}

	int sol = 1e9;

	for (int i=0; i<n; i++) {
		if (a[i] && a[i] <= k) {
			sol = min(sol, 10*abs(i - m));
		}
	}

	cout << sol;
}