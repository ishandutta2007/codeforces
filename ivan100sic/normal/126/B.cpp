#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	int n = (int)s.size();

	// z-func
	vector<int> z(n, 0);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}

	vector<int> prefmax(n, 0);
	for (int i = 1; i < n; i++) {
		prefmax[i] = max(prefmax[i - 1], z[i]);
	}

	int sol = 0;

	for (int x = 1; x < n - 1; x++) {
		if (z[n - x] == x && prefmax[n - x - 1] >= x) {
			sol = x;
		}
	}

	if (sol) {
		cout << s.substr(0, sol) << '\n';
	}
	else {
		cout << "Just a legend\n";
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}

/*
1995persistentlazytreap2001
*/