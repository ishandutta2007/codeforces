#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

struct karta {
	int vreme, grad, smer, cena;

	bool operator< (const karta& other) const {
		return vreme < other.vreme;
	}
};

int n, m, k;
karta a[100005];
multiset<int> lol[100005], lor[100005];
int punil, punir;
long long totl, totr;

void dodaj(multiset<int>* lop, int& brpuni, long long& tot, karta e) {
	if (lop[e.grad].empty()) {
		lop[e.grad].insert(e.cena);
		brpuni++;
		totl += e.cena;
	} else {
		tot -= *lop[e.grad].begin();
		lop[e.grad].insert(e.cena);
		tot += *lop[e.grad].begin();
	}
}

void izbaci(multiset<int>* lop, int& brpuni, long long& tot, karta e) {
	tot -= *lop[e.grad].begin();
	lop[e.grad].erase(lop[e.grad].find(e.cena));
	if (lop[e.grad].empty()) {
		brpuni--;
	} else {
		tot += *lop[e.grad].begin();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		a[i].cena = c;
		a[i].vreme = d;
		if (f == 0) {
			a[i].smer = -1;
			a[i].grad = t;
		} else {
			a[i].smer = 1;
			a[i].grad = f;
		}
	}

	sort(a+1, a+m+1);

	for (int i=1; i<=m; i++) {
		if (a[i].smer == -1) {
			dodaj(lor, punir, totr, a[i]);
		}
	}

	long long sol = 1e18;

	int r = 1;
	for (int i=1; i<=m; i++) {
		while (r <= m && a[r].vreme <= a[i].vreme + k) {
			if (a[r].smer == -1) {
				izbaci(lor, punir, totr, a[r]);
			}
			r++;
		}
		if (a[i].smer == 1) {
			dodaj(lol, punil, totl, a[i]);
		}
		if (punil == n && punir == n) {
			sol = min(sol, totl + totr);
		}
	}

	if (sol > 9e17) {
		sol = -1;
	}

	cout << sol;	
}