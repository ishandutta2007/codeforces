//	Codeforces Beta Round #6
//	Problem D

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
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
	int x = 0, c;
	for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
	do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
	return x;
}

void chmin(int &t, int f) { if (t > f) t = f; }

const int INF = 1001001001;

int N, A, B;
int H[20];
int mem[15][20][20];

int calc(int i, int x, int y) {
	int &hos = mem[i][x][y];
	if (!~hos) {
		hos = INF;
		if (i == N - 1) {
			if (!x && !y) hos = 0;
		} else {
			int k, z = H[i + 1];
			for (k = 0; ; ++k) {
				if (!x) chmin(hos, k + calc(i + 1, y, z));
				if (!x && !y && !z) break;
				x -= B; if (x < 0) x = 0;
				y -= A; if (y < 0) y = 0;
				z -= B; if (z < 0) z = 0;
			}
		}
	}
	return hos;
}

int main() {
	int i, x, y, tmp, k, z;
	int ou = 0;
	
	N = in();
	A = in();
	B = in();
	for (i = 0; i < N; ++i) {
		H[i] = in() + 1;
	}
	memset(mem, ~0, sizeof(mem));
	int res = calc(1, H[0], H[1]);
	printf("%d\n", res);
	for (i = 1, x = H[0], y = H[1]; i < N - 1; ++i) {
		tmp = calc(i, x, y);
		z = H[i + 1];
		for (k = 0; ; ++k) {
			if (!x) if (tmp == k + calc(i + 1, y, z)) break;
			if (ou++) putchar(' ');
			printf("%d", i + 1);
			x -= B; if (x < 0) x = 0;
			y -= A; if (y < 0) y = 0;
			z -= B; if (z < 0) z = 0;
		}
		x = y;
		y = z;
	}
	puts("");
	
	return 0;
}