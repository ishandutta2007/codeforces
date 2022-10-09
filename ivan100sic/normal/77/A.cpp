// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string h[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};

int htoi(string s) {
	return find(h, h+7, s) - h;
}

int e[7][7];
ll d[3];
int t[7];

pair<ll, int> sol = {-1e18, 0};

void kraj() {
	ll elo = 1e18, ehi = -1e18;

	for (int i=0; i<3; i++) {
		int ts = 0;
		for (int j=0; j<7; j++) {
			if (t[j] == i) {
				ts++;
			}
		}

		if (ts == 0) {
			return;
		}

		ll e = d[i] / ts;
		elo = min(elo, e);
		ehi = max(ehi, e);
	}

	ll dif = elo - ehi;
	int lkng = 0;
	for (int i=0; i<7; i++) {
		for (int j=0; j<7; j++) {
			if (i != j && t[i] == t[j]) {
				lkng += e[i][j];
			}
		}
	}

	sol = max(sol, pair(dif, lkng));
}

void rek(int l) {
	if (l == 7) {
		kraj();
	} else {
		for (int i=0; i<3; i++) {
			t[l] = i;
			rek(l+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	while (n--) {
		string a, b, c;
		cin >> a >> b >> c;
		e[htoi(a)][htoi(c)] = 1;
	}

	cin >> d[0] >> d[1] >> d[2];

	rek(0);

	cout << -sol.first << ' ' << sol.second << '\n';
}