#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// thank you radewoosh, very cool

struct kamion {
	int s, f, c, r;
} b[250005];
int n, m;
int a[405];

bool moze(kamion u, ll t) {
	ll gorivo = t;
	int ref = 0;
	for (int i=u.s; i<u.f; i++) {
		// mogu li da stignem do sledeceg a da ne tocim?
		ll trosim = (a[i+1] - a[i]) * 1ll * u.c;
		if (trosim > t)
			return false; // nema teorije
		if (gorivo - trosim < 0) {
			ref++;
			gorivo = t;
		}
		gorivo -= trosim;
	}
	return ref <= u.r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=0; i<m; i++)
		cin >> b[i].s >> b[i].f >> b[i].c >> b[i].r;

	srand(reinterpret_cast<ll>(new int) ^ *(new int));
	for (int i=0; i<m; i++) {
		int r = (rand() + (rand() << 10)) % (i+1);
		swap(b[i], b[r]);
	}
	ll vbest = 0;
	for (int i=0; i<m; i++) {
		if (!moze(b[i], vbest)) {
			// trazi binarno
			ll lo = vbest+1, hi = 1e18;
			while (lo <= hi) {
				ll mid = (lo + hi) >> 1;
				if (moze(b[i], mid)) {
					vbest = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
		} // inace nema vajde
	}
	cout << vbest << '\n';
}