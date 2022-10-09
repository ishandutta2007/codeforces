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

bool obrisah_nulu;

void ans(string s) {
	if (s == "-1" && obrisah_nulu) {
		s = "0";
	}
	cout << s;
	exit(0);
}

void solve(string s, int rem = -1) {

	// izracunaj ostatak

	if (rem == -1) {
		rem = 0;
		for (char x : s) {
			rem = (rem + x) % 3;
		}
	}

	// ako je ostatak 0 onda samo odstampamo taj brojs

	if (rem == 0) {
		ans(s);
	}

	// od sad na dalje ostatak nije 0. Sada ako je velicina broja 1
	// onda ne mozemo nista.

	if (s.size() == 1) {
		ans("-1");
	}

	// Od sad na dalje je resenje bar 1

	// Trazimo cifru rem negde osim na prvom mestu. Ako je nadjemo
	// super, odstampamo resenje
	for (int i=1; i<s.size(); i++) {
		if (s[i] % 3 == rem) {
			s.erase(i, 1);
			ans(s);
		}
	}

	// Sada proverimo da li je ok da samo obrisemo prvu cifru
	// Ako ih ima bar tri onda druga ne sme da bude 0
	if (s.size() > 2) {
		if (s[0] % 3 == rem && s[1] != '0') {
			s.erase(0, 1);
			ans(s);
		}
	}

	// Ako ih ima tacno 2 onda druga sme da bude i 0, 3, 6, 9
	if (s.size() == 2) {
		if (s[0] % 3 == rem) {
			s.erase(0, 1);
			ans(s);
		}
	}

	// Od sad na dalje, moramo da brisemo vise od 1 cifre
	// probajmo da resimo bez brisanja prve cifre
	// ako hocemo da nadjemo resenje gde ne brisemo inicijalnu cifru
	// a koristimo dve, onda te dve moraju da budu 3-rem

	vector<int> poss;
	for (int i=1; i<s.size(); i++) {
		if (s[i] % 3 == 3-rem) {
			poss.push_back(i);
		}
	}

	// ako smo nasli bar dve super
	if (poss.size() >= 2) {
		s.erase(poss[1], 1);
		s.erase(poss[0], 1);
		ans(s);
	}

	// sada vise nemam izbora, moram da obrisem prvu cifru

	// primetimo da postoje bar dve cifre
	// moram da obrisem prvi karakter i sve naredne nule
	{
		// samo njega i neke naredne nule
		int j = 1;
		while (j < s.size() && s[j] == '0') {
			j++;
			obrisah_nulu = true;
		}
		if (j == s.size()) {
			// do kraja broja su nule
			// ostavljamo tu nulu na kraju
			ans("0");
		} else {
			// cerr << "brate j " << j << '\n';
			s.erase(0, j);
			solve(s);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	int n;

	cin >> s;
	solve(s);
}