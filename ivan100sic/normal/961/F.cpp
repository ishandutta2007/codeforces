#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
pair<int, ull> h[1000005];
pair<int, ull> p[1000005];
const int BASE = 1337;
const int MOD = 1000000007;
int w[500005], z[500005];

pair<int, ull> hv(int l, int r) {
	int u = h[r].first - h[l].first * 1ll * p[r-l].first % MOD;
	if (u < 0) u += MOD;
	return {u, h[r].second - h[l].second * p[r-l].second};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	p[0].first = 1;
	p[0].second = 1;
	for (int i=1; i<1000005; i++) {
		p[i].first = p[i-1].first * 1ll * BASE % MOD;
		p[i].second = p[i-1].second * BASE;
	}

	cin >> n >> s;

	for (int i=0; i<n; i++) {
		h[i+1].first = (h[i].first * 1ll * BASE + s[i]) % MOD;
		h[i+1].second = h[i].second * BASE + s[i];
	}

	fill(z, z+n, -1);

	// nadji radijuse
	for (int i=0, j=n-1; i<=j; i++, j--) {
		int lo = 0, hi = i, o = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (hv(i-mid, i+mid+1) == hv(j-mid, j+mid+1)) {
				o = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		w[i] = o;
		// cerr << w[i] << ' ';
		if (i != j)
			z[i - w[i]] = max(z[i - w[i]], w[i]);		
	}

	for (int i=0; i<n/2; i++) {
		if (i) z[i] = max(z[i], z[i-1] - 1);
		cout << 2*z[i] + 1 << ' ';
	}
	if (n % 2)
		cout << "-1\n";
	else
		cout << "\n";
}