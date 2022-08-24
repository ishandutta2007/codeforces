//	Codeforces Beta Round #17
//	Problem B

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

int N, M;
int Q[1010];
int sho[1010];

int main() {
	int i, u, v;
	int c;
	
	N = in();
	for (u = 0; u < N; ++u) {
		Q[u] = in();
	}
	memset(sho, 0x3f, sizeof(sho));
	M = in();
	for (i = 0; i < M; ++i) {
		u = in() - 1;
		v = in() - 1;
		c = in();
		if (sho[v] > c) sho[v] = c;
	}
	
	int um = max_element(Q, Q + N) - Q;
	int ans = 0;
	for (u = 0; u < N; ++u) if (u != um) {
		if (sho[u] >= INF) {
			ans = -1;
			break;
		}
		ans += sho[u];
	}
	cout << ans << endl;
	
	return 0;
}