#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;

string greedy_finish(const string& s, string p, int pos, const int* mapa, bitset<26> slobodno) {
	int mapa2[26];
	copy(mapa, mapa+k, mapa2);
	for (int i=pos+1; i<n; i++) {
		int& x = mapa2[(int)s[i]];
		if (x != -1) {
			p[i] = x;
		} else {
			for (int j=k-1; j>=0; j--) {
				if (slobodno[j]) {
					x = p[i] = j;
					slobodno[j] = 0;
					break;
				}
			}
		}
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> k;
		string s, a, b, p;
		cin >> s >> a >> b;
		n = a.size();
		p = s;
		for (int i=0; i<n; i++) {
			s[i] -= 'a';
			a[i] -= 'a';
			b[i] -= 'a';
		}

		bitset<26> slobodno(0);
		for (int i=0; i<k; i++)
			slobodno[i] = 1;
		
		int mapa[26];
		for (int i=0; i<k; i++)
			mapa[i] = -1;

		int br = 0, preskocio = 0;

		for (int i=0; i<n; i++) {

			// cerr << "status " << i << ' ' << br << ' ';
			// for (int i=0; i<k; i++)
			// 	cerr << mapa[i] << ' ';
			// cerr << '\n';

			int& x = mapa[(int)s[i]];
			if (x != -1) {
				p[i] = x;
				if (!preskocio && x < a[i]) {
					br = 1;
					break;
				} else if (!preskocio && x > a[i]) {
					preskocio = 1;
				}
			} else {
				if (preskocio) {
					// ako sam vec preskocio samo uzmi najmanju slobodnu
					for (int j=0; j<k; j++)
						if (slobodno[j]) {
							p[i] = x = j;
							slobodno[j] = 0;
							break;
						}
				} else {
					// probaj da stavis a[i] ako je slobodno
					int uspelo = 0;
					if (slobodno[(int)a[i]]) {
						p[i] = x = a[i];
						slobodno[x] = 0;
						string tmp = greedy_finish(s, p, i, mapa, slobodno);
						slobodno[x] = 1;
						x = -1;
						if (tmp >= a) {
							uspelo = 1;
							p[i] = x = a[i];
							slobodno[x] = 0;
						}
					}

					// ako to nije uspelo probaj nesto vece
					if (!uspelo) {
						int ok = 0;
						for (int j=a[i]+1; j<k; j++)
							if (slobodno[j]) {
								slobodno[j] = 0;
								p[i] = x = j;
								ok = 1;
								preskocio = 1;
								break;
							}
						if (!ok)
							br = 1;
					}
				}
			}
		}

		// for (int i=0; i<n; i++)
		// 	cerr << (char)(p[i] + 'a');
		// cerr << '\n';

		if (p < a || p > b)
			br = 1;

		if (br) {
			cout << "NO\n";
		} else {
			cout << "YES\n";

			for (int i=0; i<k; i++)
				if (mapa[i] == -1) {
					for (int j=0; j<k; j++)
						if (slobodno[j]) {
							mapa[i] = j;
							slobodno[j] = 0;
							break;
						}
				}

			for (int i=0; i<k; i++)
				cout << (char)(mapa[i] + 'a');
			cout << '\n';
		}
	}
}