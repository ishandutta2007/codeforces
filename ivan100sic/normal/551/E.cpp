#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, class U>
using ht = gp_hash_table<T, U>;

struct query {
	int t, l, r, x;
};

const int QB = 500;

ll a[500005], n;
query u[50005]; int q;

int b[2*QB + 5], k;
ht<ll, pair<int, int>> mp[2*QB + 5];
ll diff[2*QB + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			u[i] = {t, l, r, x};
		} else {
			int x;
			cin >> x;
			u[i] = {t, x, x, x};
		}
	}

	for (int l=0; l<q; l+=QB) {
		int r = min(l+QB, q);

		k = 0;

		for (int i=l; i<r; i++) {
			if (u[i].t == 1) {
				b[k++] = u[i].l;
				b[k++] = u[i].r;
			}
		}
		b[k++] = 0;
		b[k++] = n;

		sort(b, b+k);
		k = unique(b, b+k) - b;
		k--; // b[k] = n

		for (int i=0; i<k; i++) {
			int l = b[i];
			int r = b[i+1];

			mp[i].clear();

			for (int j=l; j<r; j++) {
				ll x = a[j];
				auto& it = mp[i][x];
				if (!it.first) {
					it.first = j+1;
					it.second = j+1;
				} else {
					it.second = j+1;
				}
			}
		}

		fill(diff, diff+k, 0);

		for (int i=l; i<r; i++) {
			if (u[i].t == 1) {
				// cerr << "dodavam " << i << '\n';
				// cerr << u[i].l << ' ' << u[i].r << '\n';
				for (int j=0; j<k; j++) {
					// cerr << "blok " << b[j] << ' ' << b[j+1] << '\n';
					if (u[i].l <= b[j] && b[j+1] <= u[i].r) {
						// cerr << "dodajem " << u[i].x << " u blok " << diff[j] << '\n';
						diff[j] += u[i].x;
					}
				}
			} else {
				int y = u[i].x;
				int lo = 123123123;
				int hi = -123123123;

				for (int i=0; i<k; i++) {
					ll t = y - diff[i];
					// cerr << "trazim " << t << " u bloku " << i << '\n';
					auto it = mp[i].find(t);
					if (it != mp[i].end()) {
						lo = min(lo, it->second.first);
						hi = max(hi, it->second.second);
					}
				}

				if (lo <= hi) {
					cout << hi-lo << '\n';
				} else {
					cout << "-1\n";
				}
			}
		}

		for (int i=0; i<k; i++) {
			for (int j=b[i]; j<b[i+1]; j++) {
				a[j] += diff[i];
			}
		}
	}
}