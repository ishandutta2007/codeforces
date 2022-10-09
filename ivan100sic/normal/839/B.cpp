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

	// nema sanse da je ovo tacno resenje

	int n, k, t=0, s=0;
	cin >> n >> k;

	for (int i=1; i<=k; i++) {
		int x;
		cin >> x;
		if (x % 2) {
			x++;
			t++;
		}
		s += x;
	}

	if (s > 8*n) {
		cout << "NO";
		return 0;
	}

	if (s == 8*n) {
		if (k == 4*n && t < n) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}