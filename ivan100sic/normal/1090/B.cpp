#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<string> textrefs;
	vector<pair<string, string>> bib;

	map<string, int> tr_red;
	map<string, string> bibicu_vezbaj_za_icpc_world_finals_nabijem_te_na_elfak;

	int state = 0;

	while (1) {
		string s;
		getline(cin, s);
		if (state == 0) {
			// proveri da li smo procitali pocetak biba
			if (s == "\\begin{thebibliography}{99}") {
				state = 1;
				continue;
			} else {
				// parsuj, nadji citate
				int n = s.size();
				for (int i=0; i<n; i++) {
					if (s.substr(i, 6) == "\\cite{") {
						// nadji zatvorenu zagradu
						int j = i+6;
						while (s[j] != '}')
							j++;
						textrefs.push_back(s.substr(i+6, j-i-6));
					}
				}
			}
		} else if (state == 1) {
			// proveri da li smo zavrsili
			if (s == "\\end{thebibliography}") {
				break;
			} else {
				// dodaj bibu
				int x = 0;
				while (s[x] != '}')
					x++;
				string a = s.substr(9, x-9);
				string b = s.substr(x+1);
				bib.push_back({a, b});
				bibicu_vezbaj_za_icpc_world_finals_nabijem_te_na_elfak[a] = b;
			}
		}
	}

	// proveri redosled
	for (int i=0; i<(int)textrefs.size(); i++)
		tr_red[textrefs[i]] = i;

	bool valja = true;

	for (int i=0; i<(int)bib.size(); i++) {
		if (tr_red[bib[i].first] != i) {
			valja = false;
		}
	}

	if (valja) {
		cout << "Correct\n";
		return 0;
	}

	cout << "Incorrect\n";
	cout << "\\begin{thebibliography}{99}\n";

	for (int i=0; i<(int)textrefs.size(); i++) {
		cout << "\\bibitem{" << textrefs[i] << "}" <<
			bibicu_vezbaj_za_icpc_world_finals_nabijem_te_na_elfak[textrefs[i]] << '\n';
	}

	cout << "\\end{thebibliography}\n";
}