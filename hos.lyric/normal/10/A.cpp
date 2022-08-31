//	Codeforces Beta Round #10
//	Problem A

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

int N;
int P, Q, R, S, T;
int A[110], B[110];

int main() {
	int i, t;
	
	N = in();
	P = in();
	Q = in();
	R = in();
	S = in();
	T = in();
	for (i = 0; i < N; ++i) {
		A[i] = in();
		B[i] = in();
	}
	
	int ans = 0;
	
	for (i = 0; i < N; ++i) {
		ans += P * (B[i] - A[i]);
	}
	for (i = 0; i < N - 1; ++i) {
		for (t = 0; t < A[i + 1] - B[i]; ++t) {
			if (t < S) {
				ans += P;
			} else if (t < S + T) {
				ans += Q;
			} else {
				ans += R;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}