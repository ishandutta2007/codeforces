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

int n, m;

long long spec_c[1005][1005][26];
long long dist[1005][1005][26];
// long long smrad[1005][1005][26];

auto smrad = dist;

long long sols[300005];

struct pic {
	int a, b, c, d, e;
};

int k;
pic a[300005];
string b[1005];

int fr[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;

	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		b[i] = string(" ") + s;
	}

	for (int i=1; i<=k; i++) {
		string s;
		cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d >> s;
		a[i].e = s[0] - 'a';

		fr[a[i].e]++;
	}

	// spec & dist

	for (int i=1; i<=k; i++) {
		spec_c[a[i].a  ][a[i].b  ][a[i].e]++;
		spec_c[a[i].a  ][a[i].d+1][a[i].e]--;
		spec_c[a[i].c+1][a[i].b  ][a[i].e]--;
		spec_c[a[i].c+1][a[i].d+1][a[i].e]++;
	}

	// u ovom trenutku je spec seedovan

	for (int x=0; x<26; x++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				spec_c[i][j][x] += spec_c[i-1][j][x] + spec_c[i][j-1][x]
					- spec_c[i-1][j-1][x];
			}
		}
	}

	// uradili smo prefix, sada je spec realan, mozemo da ga iskoristimo za dist

	// SMRAD

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int nije = k - accumulate(spec_c[i][j], spec_c[i][j]+26, 0ll);

			for (int x=0; x<26; x++) {
				smrad[i][j][x] = nije * abs(x + 97 - (int)b[i][j]);
				smrad[i][j][x] += smrad[i-1][j][x] + smrad[i][j-1][x] - smrad[i-1][j-1][x];
			}
		}
	}

	// bla bla truc

	for (int i=1; i<=k; i++) {
		long long t1 = 0, t2 = 0, t3 = 0, t;

		t3 = (
				+ smrad[a[i].c  ][a[i].d  ][a[i].e]
				- smrad[a[i].a-1][a[i].d  ][a[i].e]
				- smrad[a[i].c  ][a[i].b-1][a[i].e]
				+ smrad[a[i].a-1][a[i].b-1][a[i].e]

			);

		// cerr << t1 << ' ' << t2 << ' ' << t3 << '\n';

		sols[i] = t3;
	}

	// DIST

	for (int x=0; x<26; x++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				dist[i][j][x] = spec_c[i][j][x] * abs(x + 97 - (int)b[i][j]);
				dist[i][j][x] += dist[i-1][j][x] + dist[i][j-1][x] - dist[i-1][j-1][x];
			}
		}
	}

	for (int x=0; x<26; x++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				spec_c[i][j][x] += spec_c[i-1][j][x] + spec_c[i][j-1][x]
					- spec_c[i-1][j-1][x];
			}
		}
	}

	// e sada su i dist i spec z-ovani

	// cerr << "pazi " << dist[3][3][2] << '\n';

	// solve

	for (int i=1; i<=k; i++) {
		long long t1 = 0, t2 = 0, t3 = 0, t;

		for (int x=0; x<26; x++) {
			t1 += dist[n][m][x]
				- dist[a[i].c  ][a[i].d  ][x]
				+ dist[a[i].a-1][a[i].d  ][x]
				+ dist[a[i].c  ][a[i].b-1][x]
				- dist[a[i].a-1][a[i].b-1][x];

			// safe multiplication

			t2 += abs(x-a[i].e) * (
				+ spec_c[a[i].c  ][a[i].d  ][x]
				- spec_c[a[i].a-1][a[i].d  ][x]
				- spec_c[a[i].c  ][a[i].b-1][x]
				+ spec_c[a[i].a-1][a[i].b-1][x]

				);
		}

		t3 = (
				+ smrad[a[i].c  ][a[i].d  ][a[i].e]
				- smrad[a[i].a-1][a[i].d  ][a[i].e]
				- smrad[a[i].c  ][a[i].b-1][a[i].e]
				+ smrad[a[i].a-1][a[i].b-1][a[i].e]

			);

		// cerr << t1 << ' ' << t2 << ' ' << t3 << '\n';

		sols[i] += t1+t2;
	}

	cout << *min_element(sols+1, sols+k+1);


}