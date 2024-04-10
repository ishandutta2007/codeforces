//	Codeforces Beta Round #10
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

const int INF = 1001001001;

int M, N;
int A[510], B[510];
int dp[510], prev[510][510];
int len, ans[510];

int main() {
	int i, j, jm, k;
	
	M = in();
	for (i = 1; i <= M; ++i) {
		A[i] = in();
	}
	N = in();
	for (j = 1; j <= N; ++j) {
		B[j] = in();
	}
	A[++M] = B[++N] = INF;
	
	memset(prev, ~0, sizeof(prev));
	for (i = 1; i <= M; ++i) {
		for (jm = 0, j = 1; j <= N; ++j) {
			if (A[i] > B[j] && dp[jm] < dp[j]) {
				jm = j;
			}
			if (A[i] == B[j] && dp[j] < dp[jm] + 1) {
				dp[j] = dp[jm] + 1;
				prev[i][j] = jm;
			}
		}
	}
	
	len = dp[N] - 1;
	for (k = len, i = M, j = N; j = prev[i][j]; ) {
		ans[--k] = B[j];
		for (--i; A[i] != B[j] || !~prev[i][j]; --i);
	}
	printf("%d\n", len);
	for (k = 0; k < len; ++k) {
		if (k) putchar(' ');
		printf("%d", ans[k]);
	}
	puts("");
	
	return 0;
}