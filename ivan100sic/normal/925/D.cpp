#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
	Teorema: Ako optimalan put sadrzi neki cvor 2 ili vise puta,
	onda postoji tacno jedan takav cvor, to mu je tacno drugo javljanje
	i to je pretposlednji cvor na putu.

	Dokaz: Pretpostavimo suprotno. Posmatrajmo optimalan put kog kojeg
	postoji cvor koji se ponavlja. Posto smo na optimalnom putu, u pocetku
	je grana od tog cvora do N bila zatvorena, jer bismo inace iskoristili
	nju i dobili kraci put. To znaci da je pri drugom ulasku u cvor ta
	grana otvorena i mozemo da je iskoristimo.


	Ako postoji put od 1 do N pomocu grana koje su u pocetku otvorene
	onda je taj put validan kandidat za resenje.

	Drugo moguce resenje se sastoji od otvorenog puta koji sadrzi cvorove
	1-x-y (mozda jos neke izmedju) takvog da je grana x-y zatvorena. Po
	dolasku u y odemo u x sada otvorenom granom a od x odemo direktno na cilj.

	Nema resenja akko je blok graf od G zvezda, blokovi se seku samo u cvoru 1
	i svaki blok je kompletan graf. Mi necemo ovo da trazimo vec cemo da probamo
	da nadjemo najbolji 1-x-y put.

	Ima dva "optimalna" scenarija: 1-x-y-1, 1-x-y-z-x (A i B)
	
	Prvi detektujemo BFS-om, trazimo cvor na udaljenosti dva. Ako postoji nasli
	smo 1-x-y put (i to duzine 3 sto je super)

	Ako prvi scenario upali, nema potrebe da radimo drugi. Inace,
	Drugi scenario: Trazimo tri suseda ciji je indukovani podgraf put sa 3 cvora
	Detektujemo ovako: Markiramo sve susede od 1 (to je ujedno i cela p.k.) osim samog
	keca. Medju njima, ako je susedstvo relacija ekvivalencije, nema resenja. (recimo
	hash liste suseda). Zatim za svaku granu proverim da li ta dva cvora imaju isti hash,
	ako nemaju, nasli smo resenje.
*/

int n, m;
vector<int> e[300005];
int d[300005], p[300005];
ull h[300005];

void bfs() {
	fill(d + 1, d + n + 1, -1);
	d[1] = 0;
	p[1] = 0;
	queue<int> q;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				p[y] = x;
				q.push(y);
			}
		}
	}
}

vector<int> obican_put() {
	if (d[n] != -1) {
		vector<int> v;
		int x = n;
		while (x != 1) {
			v.push_back(x);
			x = p[x];
		}
		v.push_back(1);
		reverse(v.begin(), v.end());
		return v;
	}
	else {
		return {};
	}
}

vector<int> a_put() {
	if (d[n] == 1) {
		return {};
	}

	int x = -1, y = -1;
	for (int i = 2; i < n; i++) {
		if (d[i] == 2) {
			y = i;
			x = p[i];
			return { 1, x, y, 1, n };
		}
	}

	return {};
}

vector<int> b_put() {

	// ako ima nekog na udaljenosti 2 odustani
	for (int i = 1; i <= n; i++) {
		if (d[i] == 2) {
			return {};
		}
	}

	for (int i = 1; i <= n; i++) {
		e[i].push_back(i);
		sort(e[i].begin(), e[i].end());
		for (int x : e[i]) {
			h[i] = (h[i] * 903103143 + x) ^ 441434351843857ull;
		}
	}

	for (int x = 1; x <= n; x++) {
		if (d[x] != 1) {
			continue;
		}
		for (int y : e[x]) {
			if (x == y) {
				continue; // xd
			}

			if (d[y] != 1) {
				continue;
			}

			// mora y da ne bude susedan sa n
			{
				auto it = lower_bound(e[y].begin(), e[y].end(), n);
				if (it != e[y].end()) {
					continue;
				}
			}

			if (h[x] != h[y] && e[x].size() >= e[y].size()) {
				// nadji razliku
				vector<int> diff;
				set_difference(e[x].begin(), e[x].end(), 
					e[y].begin(), e[y].end(), back_inserter(diff));
				return { 1, y, x, diff[0], y, n };
			}
		}
	}

	return {};
}

vector<int> sol;

void zaracunaj(vector<int> v) {
	if (v.size() == 0) {
		return;
	}
	if (sol.size() == 0 || v.size() < sol.size()) {
		sol = v;
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	bfs();
	zaracunaj(obican_put());

	zaracunaj(a_put());
	zaracunaj(b_put());

	if (sol.size() == 0) {
		cout << "-1\n";
	}
	else {
		cout << sol.size() - 1 << '\n';
		for (int x : sol) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}