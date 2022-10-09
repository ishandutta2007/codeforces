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

	set<int> h;

	for (int i=1; i<=m; i++) {
		int x;
		cin >> x;
		h.insert(x);
	}

	int bone = 1;
	int fell = 0;

	if (h.count(bone)) {
		fell = 1;
	}

	for (int i=1; i<=k; i++) {
		int u, v;
		cin >> u >> v;

		if (!fell) {
			if (bone == u || bone == v) {
				bone ^= u ^ v;
			}
			if (h.count(bone)) {
				fell = 1;
			}
		}
	}

	cout << bone;
}