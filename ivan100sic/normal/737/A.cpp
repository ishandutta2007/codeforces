#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, s, t;
int g[200005], c[200005], v[200005], l[200005];
int suml[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k >> s >> t;
	for (int i=1; i<=n; i++) {
		cin >> c[i] >> v[i];
	}
	for (int i=1; i<=k; i++) {
		cin >> g[i];
	}
	k++;
	sort(g+1, g+k);
	g[k] = s;
	for (int i=1; i<=k; i++) {
		l[i] = g[i] - g[i-1];
	}

	sort(l+1, l+k+1);
	for (int i=1; i<=k; i++) {
		//cerr << "segment: " << l[i] << '\n';
		suml[i] = suml[i-1] + l[i];
	}

	int mc = 1999999999;
	for (int i=1; i<=n; i++) {
		int c = ::c[i];
		int v = ::v[i];

		// da li moze da predje?
		if (v < l[k]) {
			continue;
		}

		// koliko vremena mu treba?
		int split = upper_bound(l+1, l+k+1, v/2) - l;

		int t_fast = suml[split-1];
		// v = 7, l = 5, t = (v-l) + 2*(2l-v) = 3l-v = 15-7 = 8
		long long t_eco = 3ll * (suml[k] - suml[split-1]) - v * 1ll * (k-split+1);

		//cerr << t_fast << ' ' << t_eco << ' ' << split << '\n';

		if (t_fast + t_eco <= t) {
			mc = min(mc, c);
		}
	}

	if (mc == 1999999999) {
		mc = -1;
	}

	cout << mc;
}