#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 123123123;

struct mat {
	int a[6][6];

	mat() {
		for (int i=0; i<6; i++)
			for (int j=0; j<6; j++)
				a[i][j] = i == j ? 0 : inf;
	}

	mat(nullptr_t) {
		for (int i=0; i<6; i++)
			for (int j=0; j<6; j++)
				a[i][j] = inf;
	}

	const int* operator[] (int x) const { return a[x]; }
	int* operator[] (int x) { return a[x]; }

	mat operator+ (const mat& b) const {
		mat t(nullptr);
		for (int i=0; i<6; i++) {
			for (int j=i; j<6; j++) {
				int& x = t[i][j];
				for (int k=i; k<=j; k++)
					x = min(x, a[i][k] + b[k][j]);
			}
		}
		return t;
	}
};

int n, q;
mat baza[10];
string s;

void init() {
	baza[2][0][0] = 1;
	baza[2][0][1] = 0;

	baza[0][1][1] = 1;
	baza[0][1][2] = 0;

	baza[1][2][2] = 1;
	baza[1][2][3] = 0;

	baza[7][3][3] = 1;
	baza[7][3][4] = 0;

	baza[6][3][3] = 1;
	baza[6][4][4] = 1;
	baza[6][3][5] = 0;
	baza[6][4][5] = 0;
}

template<int MAXN>
struct segtree {
	mat a[2*MAXN];

	void init(string s) {
		for (int i=1; i<=(int)s.size(); i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = baza[s[i-1] - '0'];
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	mat get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return mat();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}
};

segtree<262144> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init();
	cin >> n >> q >> s;
	drvo.init(s);
	for (int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;
		auto z = drvo.get(l, r);
		int u = z[0][4];
		if (u > 3213211)
			u = -1;
		cout << u << '\n';
	}
}