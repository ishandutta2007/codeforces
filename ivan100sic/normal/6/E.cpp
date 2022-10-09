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

int n, k;
int a[100005];

const int MAXN = 131072;

struct tree {
	int hi[2*MAXN], lo[2*MAXN];

	void init() {
		for (int i=1; i<=n; i++) {
			hi[i + MAXN - 1] = a[i];
			lo[i + MAXN - 1] = a[i];
		}
		for (int i=MAXN-1; i>=1; i--) {
			hi[i] = max(hi[2*i], hi[2*i+1]);
			lo[i] = min(lo[2*i], lo[2*i+1]);
		}
	}

	pair<int, int> get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return {1e9, -1e9};
		}

		if (l <= nl && nr <= r) {
			return {lo[node], hi[node]};
		}

		int nm = (nl + nr) / 2;

		auto p1 = get(l, r, 2*node, nl, nm);
		auto p2 = get(l, r, 2*node+1, nm+1, nr);

		return {min(p1.first, p2.first), max(p1.second, p2.second)};
	}

	int gett(int l, int r) {
		auto p = get(l, r);
		return p.second - p.first;
	}
} drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	drvo.init();

	int l = 1, r = 1;
	int sol = 0;
	vector<int> b;

	while (l <= n) {
		if (r < l) {
			r = l;
		}
		while (r < n && drvo.gett(l, r+1) <= k) {
			r++;
		}

		// cerr << l << ' ' << r << '\n';

		if (r - l > sol) {
			sol = r - l;
			b.clear();
			b.push_back(l);
		} else if (r - l == sol) {
			b.push_back(l);
		}
		l++;
	}

	cout << sol+1 << ' ' << b.size() << '\n';
	for (int x : b) {
		cout << x << ' ' << x + sol << '\n';
	}

}