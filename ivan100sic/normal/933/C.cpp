#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;

int n;
int x[3], y[3], r[3];
cd p[3];

int kv(int x) {
	return x*x;
}

ld kv(ld x) {
	return x*x;
}

bool sek(int i, int j) {
	int d2 = kv(x[i]-x[j]) + kv(y[i]-y[j]);
	return d2 < kv(r[i]+r[j]) && d2 > kv(r[i]-r[j]);
}

bool dodir(int i, int j) {
	int d2 = kv(x[i]-x[j]) + kv(y[i]-y[j]);
	return d2 == kv(r[i]+r[j]) || d2 == kv(r[i]-r[j]);
}

basic_string<cd> tacke[3], sve;

bool cmp(cd a, cd b) {
	if (a.real() != b.real())
		return a.real() < b.real();
	return a.imag() < b.imag();
}

void junikuj(basic_string<cd>& a) {
	if (a.size() == 0)
		return;
	basic_string<cd> b;
	for (auto p : a) {
		bool found = false;
		for (auto q : b) {
			if (abs(p-q) < 1e-8)
				found = true;
		}
		if (!found)
			b += p;
	}
	swap(a, b);
}

int nadji(basic_string<cd>& a, cd b) {
	for (int i=0; i<(int)a.size(); i++) {
		if (abs(a[i] - b) < 1e-8)
			return i;
	}
	return -1;
}

pair<cd, cd> preseci(int i, int j) {
	ld d2 = kv(x[i]-x[j]) + kv(y[i]-y[j]);
	ld d = sqrt(d2);
	ld a = (kv(r[i]) - kv(r[j]) + d2) / (2 * d);
	ld h = sqrt(kv(r[i]) - a*a);
	cd p2 = p[i] + a*(p[j] - p[i]) / d;
	cd dir2 = cd(0, 1) * (p[j] - p[i]);
	cd p3 = p2 + h*dir2 / d;
	cd p4 = p2 - h*dir2 / d;
	return {p3, p4};
}

cd dodirni(int i, int j) {
	ll d2 = kv(x[i]-x[j]) + kv(y[i]-y[j]);
	if (d2 == kv(r[i]+r[j])) {
		return (p[i] * (ld)r[j] + p[j] * (ld)r[i]) / (ld)(r[i] + r[j]);
	} else {
		return (p[i] * (ld)r[j] - p[j] * (ld)r[i]) / (ld)(r[j] - r[i]);
	}
}

bool oncircle(int i, cd x) {
	return abs(abs(x - p[i]) - r[i]) < 1e-8;
}

bool vis[321];
basic_string<int> e[321];

void dfs(int x) {
	vis[x] = 1;
	for (int y : e[x])
		if (!vis[y])
			dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i] >> r[i];
		p[i] = {(ld)x[i], (ld)y[i]};
	}

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (sek(i, j)) {
				auto [u, v] = preseci(i, j);
				// cerr << "par " << i << ' ' << j << " ima " << u << ' ' << v << '\n';
				sve += {u, v};
			} else if (dodir(i, j)) {
				auto p = dodirni(i, j);
				cerr << "dodir " << p << '\n';
				sve += p;
			}
		}
	}

	for (int i=0; i<n; i++) {
		cd u = {(ld)x[i], (ld)y[i]+r[i]};
		cd v = {(ld)x[i], (ld)y[i]-r[i]};
		sve += {u, v};
	}

	junikuj(sve);

	for (auto p : sve)
		cerr << p << '\n';

	int edges = 0;

	for (int i=0; i<n; i++) {
		basic_string<int> w;
		for (int j=0; j<(int)sve.size(); j++)
			if (oncircle(i, sve[j]))
				w += j;

		for (int x : w) {
			cerr << " " << x << '\n';
			for (int y : w) {
				e[x] += y;
			}
		}
		cerr << "~\n";
		edges += w.size();
	}

	int cc = 0;

	for (int i=0; i<(int)sve.size(); i++) {
		if (!vis[i]) {
			cc++;
			dfs(i);
		}
	}
	
	cerr << "cc: " << cc << '\n';
	cerr << "edges: " << edges << '\n';
	cerr << "verts: " << sve.size() << '\n';

	cout << 1 + cc + edges - (int)sve.size();
}