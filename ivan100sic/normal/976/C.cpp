#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r, id;
	bool operator< (seg b) const {
		if (l != b.l) {
			return l < b.l;
		}
		return r > b.r;
	}
};

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<seg> v;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back({ l, r, i });
	}
	sort(v.begin(), v.end());
	// nadji bilo koju "poluinverziju"
	int best_r = -1, best_id = -1;
	for (seg x : v) {
		if (x.r <= best_r) {
			cout << x.id << ' ' << best_id << '\n';
			return;
		}
		if (x.r > best_r) {
			best_r = x.r;
			best_id = x.id;
		}
	}
	cout << "-1 -1\n";
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}