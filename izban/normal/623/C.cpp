#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 1 << 17;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const double PHI = (sqrt(5.0) - 1) / 2.0;

int n;
pair<int, int> a[MAXN];

ll sqr(ll x) {
	return x * x;
}

vector<pair<int, int> > bb[4];

bool f(ll d) {
	bool ok = 0;
	for (int it = 0; it < 4; it++) {
		vector<pair<int, int> > b = bb[it];


		sort(b.begin(), b.end());
		vector<int> mnl(n), mxl(n), mnr(n), mxr(n);
		mnl[0] = mxl[0] = b[0].second;
		for (int i = 1; i < n; i++) {
			mnl[i] = min(mnl[i - 1], b[i].second);
			mxl[i] = max(mxl[i - 1], b[i].second);
		}
		mnr[n - 1] = mxr[n - 1] = b[n - 1].second;
		for (int i = n - 2; i >= 0; i--) {
			mnr[i] = min(mnr[i + 1], b[i].second);
			mxr[i] = max(mxr[i + 1], b[i].second);
		}

		int r = -1;
		for (int l = 0; l < n; l++) {
			r = max(r, l);
			while (r + 1 < n && sqr(b[r + 1].first - b[l].first) <= d) {
				r++;
			}
			int mxy = -1;
			if (l) {
				mxy = max(mxy, abs(mnl[l - 1]));
				mxy = max(mxy, abs(mxl[l - 1]));
			}
			if (r + 1 < n) {
				mxy = max(mxy, abs(mnr[r + 1]));
				mxy = max(mxy, abs(mxr[r + 1]));
			}
			if (mxy == -1) {
				ok |= l == 0 && r == n - 1;
			}
			else {
				int mny1 = 1e9;
				int mxy1 = -1e9;
				if (l) {
					mny1 = min(mny1, mnl[l - 1]);
					mxy1 = max(mxy1, mxl[l - 1]);
				}
				if (r + 1 < n) {
					mny1 = min(mny1, mnr[r + 1]);
					mxy1 = max(mxy1, mxr[r + 1]);
				}
				ok |= sqr(max(abs(b[l].first), abs(b[r].first))) + sqr(mxy) <= d && sqr(mxy1 - mny1) <= d;
			}
			if (ok) {
				ok = ok;
			}
		}
	}
	return ok;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);

		for (int it = 0; it < 4; it++) {
			vector<pair<int, int> > b(n);
			for (int i = 0; i < n; i++) b[i] = a[i];
			sort(b.begin(), b.end());
			for (int i = 0; i < n; i++) {
				a[i] = make_pair(-a[i].second, a[i].first);
			}
			bb[it] = b;
		}

		ll l = -1, r = 1e17;
		while (r - l > 1) {
			ll m = (l + r) >> 1;
			if (f(m)) r = m;
			else l = m;
		}
		cout << r << endl;
	}

	return 0;
}