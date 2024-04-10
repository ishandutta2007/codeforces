#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct vec {
	int x, y, id;
	// ovo je ok jer nije previse osetljivo
	bool operator< (const vec& b) const {
		return atan2(y, x) < atan2(b.y, b.x);
	}
	int norm2() {
		return x*x + y*y;
	}
	int sp(vec b) {
		return x * b.x + y * b.y;
	}
};

struct bignum {
	ll a[10];

	bignum(ll x = 0) {
		fill(a, a+10, 0);
		a[0] = x;
		sredi();
	}

	bignum operator* (bignum b) const {
		bignum tmp;
		for (int i=0; i<10; i++)
			for (int j=0; i+j<10; j++)
				tmp.a[i+j] += a[i] * b.a[j];
		tmp.sredi();
		return tmp;
	}

	void sredi() {
		for (int i=0; i<9; i++) {
			a[i+1] += a[i] / 123123123;
			a[i] %= 123123123;
		}
	}

	bool operator< (const bignum& b) const {
		for (int i=9; i>=0; i--)
			if (a[i] != b.a[i])
				return a[i] < b.a[i];
		return false;
	}
};

struct cos_ugao {
	int sgn;
	bignum p, q;
	bool operator< (cos_ugao b) const {
		if (sgn != b.sgn)
			return sgn < b.sgn;
		if (sgn == 1)
			return p * b.q < b.p * q;
		else
			return b.p * q < p * b.q;
	}
};

vec a[100005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cos_ugao best;
	best.sgn = -1;
	best.p = 4;
	best.q = 1;
	cin >> n;
	for (int i=0; i<n; i++) {
		a[i].id = i+1;
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a+n);
	a[n] = a[0];
	int p = 0;
	for (int i=0; i<n; i++) {
		cos_ugao ugao;
		ugao.sgn = a[i].sp(a[i+1]) < 0 ? -1 : 1;
		ugao.p = bignum(1);
		ugao.p = ugao.p * a[i].sp(a[i+1]);
		ugao.p = ugao.p * a[i].sp(a[i+1]);
		ugao.q = bignum(1);
		ugao.q = ugao.q * a[i].norm2();
		ugao.q = ugao.q * a[i+1].norm2();
		if (best < ugao) {
			best = ugao;
			p = i;
		}
	}
	cout << a[p].id << ' ' << a[p+1].id << '\n';
}