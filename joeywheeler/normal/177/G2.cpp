#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

typedef long long ll;

struct Matrix {
	const static int N = 4;
	int n, m;
	ll v[N][N];

	void init(int _n, int _m) {
		n = _n; m = _m;
		FO(i,0,n) FO(j,0,m) v[i][j] = 0;
	}

	void init(int _n) {
		init(_n,_n);
	}

	void ident() {
		FO(i,0,n) FO(j,0,n) v[i][j] = 0;
		FO(i,0,n) v[i][i] = 1;
	}

	Matrix operator*(const Matrix &o) const {
		assert(m == o.n);

		Matrix res; res.init(n,o.m);
		ll mod2 = MOD*1ll*MOD;
		FO(i,0,n) FO(j,0,o.m) {
			FO(k,0,m) {
				res.v[i][j] += v[i][k] * o.v[k][j];
				if (res.v[i][j] >= mod2) res.v[i][j] -= mod2;
			}
			res.v[i][j] %= MOD;
		}

		return res;
	}

	Matrix operator^(long long k) {
		Matrix res; res.init(n); res.ident();
		Matrix a = *this;
		while (k) {
			if (k&1) res = res*a;
			a = a*a;
			k /= 2;
		}
		return res;
	}
};



ll k;

int sl[100005];
char s[100005];
int n;

int tre[100005][2];
int trc[100005][2];
bool as[2];

int ne[100005], nc[100005];

int go() {
	n = int(strlen(s));

	sl[0] = 0;
	FO(i,1,n+1) {
		int v = s[i-1] - 'a', j;
		for (j = sl[i-1]; j && s[j] != 'a'+v; j = sl[j]);
		if (j+1 != i && s[j] == 'a'+v) sl[i] = j+1;
		else sl[i] = 0;
	}

	FO(i,0,n) {
		int v = s[i] - 'a';
		if (i == n-1) {
			tre[i][v] = sl[n];
			trc[i][v] = 1;
		} else {
			tre[i][v] = i+1;
			trc[i][v] = 0;
		}

		v = !v;
		trc[i][v] = 0;
		if (i == 0) {
			tre[i][v] = 0;
		} else {
			tre[i][v] = tre[sl[i]][v];
		}
	}
	FO(i,0,2) as[i] = false;

	FO(i,2,k+1) {
		as[i&1] = true;
		FO(j,0,n) {
			ne[j] = tre[tre[j][~i&1]][i&1];
			if (j && ne[j] != ne[j-1]) as[i&1] = false;
		}
		FO(j,0,n) {
			nc[j] = trc[j][~i&1] + trc[tre[j][~i&1]][i&1];
			if (nc[j] >= MOD) nc[j] -= MOD;
		}
		FO(j,0,n) tre[j][i&1] = ne[j];
		FO(j,0,n) trc[j][i&1] = nc[j];

		if (as[0] && as[1]) {
#define idx(k,i) (k*2+i)
			int a = tre[0][~i&1];
			int b = tre[0][i&1];
			Matrix m1; m1.init(4);
			FO(j,0,2) m1.v[idx(0,j)][idx(1,j)] = 1;
			FO(j,0,2) m1.v[idx(1,j)][idx(1,j)] = 1, m1.v[idx(1,j)][idx(0,1)] = 1;
			Matrix m2; m2.init(4);
			FO(j,0,2) m2.v[idx(0,j)][idx(1,j)] = 1;
			FO(j,0,2) m2.v[idx(1,j)][idx(1,j)] = 1, m2.v[idx(1,j)][idx(0,0)] = 1;

			Matrix t = (m2*m1)^((k-i)/2);
			if ((k-i)&1) t = m1 * t;

			Matrix im; im.init(4,1);
			FO(j,0,2) {
				im.v[idx(j,0)][0] = trc[a][(i&1)^j^1];
				im.v[idx(j,1)][0] = trc[b][(i&1)^j^1];
			}

			im = t * im;

			return (trc[0][i&1] + im.v[idx(1,0)][0] - trc[a][i&1] + MOD) % MOD;
		}
	}

	return trc[0][k&1];
}

int main() {
	int m;
	scanf("%lld%d", &k, &m); k--;
	FO(Z,0,m) {
		scanf(" %s", s);
		printf("%d\n", go());
	}
}