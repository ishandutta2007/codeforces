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

char CS[10][10] = {
	"baaa", 
	"abaa", 
	"aaba", 
	"aaab", 
	"bbaa", 
	"baba", 
	"baab", 
};

int A[10][10] = {
	{ 1, 1, 0, 0, 0, 1, 1, }, 
	{ 1, 0, 1, 0, 1, 0, 1, }, 
	{ 1, 0, 0, 1, 1, 1, 0, }, 
	{ 0, 1, 1, 0, 1, 1, 0, }, 
	{ 0, 1, 0, 1, 1, 0, 1, }, 
	{ 0, 0, 1, 1, 0, 1, 1, }, 
};
int C[10][10] = {
	{ 1, 1, 0, -1, 0, 0, }, 
	{ 1, 0, -1, 0, 1, 0, }, 
	{ 0, 1, -1, 0, 0, 1, }, 
	{ 0, 0, 0, -1, 1, 1, }, 
	{ -1, 0, 1, 1, 0, -1, }, 
	{ 0, -1, 1, 1, -1, 0, }, 
};
int B[10];

int main() {
	int i, j, u, k;
	int b[10];
	int xm[10], x[10];
	int opt, tmp;
	
	for (; ; ) {
		for (i = 0; i < 6; ++i) {
			if (!~scanf("%d", &B[i])) {
				break;
			}
		}
		if (i < 6) break;
		opt = -1;
		for (x[6] = 0; x[6] <= 100000; ++x[6]) {
			for (i = 0; i < 6; ++i) {
				b[i] = B[i] - A[i][6] * x[6];
			}
			for (j = 0; j < 6; ++j) {
				x[j] = 0;
				for (i = 0; i < 6; ++i) {
					x[j] += C[j][i] * b[i];
				}
			}
			for (j = 0; j < 6; ++j) {
				if (x[j] % 2 != 0) goto failed;
				x[j] /= 2;
				if (x[j] < 0) goto failed;
			}
			for (i = 0; i < 6; ++i) {
				int tmpB = 0;
				for (j = 0; j < 7; ++j) {
					tmpB += A[i][j] * x[j];
				}
				assert(tmpB == B[i]);
			}
			tmp = 0;
			for (j = 0; j < 7; ++j) {
				tmp += x[j];
			}
			if (opt == -1 || opt > tmp) {
				opt = tmp;
				memcpy(xm, x, sizeof(x));
			}
		failed:;
		}
		printf("%d\n", opt);
		if (opt >= 0) {
			for (u = 0; u < 4; ++u) {
				for (j = 0; j < 7; ++j) {
					for (k = 0; k < xm[j]; ++k) {
						putchar(CS[j][u]);
					}
				}
				puts("");
			}
		}
	}
	
	return 0;
}