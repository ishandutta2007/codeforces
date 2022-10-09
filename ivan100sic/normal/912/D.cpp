#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll zbir = 0;
int n, m, r, k;
ll dodato = 0;

ll koord(ll x, ll w) {
	// gde moze da bude levi kraj?
	ll l = x - r + 1;
	ll h = x;

	l = max(l, 1ll);
	h = min(h, w - r + 1);

	return h-l+1;
}

ll vrednost(int x, int y) {
	return koord(x, n) * koord(y, m);
}

void dodaj(int x, int y) {
	zbir += vrednost(x, y);
	dodato++;
	if (dodato == k) {
		cout.precision(20);
		cout << fixed << zbir * 1.0 / (n-r+1) / (m-r+1) << '\n';
		exit(0);
	}
	
}

struct stvar {
	int x, y;
	ll val;

	bool operator< (const stvar& other) const {
		return make_tuple(val, x, y) >
			make_tuple(other.val, other.x, other.y);
	}
};

set<stvar> pq;
set<pair<int, int>> erased;

void pqa(int x, int y) {
	if (erased.count({x, y})) {
		return;
	}
	if (x < 0 || x > n || y < 0 || y > m) {
		return;
	}
	pq.insert({x, y, vrednost(x, y)});
}

void pqe(int x, int y) {
	pq.erase({x, y, vrednost(x, y)});
	erased.insert({x, y});
}

void resi() {
	ll br = 0;
	ll zbir = 0;

	while (br < k) {
		auto trip = *pq.begin();
		pqe(trip.x, trip.y);

		// cerr << trip.x << ' ' << trip.y << ' ' << trip.val << '\n';

		zbir += trip.val;
		br++;

		pqa(trip.x + 1, trip.y + 0);
		pqa(trip.x - 1, trip.y + 0);
		pqa(trip.x + 0, trip.y + 1);
		pqa(trip.x + 0, trip.y - 1);
	}

	cout.precision(20);
	cout << fixed << zbir * 1.0 / (n-r+1) / (m-r+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);


	cin >> n >> m >> r >> k;

	if (n > m) {
		swap(n, m);
	}

	if (n % 2 == 1) {
		// srednji sloj
		for (int i=n/2+1; i<=m-n/2; i++) {
			pq.insert({n/2+1, i, vrednost(n/2+1, i)});
		}
	} else {
		// srednji sloj
		for (int i=n/2; i<=m-n/2+1; i++) {
			pq.insert({n/2, i, vrednost(n/2, i)});
			pq.insert({n/2+1, i, vrednost(n/2+1, i)});
		}
	}

	resi();
}