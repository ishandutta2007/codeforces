#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll racunaj(const vector<ll>& a, ll b) {
	ll z = 0;
	for (ll x : a)
		z += __builtin_popcount(b-x);
	return z;
}

void brut(const vector<ll>& a) {
	ll h = *max_element(a.begin(), a.end());
	ll x = 0, y = 1e18;
	for (ll i=h; i<=2*h; i++) {
		ll z = racunaj(a, i);
		if (z < y) {
			y = z;
			x = i;
		}
	}
	cerr << "najbolje postaviti sve na: " << x << '\n';
	cout << y << '\n';
}

struct poredi {
	bool operator() (const pair<ll, ll>& a, const pair<ll, ll>& b) const {
		return a.second < b.second;
	}
};

void residp(const vector<ll>& a) {
	ll maxa = *max_element(a.begin(), a.end());
	int n = a.size();
	vector<pair<ll, ll>> ol, nu;
	ol.emplace_back(0, 0);
	ll sol = 1e18;

	for (int b=0; b<60; b++) {
		int k = ol.size();
		sort(ol.begin(), ol.end());
		vector<ll> zz(k+1); // zz[i] je broj y-ova koji ce imati cifru 0
		// ako se primeni maska ol[i].first
		for (ll y : a) {
			ll by = y & ((1ll << b) - 1);
			auto it = lower_bound(ol.begin(), ol.end(), make_pair(by, -1ll));

			if (y & (1ll << b)) {
				// bice 0 osim ako se ne doda bar
				zz[0]++;
				zz[it-ol.begin()]--;
			} else {
				zz[it-ol.begin()]++;
				zz[k]--;
			}
		}
		for (int i=0; i<k; i++)
			zz[i+1] += zz[i];

		for (auto [p, q] : ol) {
			if (p >= maxa)
				sol = min(sol, q);
		}

		// for (auto [a, b] : ol)
		// 	cerr << a << ' ' << b << '\n';
		// cerr << '\n';

		for (int i=0; i<k; i++) {
			// cerr << "zz " << ol[i].first << ' ' << zz[i] << '\n';
			nu.emplace_back(ol[i].first, ol[i].second + n-zz[i]);
			nu.emplace_back(ol[i].first + (1ll << b), ol[i].second + zz[i]);
		}

		ol = {};
		sort(nu.begin(), nu.end());
		vector<ll> borders = {0};
		for (ll y : a) {
			borders.push_back(y & ((1ll << (b+1)) - 1));
		}
		borders.push_back(1ll << (b+1));
		sort(borders.begin(), borders.end());
		borders.resize(unique(borders.begin(), borders.end()) - borders.begin());
		// for (int x : borders)
		// 	cerr << x << ' ';
		// cerr << '\n';
		int bop = 0;

		for (auto [p, q] : nu) {
			if (ol.empty()) {
				ol.emplace_back(p, q);
			} else if (p >= borders[bop]) {
				ol.emplace_back(p, q);
				while (p >= borders[bop])
					bop++;
			} else {
				if (q < ol.back().second) {
					ol.back() = {p, q};
				}
			}
		}

		nu = {};
	}

	cout << sol << '\n';
}

/*
radicemo ovako. posmatrajmo cifru na poziciji 0 kod svih brojeva. Imamo
dva izbora, da ta cifra svima bude 0 ili da svima bude 1. Ako idemo na to
da svima cifra bude 0, onima kojima je ta cifra vec 1 dodajemo 1, ostale
ne diramo, i obratno, i cena tog poteza je jednaka broju cifara koje menjamo.

Sada se granamo na dva slucaja sa razlicitim nizovima brojeva. Za svaki od njih
sada posmatramo cifru na poziciji 1 i radimo slicno kao do sad.

Dakle mozemo da zamislimo da je stablo odluka kompletno binarno stablo sa
grananjem na 0-granu ili 1-granu u zavisnosti od toga na koju vrednost postavljamo
cifru.

Neki cvor ovog stabla je odredjen njegovom dubinom (broj cifara) i nizom
cifara (ceo broj) i u sebi sadrzi trenutnu ukupnu cenu da se dodje do takve
konfiguracije. Ovaj niz cifara opisuje kako tacno izgleda poslednjih
`dubina` cifara svih brojeva.

Neka je dubina b, a taj niz cifara mask < 2^b. Koja je sada b-ta cifra broja
iz niza a cija je originalna vrednost bila y? Neka je by = y mod 2^b.
Ako je by <= mask, onda je ista kao sto je sad, inace je razlicita.
Hajde da efikasno nadjemo za svako mask koliko ce biti 0-cifara a koliko 1-cifara
na poziciji b, da bismo znali cenu nakon odluke.

Recimo da neko y ima cifru 0 na poziciji b. Onda se broj 

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& x : a)
		cin >> x;
	// brut(a);
	residp(a);
}

/*
5
23 45 14 50 31

23 =   4   2 1 0
45 = 5   3 2   0
14 =     3 2 1
50 = 5 4     1
31 =   4 3 2 1 0

najbolje staviti na:
55 = 5 4   2 1 0
*/