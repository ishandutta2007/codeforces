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

struct ring {
	int a, b, h;

	bool operator< (const ring& other) const {
		return b > other.b || (b == other.b && a > other.a);
	}
};

int n;
ring a[100005];

int ua[100005], uac;

const int MAXN = 131072;
struct tree {
	long long a[2*MAXN];

	void init() {
		memset(a, 128, sizeof(a));
	}

	void write(int x, long long val) {
		x += MAXN - 1;
		a[x] = val;
		while (x > 1) {
			x /= 2;
			a[x] = max(a[2*x], a[2*x+1]);
		}
	}

	long long get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return 0;
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}
		int nm = (nl + nr) >> 1;
		return max(
			get(l, r, 2*node, nl, nm),
			get(l, r, 2*node+1, nm+1, nr)
		);
	}
} drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i].a >> a[i].b >> a[i].h;
		ua[i] = a[i].a;
	}

	sort(a+1, a+n+1);
	sort(ua+1, ua+n+1);
	uac = unique(ua+1, ua+n+1) - (ua+1);
	ua[++uac] = 1'000'000'001;

	drvo.write(uac, 0);

	for (int i=1; i<=n; i++) {
		int moje = lower_bound(ua+1, ua+uac+1, a[i].a) - ua;
		int gore = lower_bound(ua+1, ua+uac+1, a[i].b) - ua - 1;

		long long sol = a[i].h + drvo.get(1, gore);

		drvo.write(moje, sol);
	}

	cout << drvo.get(1, MAXN);
}