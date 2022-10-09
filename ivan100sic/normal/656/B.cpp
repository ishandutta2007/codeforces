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

	int x = 720720;
	int n, c = 0;
	vector<int> m, r;
	cin >> n;
	m.resize(n);
	r.resize(n);
	for (int i=0; i<n; i++) {
		cin >> m[i];
	}
	for (int i=0; i<n; i++) {
		cin >> r[i];
	}

	for (int i=0; i<x; i++) {
		for (int j=0; j<n; j++) {
			if (i % m[j] == r[j]) {
				c++;
				break;
			}
		}
	}

	cout.precision(20);
	cout << fixed << 1.0 * c / x;
}