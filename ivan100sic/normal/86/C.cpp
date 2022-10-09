#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct aho {
	struct node {
		map<char, int> nx, go;
		bool kraj;
		int link, dub, rec;
		node() : nx(), go(), kraj(false), link(-1), dub(0), rec(0) {}
	};

	vector<node> v;

	aho() : v(1) {}

	void dodaj(const string& s) {
		int t = 0, dub = 0;
		for (char x : s) {
			if (v[t].nx.count(x)) {
				t = v[t].nx[x];
			} else {
				t = v[t].nx[x] = v.size();
				v.emplace_back();
			}
			v[t].dub = ++dub;
		}
		v[t].kraj = true;
	}

	void zavrsi() {
		basic_string<int> q = {0};
		size_t qs = 0;
		while (qs != q.size()) {
			int x = q[qs++];
			for (auto [c, y] : v[x].nx) {
				int z = v[x].link;
				while (z != -1 && !v[z].nx.count(c))
					z = v[z].link;

				if (z == -1)
					v[y].link = 0;
				else
					v[y].link = v[z].nx[c];

				q += y;
			}
		}

		for (auto& p : v)
			p.go = p.nx;

		// reverse(q.begin(), q.end());
		// q.pop_back();
		for (int x : q) {
			if (!x)
				continue;
			v[x].rec = v[v[x].link].rec;
			if (v[x].kraj)
				v[x].rec = v[x].dub;
		}
	}

	int go(int x, char c) {
		if (v[x].go.count(c))
			return v[x].go[c];
		if (v[x].link == -1)
			return v[x].go[c] = 0;
		return v[x].go[c] = go(v[x].link, c);
	}
};

int n, m;
string a[11];
int d[1005][111][13];

const int mod = 1'000'000'009;

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	aho corasick; // i love this
	for (int i=0; i<m; i++) {
		cin >> a[i];
		corasick.dodaj(a[i]);
	}
	corasick.zavrsi();

	d[0][0][0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<(int)corasick.v.size(); j++) {
			for (int k=0; k<=11; k++) {
				for (char x : {'A', 'C', 'G', 'T'}) {
					int jj = corasick.go(j, x);
					int kk = corasick.v[jj].rec <= k ? k+1 : 0;
					ad(d[i+1][jj][kk], d[i][j][k]);
				}
			}
		}
	}

	// cerr << corasick.go(0, 'T') << '\n';
	// cerr << corasick.v[1].kraj << '\n';
	// cerr << corasick.v[1].rec << '\n';
	// cerr << d[1][1][0] << '\n';
	// cerr << d[2][1][1] << '\n';

	int sol = 0;
	for (int j=0; j<(int)corasick.v.size(); j++) {
		for (int k=0; k<=corasick.v[j].rec; k++) {
			ad(sol, d[n][j][k]);
		}

		// for (int k=0; k<=11; k++) {
		// 	cerr << j << ' ' << k << ' ' << d[n][j][k] << '\n';
		// }
	}

	cout << sol << '\n';
}