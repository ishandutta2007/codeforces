#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[15][15], b[15][15], f[15][15];
basic_string<int> e[15];
int cc[15], k;

void postavi8(vector<string>& v, int x, int y, char c) {
	for (int i=x-1; i<=x+1; i++)
		for (int j=y-1; j<=y+1; j++) {
			if (i == x && j == y)
				continue;
			v[i][j] = c;
		}
}

void stampaj(vector<string>& v) {
	for (string& s : v)
		cout << s << '\n';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// ucitavanje

	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> a[i][j];

	// tranzitivno zatvaranje

	for (int i=1; i<=n; i++)
		a[i][i] = 1;

	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				a[i][j] |= a[i][k] && a[k][j];

	// trazenje SCC

	for (int i=1; i<=n; i++) {
		if (cc[i] == 0) {
			k++;
			for (int j=1; j<=n; j++)
				if (a[i][j] && a[j][i])
					cc[j] = k;
		}
	}

	// prenos grana u B-graf SCC-ova

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (a[i][j])
				b[cc[i]][cc[j]] = 1;
		}
	}

	// ukloni lupove
	for (int i=1; i<=k; i++)
		b[i][i] = 0;

	// toposort
	vector<int> ts, indeg(k+1, 0);
	for (int i=1; i<=k; i++) {
		for (int j=1; j<=k; j++) {
			if (b[i][j])
				indeg[j]++;
		}
	}

	queue<int> q;

	for (int i=1; i<=k; i++)
		if (indeg[i] == 0)
			q.push(i);

	while (q.size()) {
		int x = q.front(); q.pop();
		ts.push_back(x);
		for (int i=1; i<=k; i++)
			if (b[x][i]) {
				indeg[i]--;
				if (indeg[i] == 0)
					q.push(i);
			}
	}

	cerr <<"ts\n";
	for (int x : ts)
		cerr << x << ' ';
	cerr << '\n';

	// prenos grana u F-graf (topoloski sortirani)

	for (int i=0; i<k; i++) {
		int x = ts[i];
		for (int j=1; j<=n; j++) {
			if (cc[j] == x)
				e[i+1] += j;
		}
	}

	for (int i=0; i<k; i++) {
		for (int j=0; j<k; j++) {
			int x = ts[i];
			int y = ts[j];
			f[i+1][j+1] = b[x][y];
		}
	}

	cout << "75 75 " << 3*k+2 << '\n';

	vector<string> beton(75, string(75, '#'));
	for (int i=1; i<=k; i++)
		for (int j=1; j<=k; j++)
			beton[4+4*i][4+4*j] = '.';

	vector<string> ograda(75, string(75, '.'));
	for (int i=1; i<=k; i++) {
		for (int j=i+1; j<=k; j++) {
			postavi8(ograda, 4+4*i, 4+4*j, '#');
		}
	}

	for (int i=1; i<=k; i++) {
		for (int j=1; j<=k; j++)
			cerr << f[i][j];
		cerr << '\n';
	}
	for (int i=1; i<=k; i++) {
		for (int x : e[i])
			cerr << x << ' ';
		cerr << '\n';
	}

	for (int i=1; i<=k; i++) {
		// prvi sloj, beton
		// popuni rupe gde treba
		auto bt = beton;
		auto og = ograda;

		for (int j=1; j<i; j++)
			if (f[j][i]) {
				bt[4+4*j][4+4*i] = '#';
				postavi8(og, 4+4*j, 4+4*i, '.');
			}

		// skloni ogradu gde treba
		for (int j=i+1; j<=k; j++)
			if (f[i][j]) {
				postavi8(og, 4+4*i, 4+4*j, '.');
			}

		auto og2 = og;
		// naredjaj cifre
		for (int j=0; j<(int)e[i].size(); j++)
			og[0][j] = e[i][j] + '0';

		stampaj(og2);
		stampaj(og);
		stampaj(bt);
	}

	// zadnja dva sloja su E N D L E S S   V O I D
	for (int i=0; i<2; i++) {
		for (int i=0; i<75; i++)
			cout << string(75, '.') << '\n';
		cout << '\n';
	}
}