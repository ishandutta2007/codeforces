#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];

int d[200005];

void bfs(int x) {
	queue<int> q;
	fill(d+1, d+n+1, 1123123123);
	d[x] = 0;
	q.push(x);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (d[y] == 1123123123) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}

int p[200005];
bool blok[200005];

int najdublji;

void dfs(int x, int parent) {
	if (najdublji == -1 || d[x] > d[najdublji])
		najdublji = x;
	p[x] = parent;
	for (int y : e[x]) {
		if (blok[y])
			continue;
		if (y != parent) {
			d[y] = d[x] + 1;
			dfs(y, x);
		}
	}
}

void dfs2(int x, int parent, vector<int>& v, int radijus) {
	for (int y : e[x])
		if (y != parent)
			dfs2(y, x, v, radijus-1);

	if (e[x].size() >= 3 && radijus == 0)
		v.push_back(x);
}

struct blokce {
	int x1, d1, x2, d2;

	int sd() const {
		return d1 + d2;
	}

	bool operator< (const blokce& other) const {
		return sd() > other.sd();
	}
};

blokce racva_sol[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	basic_string<int> racve;
	for (int i=1; i<=n; i++)
		if (e[i].size() >= 3)
			racve += i;

	int r0 = racve[0];
	bfs(r0);
	int r1 = r0;
	for (int x : racve)
		if (d[x] > d[r1])
			r1 = x;
	int r2 = r1;
	bfs(r1);
	for (int x : racve)
		if (d[x] > d[r2])
			r2 = x;
	// r1 - r2 je resenje, uradi dfs

	d[r1] = 0;
	dfs(r1, r1);

	int c1 = -1, c2 = -1;

	int diam = d[r2];
	if (diam % 2 == 0) {
		int x = r2;
		for (int i=0; i<diam/2; i++)
			x = p[x];
		c1 = c2 = x;
	} else {
		int x = r2;
		for (int i=0; i<diam/2; i++)
			x = p[x];
		c1 = x;
		c2 = p[x];
	}

	int radijus = diam / 2;

	vector<vector<int>> klasteri;

	if (c1 == c2) {
		for (int y : e[c1]) {
			vector<int> v;
			dfs2(y, c1, v, radijus-1);
			if (v.size())
				klasteri.push_back(v);
		}
	} else {
		vector<int> v;
		dfs2(c1, c2, v, radijus);
		if (v.size())
			klasteri.push_back(v);
		v = {};
		dfs2(c2, c1, v, radijus);
		if (v.size())
			klasteri.push_back(v);
	}

	// odredi blokirane cvorove

	d[c1] = 0;
	dfs(c1, c1);

	/*
	for (auto v : klasteri) {
		for (int x : v) {
			cerr << x << ' ';
		}
		cerr << " je klaster\n";
	}
	*/

	for (auto v : klasteri) {
		for (int x : v) {
			for (int y = x; y != c1; y = p[y]) {
				if (blok[y])
					break;
				blok[y] = true;
			}
		}
	}
	blok[c1] = true;

	/*
	for (int i=1; i<=n; i++)
		cerr << (int)blok[i] << ' ';
	cerr << " su blok\n";
	*/

	// resi svaki
	for (auto v : klasteri) {
		for (int x : v) {
			int naj1 = -1, naj2 = -1;
			for (int y : e[x]) {
				if (!blok[y]) {
					najdublji = -1;
					d[y] = 0;
					dfs(y, x);
					if (naj1 == -1 || d[najdublji] > d[naj1]) {
						naj2 = naj1;
						naj1 = najdublji;
					} else if (naj2 == -1 || d[najdublji] > d[naj2]) {
						naj2 = najdublji;
					}
				}
			}

			// cerr << x << ' ' << naj1 << ' ' << naj2 << "\n";

			racva_sol[x] = {naj1, d[naj1], naj2, d[naj2]};
		}
	}

	// sklopi u globalno resenje
	// basically uzmi max iz svakog klastera pa najveca dva po zbiru
	vector<blokce> klaster_maks;
	for (auto v : klasteri) {
		blokce naj = {-1, -1, -1, -1};
		for (int x : v) {
			if (racva_sol[x].sd() > naj.sd())
				naj = racva_sol[x];
		}
		klaster_maks.push_back(naj);
	}

	sort(klaster_maks.begin(), klaster_maks.end());

	cout << klaster_maks[0].x1 << ' ' << klaster_maks[1].x1 << '\n';
	cout << klaster_maks[0].x2 << ' ' << klaster_maks[1].x2 << '\n';
}