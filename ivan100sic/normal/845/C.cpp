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

map<int, int> c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int l, r;
		cin >> l >> r;
		c[l] += 1;
		c[r+1] -= 1;
	}
	int total = 0;
	for (auto p : c) {
		total += p.second;
		if (total > 2) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}