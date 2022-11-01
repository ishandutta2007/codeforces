#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct Matrix {
	const static int n = 150;
	bitset<n> v[n];

	void ident() {
		FO(i,0,n) FO(j,0,n) v[i][j] = 0;
		FO(i,0,n) v[i][i] = 1;
	}

	Matrix tp() const {
		Matrix res;
		FO(i,0,n) FO(j,0,n) res.v[j][i] = v[i][j];
		return res;
	}

	Matrix operator*(const Matrix &o) const {
		Matrix res;
		Matrix tmp = o.tp();
		FO(i,0,n) FO(j,0,n) {
			res.v[i][j] = (v[i]&tmp.v[j]).any();
		}

		return res;
	}

	Matrix operator^(long long k) {
		Matrix res; res.ident();
		Matrix a = *this;
		while (k) {
			if (k&1) res = res*a;
			a = a*a;
			k /= 2;
		}
		return res;
	}
};

int n, m;
tuple<int,int,int> e[151];

Matrix pos;
Matrix adj;

int main() {
	scanf("%d%d", &n, &m);
	FO(i,0,m) {
		int x,y,d; scanf("%d%d%d", &x, &y, &d); x--; y--;
		e[i] = make_tuple(d,x,y);
	}
	e[m++] = make_tuple(1.1e9,n-1,n-1);
	adj.v[n-1][n-1] = 1;
	pos.ident();
	sort(e,e+m);
	int lt = 0;
	FO(i,0,m) {
		int d,x,y; tie(d,x,y) = e[i];
		Matrix nps = pos * (adj^(d-lt));
		if (nps.v[0][n-1]) {
			int s = lt, e = d, b = d;
			while (s <= e) {
				int md = (s+e)/2;
				if ((pos * (adj^(md-lt))).v[0][n-1]) {
					b = md;
					e = md-1;
				} else s = md+1;
			}
			printf("%d\n", b);
			return 0;
		}
		pos = nps;
		adj.v[x][y] = 1;
		lt = d;
	}
	printf("Impossible\n");
}