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

int n;
int a[505];

vector<int> kompatibilni(int n) {
	vector<int> z;

	int i = 1;

	// dodajemo sve brojeve do korena
	for (i=1; i*i<=n; i++) {
		z.push_back(i);
	}

	i--;

	for (int j=i; j > 0; j--) {
		if (n % j == 0) {
			int x = n / j;
			if (x > 1) {
				z.push_back(x - 1);
			}
			z.push_back(x);
		} else {
			z.push_back(n / j);
		}
	}

	// za kraj, dodati x = n+1

	// sortiramo i izbacimo duplikate
	sort(z.begin(), z.end());
	z.resize(unique(z.begin(), z.end()) - z.begin());

	/*
	for (int x : z) {
		cerr << x << ' ';
	}
	cerr << '\n';
	*/
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	// u nizu "dobri" cuvam presek svih skupova do sada.
	// init mi je flag kojim postavljam pocetnu vrednost za
	// ovaj skup
	vector<int> dobri;
	bool init = false;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		vector<int> t = kompatibilni(a[i]);

		if (!init) {
			dobri = t;
			init = true;
		} else {
			vector<int> t2;
			set_intersection(
				t.begin(), t.end(),
				dobri.begin(), dobri.end(),
				back_inserter(t2)
			);
			dobri = t2;
		}
	}

	// ovo je ok jer je 1 uvek u skupu

	int x = *dobri.rbegin();
	long long sol = 0;

	for (int i=1; i<=n; i++) {
		// vidi koje je bolje predstavljanje za x
		// ako je a[i] deljivo sa x+1, bolje da napisem a[i]
		// kao (x+1) + (x+1) + ... jer ima manje elemenata.

		// u suprotnom, pokusam da iskoristim broj (x+1) sto vise
		// puta u predstavljanju.

		// a[i] = u*x + v*(x+1)
		// a[i] = -u (mod x+1)

		if (a[i] % (x+1) == 0) {
			sol += a[i] / (x+1); 
		} else {
			int u = (x+1) - a[i] % (x+1);
			int v = (a[i] - u*x) / (x+1);

			sol += u + v;
		}
	}

	cerr << "x: " << x << '\n';
	cout << sol;

}