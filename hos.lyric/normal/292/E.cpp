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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

uint xrand() {
	static uint x = 314159265, y = 358979323, z = 846264338, w = 327950288;
	uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}
const int MAX = 15000010;
int n, l[MAX], r[MAX], size[MAX];
int val[MAX];
int node(int _l, int _r, int _val) {
	assert(n < MAX);
	n[l] = _l;
	n[r] = _r;
	n[size] = (~n[l] ? n[l][size] : 0) + 1 + (~n[r] ? n[r][size] : 0);
	n[val] = _val;
	return n++;
}
int merge(int a, int b) {
	if (!~a) return b;
	if (!~b) return a;
	if ((int)(xrand() % (a[size] + b[size])) < a[size]) {
		return node(a[l], merge(a[r], b), a[val]);
	} else {
		return node(merge(a, b[l]), b[r], b[val]);
	}
}
int splitL, splitR;
void split(int a, int sz) {
	if (!~a) {
		splitL = splitR = -1;
		return;
	}
	int sizeL = ~a[l] ? a[l][size] : 0;
	if (sz <= sizeL) {
		split(a[l], sz);
		splitR = node(splitR, a[r], a[val]);
	} else {
		split(a[r], sz - sizeL - 1);
		splitL = node(a[l], splitL, a[val]);
	}
}

int get(int a, int k) {
	int sizeL = (~a[l] ? a[l][size] : 0);
	if (k < sizeL) {
		return get(a[l], k);
	} else if (k == sizeL) {
		return a[val];
	} else {
		return get(a[r], k - sizeL - 1);
	}
}

int N, qry;
int A[100010], B[100010];

int build(int *s, int *t) {
	if (t - s == 1) {
		return node(-1, -1, *s);
	} else {
		int *u = s + (t - s) / 2;
		return merge(build(s, u), build(u, t));
	}
}

int main() {
	int i;
	
	N = in();
	qry = in();
	for (i = 0; i < N; ++i) {
		A[i] = in();
	}
	for (i = 0; i < N; ++i) {
		B[i] = in();
	}
	
	int a = build(A, A + N);
	int b = build(B, B + N);
	
	for (; qry--; ) {
		int typ = in();
		switch (typ) {
			case 1: {
				int x = in() - 1;
				int y = in() - 1;
				int k = in();
				split(a, x);
				split(splitR, k);
				int copy = splitL;
				split(b, y);
				int saveL = splitL;
				split(splitR, k);
				b = merge(merge(saveL, copy), splitR);
			} break;
			case 2: {
				int x = in() - 1;
				int res = get(b, x);
				printf("%d\n", res);
			} break;
			default: assert(0);
		}
	}
cerr<<"n = "<<n<<endl;
	
	return 0;
}