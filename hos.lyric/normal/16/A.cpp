//	Codeforces Beta Round #16
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

int M, N;
string S[110];
char buf[110];

bool solve() {
	int i;
	
	M = in();
	N = in();
	for (i = 0; i < M; ++i) {
		scanf("%s", buf);
		S[i] = buf;
	}
	for (i = 0; i < M; ++i) {
		if (S[i] != string(N, S[i][0])) return 0;
	}
	for (i = 1; i < M; ++i) {
		if (S[i - 1] == S[i]) return 0;
	}
	
	return 1;
}

int main() {
	
	
	puts(solve() ? "YES" : "NO");
	
	return 0;
}