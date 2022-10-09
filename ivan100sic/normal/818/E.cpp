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
	int b[2*MAXN];

	void init() {
		for (int i=1; i<=n; i++) {
			b[i + MAXN - 1] = a[i];
		}
		for (int i=MAXN-1; i>0; i--) {
			b[i] = (1ll * b[2*i] * b[2*i+1]) % k;
		}
	}

	int get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return 1;
		}
		if (l <= nl && nr <= r) {
			return b[node];
		}

		int nm = (nl + nr) >> 1;

		int p1 = get(l, r, 2*node, nl, nm);
		int p2 = get(l, r, 2*node+1, nm+1, nr);

		return 1ll * p1 * p2 % k;
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
		a[i] %= k;
	}

	drvo.init();

	cerr << drvo.get(1, n) << '\n';
	cerr << drvo.get(2, 2) << '\n';

	long long sol = 1ll * n * (n+1) / 2;

	int r = 0;
	for (int l=1; l<=n; l++) {
		if (a[l] == 0) {
			r = l-1;
		} else {
			if (r < l) {
				r = l;
			}
			while (r < n && drvo.get(l, r+1)) {
				r++;
			}
			sol -= r-l+1;	
		}
		cerr << l << ' ' << r << '\n';
	}

	cout << sol;


}