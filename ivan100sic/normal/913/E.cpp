#include <bits/stdc++.h>
using namespace std;

struct izraz {
	int tip; // 0 - primary, 1 - andexpr, 2 - orexpr
	string repr;
	int tabela;
};

const int MAXLEN = 28;

string dp[MAXLEN+1][3][256];

void stavi(string& a, const string& b) {
	if (a.size() == 0 || a.size() > b.size() || (a.size() == b.size() && a > b)) {
		a = b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	dp[1][0][0b00001111] = "x";
	dp[1][0][0b00110011] = "y";
	dp[1][0][0b01010101] = "z";

	for (int i=2; i<=MAXLEN; i++) {
		cerr << "i " << i << '\n';
		// not izrazi
		for (int mask=0; mask<256; mask++) {
			if (dp[i-1][0][mask].size()) {
				
				stavi(dp[i][0][mask ^ 255], string("!") + dp[i-1][0][mask]);
			}

			if (i > 3 && dp[i-3][1][mask].size()) {
				stavi(dp[i][0][mask ^ 255], string("!(") + dp[i-3][1][mask] + ")");
			}

			if (i > 3 && dp[i-3][2][mask].size()) {
				stavi(dp[i][0][mask ^ 255], string("!(") + dp[i-3][2][mask] + ")");
			}
		}

		// and izrazi bez zagrada
		for (int j=1; j<i; j++) {
			int k = i-1-j;
			if (k < 0) {
				continue;
			}

			for (int lt=0; lt<2; lt++) {
				for (int rt=0; rt<2; rt++) {

					for (int lmask=0; lmask<256; lmask++) {
						for (int rmask=0; rmask<256; rmask++) {

							string& ls = dp[j][lt][lmask];
							string& rs = dp[k][rt][rmask];

							if (ls.size() == 0 || rs.size() == 0) {
								continue;
							}

							string& ss = dp[i][1][lmask & rmask];

							stavi(ss, ls + "&" + rs);
						}
					}
				}
			}
		}

		// and izrazi sa zagradom levo
		for (int j=1; j<i; j++) {
			int k = i-3-j;
			if (k < 0) {
				continue;
			}

			int lt = 2; {
				for (int rt=0; rt<2; rt++) {

					for (int lmask=0; lmask<256; lmask++) {
						for (int rmask=0; rmask<256; rmask++) {

							string& ls = dp[j][lt][lmask];
							string& rs = dp[k][rt][rmask];

							if (ls.size() == 0 || rs.size() == 0) {
								continue;
							}

							string& ss = dp[i][1][lmask & rmask];

							stavi(ss, string("(") + ls + ")&" + rs);
						}
					}
				}
			}
		}

		// and izrazi sa zagradom desno
		for (int j=1; j<i; j++) {
			int k = i-3-j;
			if (k < 0) {
				continue;
			}

			for (int lt=0; lt<2; lt++) {
				int rt = 2; {

					for (int lmask=0; lmask<256; lmask++) {
						for (int rmask=0; rmask<256; rmask++) {

							string& ls = dp[j][lt][lmask];
							string& rs = dp[k][rt][rmask];

							if (ls.size() == 0 || rs.size() == 0) {
								continue;
							}

							string& ss = dp[i][1][lmask & rmask];

							stavi(ss, ls + "&(" + rs + ")");
						}
					}
				}
			}
		}

		// and izrazi sa obe zagrade
		for (int j=1; j<i; j++) {
			int k = i-5-j;
			if (k < 0) {
				continue;
			}

			int lt = 2; {
				int rt = 2; {

					for (int lmask=0; lmask<256; lmask++) {
						for (int rmask=0; rmask<256; rmask++) {

							string& ls = dp[j][lt][lmask];
							string& rs = dp[k][rt][rmask];

							if (ls.size() == 0 || rs.size() == 0) {
								continue;
							}

							string& ss = dp[i][1][lmask & rmask];

							stavi(ss, string("(") + ls + ")&(" + rs + ")");
						}
					}
				}
			}
		}

		// or izrazi
		for (int j=1; j<=i-2; j++) {
			int k = i-1-j;

			for (int lt=0; lt<3; lt++) {
				for (int rt=0; rt<3; rt++) {

					for (int lmask=0; lmask<256; lmask++) {
						for (int rmask=0; rmask<256; rmask++) {

							string& ls = dp[j][lt][lmask];
							string& rs = dp[k][rt][rmask];

							if (ls.size() == 0 || rs.size() == 0) {
								continue;
							}

							string& ss = dp[i][2][lmask | rmask];

							stavi(ss, ls + "|" + rs);
						}
					}
				}
			}
		}
	}

	string sol[256];

	for (int i=0; i<256; i++) {

		sol[i] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA";

		for (int j=1; j<=MAXLEN; j++) {
			if (dp[j][0][i].size()) stavi(sol[i], dp[j][0][i]);
			if (dp[j][1][i].size()) stavi(sol[i], dp[j][1][i]);
			if (dp[j][2][i].size()) stavi(sol[i], dp[j][2][i]);
		}

		if (sol[i] == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaA") {
			cerr << "bad!\n";
		}

		cerr << sol[i] << '\n';
	}

	// return 0;

	int t;
	cin >> t;
	while (t--) {
		string x;
		cin >> x;
		int m = 0;
		for (char v : x) {
			m = 2*m + (v - '0');
		}

		cout << sol[m] << '\n';
	}

}