//	Codeforces Beta Round #24
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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

int M, N;
int X, Y;
double E[1010];
double dg[1010], sb[1010], sp[1010];

int main() {
	int x, y;
	double r;
	
	M = in();
	N = in();
	X = in();
	Y = in();
	
	if (N == 1) {
		printf("%.8f\n", (M - X) * 2.0);
		return 0;
	}
	
	for (x = M; x > X; --x) {
		for (y = 1; y <= N; ++y) {
			E[y] += (y == 1 || y == N) ? 3 : 4;
			dg[y] = (y == 1 || y == N) ? 2 : 3;
			sb[y] = sp[y] = -1;
		}
		for (y = 1; y < N; ++y) {
			r = sb[y] / dg[y];
			dg[y + 1] -= sp[y] * r;
			E[y + 1] -= E[y] * r;
		}
		for (y = N; y >= 1; --y) {
			E[y] = (E[y] - E[y + 1] * sp[y]) / dg[y];
		}
	}
	
	printf("%.8f\n", E[Y]);
	
	
	return 0;
}