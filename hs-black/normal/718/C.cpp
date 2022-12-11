#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int P = 1e9+7;
const int N = 105000;
template <typename T>
void read(T &x) {
	x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if (f) x=-x;
}

struct Matrix {
	int n, m;
	ll f[3][3];
	Matrix(int x = 0,int y = 0) {
		memset(f, 0, sizeof(f));
		n = x, m = y;
	}
	Matrix operator * (Matrix a) {
		Matrix tmp(n, a.m); 
		for (int i = 1;i <= tmp.n; i++) 
			for (int j = 1;j <= tmp.m; j++) 
				for (int k = 1;k <= m; k++) 
					tmp.f[i][j] = (tmp.f[i][j] + f[i][k] * a.f[k][j]) % P;
		return tmp;
	}
	Matrix operator + (Matrix a) {
		Matrix tmp(n, m);
		for (int i = 1;i <= n; i++) 
			for (int j = 1;j <= m; j++) 
				tmp.f[i][j] = (f[i][j] + a.f[i][j]) % P;
		return tmp;
	}
};
int n, m;

struct node {
	Matrix mat, add;
	int l, r;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define mat(x) tree[x].mat
	#define add(x) tree[x].add
}tree[N<<2];

Matrix I(2, 2), e(2, 2), t(1, 2), c(2, 2);

Matrix fpw(Matrix di,ll mi) {
	Matrix ans = I;
	while (mi) {
		if (mi & 1) ans = ans * di;
		di = di * di;
		mi >>= 1;
	}
	return ans;
}
	
int a[N], tag[N<<2];

#define p1 p << 1
#define p2 p << 1 | 1

void spread(int p) {
	if (tag[p]) {
		mat(p1) = mat(p1) * add(p);
		mat(p2) = mat(p2) * add(p);
		add(p1) = add(p1) * add(p);
		add(p2) = add(p2) * add(p);
		tag[p1] = tag[p2] = 1;
		add(p) = I, tag[p] = 0;
	}
}


void build(int l,int r,int p) {
	l(p) = l, r(p) = r;
	mat(p).n = 1, mat(p).m = 2;
	add(p) = I;
	if (l == r) {
		mat(p) = t * fpw(e, a[l] - 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p1);
	build(mid + 1, r, p2);
	mat(p) = mat(p1) + mat(p2);
}

void change(int l,int r,int p,Matrix x) {
	if (l <= l(p) && r(p) <= r) {
		add(p) = add(p) * x;
		mat(p) = mat(p) * x;
		tag[p] = 1;
		return;
	}
	spread(p);
	if (r(p1) >= l) change(l, r, p1, x);
	if (l(p2) <= r) change(l, r, p2, x);
	mat(p) = mat(p1) + mat(p2);
}

node query(int l,int r,int p) {
	if (l <= l(p) && r(p) <= r) return tree[p];
	spread(p);
	if (r(p1) < l) return query(l, r, p2);
	if (l(p2) > r) return query(l, r, p1);
	node tmp; tmp.mat.n = 1, tmp.mat.m = 2;
	tmp.mat = query(l, r, p1).mat + query(l, r, p2).mat;
	return tmp;
}

int main() {
	read(n), read(m);
	I.f[1][1] = I.f[2][2] = 1;
	e.f[1][1] = e.f[1][2] = e.f[2][1] = 1;
	t.f[1][1] = 1;
	for (int i = 1;i <= n; i++) read(a[i]);
	build(1, n, 1);
	for (int i = 1;i <= m; i++) {
		int opt, l, r, x;
		read(opt), read(l), read(r);
		if (opt == 1) {
			read(x); 
			change(l, r, 1, fpw(e, x));
		}
		else printf ("%lld\n", query(l, r, 1).mat.f[1][1]);
	}
	return 0;
}

/*
6 2
2 2 2 2 1 1
1 1 4 2
2 1 1

*/