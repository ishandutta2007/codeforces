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

int c[10005], n, k;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	if (k == 0) {
		long long sol = 0;
		for (int i=0; i<=10000; i++) {
			sol += 1ll * c[i] * (c[i] - 1) / 2;
		}
		cout << sol;
		return 0;
	}

	for (int i=0; i<(1<<14); i++) {
		if (__builtin_popcount(i) == k) {
			v.push_back(i);
		}
	}

	long long sol = 0;
	for (int i=0; i<=10000; i++) {
		for (int y : v) {
			int j = i ^ y;
			if (j <= 10000) {
				sol += c[i] * 1ll * c[j];
			}
		}
	}

	cout << sol/2 << '\n';
}