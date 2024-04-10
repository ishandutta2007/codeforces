#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int b[262144];

void fclear() {
	memset(b, 0, sizeof(b));
}

void fadd(int x, int y) {
	x++;
	while (x < 262144) {
		b[x] += y;
		x += x & -x;
	}
}

int fsum(int x) {
	x++;
	int y = 0;
	while (x > 0) {
		y += b[x];
		x -= x & -x;
	}
	return y;
}

int fsearch(int y) {
	int x = 0;
	for (int j=131072; j>=1; j>>=1) {
		if (b[x+j] <= y) {
			y -= b[x+j];
			x += j;
		}
	}
	return x;
}

int n;
int p[200005], q[200005], r[200005];
int pt[200005], qt[200005], rt[200005];

void deconstruct(int* p, int* t) {
	fclear();
	for (int i=0; i<n; i++)
		fadd(i, 1);
	for (int i=0; i<n; i++) {
		fadd(p[i], -1);
		t[i] = fsum(p[i]);
	}
}

void construct(int* t, int* p) {
	fclear();
	for (int i=0; i<n; i++)
		fadd(i, 1);
	for (int i=0; i<n; i++) {
		p[i] = fsearch(t[i]);
		fadd(p[i], -1);
	}
}

void test() {
	n = 4;
	int a[4] = {0, 2, 0, 0};
	int b[4];
	construct(a, b);
	for (int i=0; i<4; i++)
		cerr << b[i] << " \n"[i == 3];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// test();
	// return 0;

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> p[i];
	for (int i=0; i<n; i++)
		cin >> q[i];

	deconstruct(p, pt);
	deconstruct(q, qt);
	for (int i=0; i<n; i++)
		rt[i] = pt[i] + qt[i];
	for (int i=n-1; i>=0; i--) {
		if (i)
			rt[i-1] += rt[i] / (n-i);
		rt[i] %= n-i;
	}
	construct(rt, r);
	for (int i=0; i<n; i++)
		cout << r[i] << " \n"[i == n-1];
}