// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct seg {
	ll l, r;
	seg(ll l=0, ll r=0) : l(l), r(r) {}

	bool operator< (const seg& b) const {
		return l < b.l;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll n, k, l;
		cin >> n >> k >> l;
		vector<ll> a(n+2);
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}

		a[n+1] = -1e10;

		vector<seg> b = {seg(0, 2*k)};
		for (int i=1; i<=n+1; i++) {
			if (b.empty()) break;

			ll w = a[i] + k - l - 1;
			ll bl = k-w;
			ll br = k+w+1;

			if (w >= k) {
				b = {};
				break;
			}

			if (w < 0) {
				b = {seg(0, 2*k)};
				continue;
			}

			vector<seg> c;

			auto go2 = [&](ll l, ll r) {
				// in range [0, 2*k]
				if (l >= r) return;
				c.emplace_back(l, r);
			};

			auto go = [&](ll l, ll r) {
				// in range [0, 2*k]
				go2(max(l, 0ll), min(r, bl));
				go2(max(l, br), min(r, 2*k));
			};

			for (auto [l, r] : b) {
				l++;
				r++;
				if (r == 2*k+1) {
					go(l, 2*k);
					go(0, 1);
				} else {
					go(l, r);
				}
			}

			b = c;
			c = {};
			// extensions?
			for (auto [l, r] : b) {
				if (max(l, 0ll) < min(r, bl)) {
					go2(r, bl);
				}

				if (max(l, br) < min(r, 2*k)) {
					go2(r, 2*k);
					go2(0, bl);
				}

				go2(l, r);
			}

			if (c.empty()) continue;

			// saberi se
			b = c;
			c = {};

			int j = 0;
			sort(begin(b), end(b));
			for (int i=1; i<(int)b.size(); i++) {
				if (b[i].l > b[j].r) {
					b[++j] = b[i];
				} else {
					b[j].r = max(b[j].r, b[i].r);
				}
			}

			b.resize(j+1);
		}

		cout << (b.size() ? "Yes\n" : "No\n");
	}
}