#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct stvar {
	ll tezina;
	int predak;
};

stvar b[400005][20], g[400005][20];

int cvorovi = 0;

void dodaj(int parent, ll wt) {
	int x = ++cvorovi;

	// popuni b
	b[x][0] = {wt, parent};
	for (int i=1; i<20; i++) {
		int y = b[x][i-1].predak;

		b[x][i].tezina = max(b[x][i-1].tezina, b[y][i-1].tezina);
		b[x][i].predak = b[y][i-1].predak;
	}

	// nadji prvog iznad veceg

	int y = parent;

	for (int i=19; i>=0; i--) {
		if (b[y][i].tezina < wt) {
			y = b[y][i].predak;
		}
	}

	g[x][0] = {wt, y};

	// popuni g
	for (int i=1; i<20; i++) {
		int y = g[x][i-1].predak;

		g[x][i] = {min((ll)1e16, g[x][i-1].tezina + g[y][i-1].tezina), g[y][i-1].predak};
	}
}

int citaj(int x, ll limit) {
	int len = 0;
	for (int i=19; i>=0; i--) {
		if (g[x][i].tezina <= limit) {
			len += 1 << i;
			limit -= g[x][i].tezina;
			x = g[x][i].predak;
		}
	}
	return len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<20; i++) {
		b[0][i] = {(ll)1e16, 0};
		g[0][i] = {(ll)1e16, 0};
	}

	dodaj(0, 0);

	ll q, last = 0;
	cin >> q;
	while (q--) {
		ll t, a, b;
		cin >> t >> a >> b;
		a ^= last;
		b ^= last;

		if (t == 1) {
			dodaj(a, b);
		} else {
			last = citaj(a, b);
			cout << last << '\n';
		}
	}
	
}