//	Codeforces Beta Round #76

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int SZ = 22;
const Int MO = 1000000007;

struct Matrix {
	Int a[30][30];
	Matrix() {
		memset(a, 0, sizeof(a));
	}
};
Matrix operator+(const Matrix &x, const Matrix &y) {
	Matrix ret;
	int i, j;
	for (i = 0; i < SZ; ++i) for (j = 0; j < SZ; ++j) {
		ret.a[i][j] = (x.a[i][j] + y.a[i][j]) % MO;
	}
	return ret;
}
Matrix operator*(const Matrix &x, const Matrix &y) {
	Matrix ret;
	int i, j, k;
	for (i = 0; i < SZ; ++i) for (k = 0; k < SZ; ++k) for (j = 0; j < SZ; ++j) {
		(ret.a[i][j] += x.a[i][k] * y.a[k][j]) %= MO;
	}
	return ret;
}

#define _(x,y) ((x) * 5 + (y))
#define START 20
#define END 21

Matrix I, A;

Int calc(Int e) {
	Matrix a = A, b = I;
	for (; e; e >>= 1, a = a * a) if (e & 1) b = b * a;
	return b.a[END][START];
}

int L, R;

int main() {
	int i, j;
	int x, y, z;
	int l, r;
	
	for (i = 0; i < SZ; ++i) {
		I.a[i][i] = 1;
	}
	for (x = 0; x < 4; ++x) for (y = 0; y < 4; ++y) for (z = 0; z <= 4; ++z) {
		if (x / 2 == y / 2) continue;
		if (y / 2 == z / 2) continue;
		if (x == 2 && y == 0 && z == 3) continue;
		if (x == 3 && y == 0 && z == 2) continue;
		i = _(x, y);
		j = _(y, z);
		A.a[i][j] = 1;
	}
	for (x = 0; x < 4; ++x) {
		i = _(x, 4);
		A.a[i][START] = 1;
	}
	for (y = 0; y < 4; ++y) for (z = 0; z <= 4; ++z) {
		if (y / 2 == z / 2) continue;
		j = _(y, z);
		A.a[END][j] = 1;
	}
	A.a[END][END] = 1;
	
	for (; ~scanf("%d%d", &L, &R); ) {
		Int ans = 0;
		
		//	
		ans += calc(R + 1);
		ans -= calc(L);
		
		/*
		//	even
		l = (L + 1) / 2;
		r = R / 2;
		if (l <= r) {
			ans += calc(r + 1);
			ans -= calc(l);
		}
		*/
		
		//	odd
		l = (L + 2) / 2;
		r = (R + 1) / 2;
		if (l <= r) {
			ans += calc(r + 1);
			ans -= calc(l);
		}
		
		for (; ans % 2 != 0; ans += MO);
		ans /= 2;
		
		ans %= MO;
		ans += MO;
		ans %= MO;
		cout << ans << endl;
	}
//for(int n=1;n<=5;++n)cout<<"calc("<<n<<") = "<<calc(n)<<endl;
	
	return 0;
}