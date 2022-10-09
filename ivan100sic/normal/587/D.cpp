#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int u, v, c, t;
};

int n, m;
basic_string<int> e[50005];
int fr[50005];
edge a[50005];

basic_string<int> f[300005];

int kontra(int x) {
	if (x < m)
		return x + m;
	else
		return x - m;
}

void add_edge(int x, int y) {
	f[x] += y;
}

vector<pair<int, int>> twins;

int idx[300005], low[300005], t, br, cc[300005];
bool inst[300005];
basic_string<int> st, rtopo;

void scc(int x) {
	idx[x] = low[x] = ++t;
	inst[x] = 1;
	st += x;
	for (int y : f[x]) {
		if (idx[y] == 0) {
			scc(y);
			low[x] = min(low[x], low[y]);
		} else if (inst[y]) {
			low[x] = min(low[x], idx[y]);
		}
	}
	if (idx[x] == low[x]) {
		br++;
		while (1) {
			int z = st.back();
			st.pop_back();
			cc[z] = br;
			rtopo += z;
			inst[z] = false;
			if (z == x)
				break;
		}
	}
}

bool probaj(int gr, bool stampaj = false) {
	for (int i=0; i<6*m; i++) {
		f[i] = {};
		idx[i] = low[i] = cc[i] = 0;
	}
	t = br = 0;
	rtopo = {};

	// restrikcija = ako kod nekog cvora ima dve grane iste boje,
	// jedna od njih mora biti uzeta
	for (auto [i, j] : twins) {
		add_edge(kontra(i), j);
		add_edge(kontra(j), i);
	}

	// mecing uslov
	for (int x=1; x<=n; x++) {
		for (int i=0; i<(int)e[x].size(); i++) {
			// ako uzmem i ne smem da uzmem prefis i sufiks
			// povezi ove prefiks/sufiks cvorove sa ostatkom grafa
			if (i > 0) {
				add_edge(e[x][i], fr[x] + (i-1) + 2*m);
				add_edge(fr[x] + (i) + 2*m, fr[x] + (i-1) + 2*m);
			}
			if (i < (int)e[x].size() - 1) {
				add_edge(e[x][i], fr[x] + (i+1) + 4*m);
				add_edge(fr[x] + (i) + 4*m, fr[x] + (i+1) + 4*m);
			}
			add_edge(fr[x] + (i) + 2*m, kontra(e[x][i]));
			add_edge(fr[x] + (i) + 4*m, kontra(e[x][i]));
		}
	}

	// sve debele grane mrsh
	for (int i=0; i<m; i++) {
		if (a[i].t > gr) {
			add_edge(i, kontra(i));
		}
	}

	// udri
	for (int i=0; i<6*m; i++)
		if (!idx[i])
			scc(i);

	for (int i=0; i<m; i++)
		if (cc[i] == cc[kontra(i)])
			return false;

	if (stampaj) {
		cout << "Yes\n";
		string val(2*m, false);
		for (int x : rtopo) {
			if (x < 2*m) {
				if (!val[kontra(x)])
					val[x] = 1;
			}
		}
		int z = 0;
		for (int i=0; i<m; i++)
			if (val[i])
				z++;
		cout << gr << ' ' << z << '\n';
		for (int i=0; i<m; i++)
			if (val[i])
				cout << i+1 << ' ';
		cout << '\n';
	}

	return true;
}

void no() {
	cout << "No\n";
	exit(0);
}

void find_twins() {
	for (int x=1; x<=n; x++) {
		map<int, int> sz, cl;
		for (int i : e[x]) {
			int t = sz[a[i].c]++;
			if (t == 2) {
				no();
			} else if (t == 1) {
				twins.emplace_back(i, cl[a[i].c]);
			} else {
				cl[a[i].c] = i;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].c >> a[i].t;
		e[a[i].u] += i;
		e[a[i].v] += i;
	}
	
	find_twins();

	for (int i=1; i<=n; i++) {
		fr[i+1] = fr[i] + e[i].size();
	}

	int l = 0, r = 1.01e9, o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (probaj(m)) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (o != -1) {
		probaj(o, true);
	} else {
		cout << "No\n";
	}
}