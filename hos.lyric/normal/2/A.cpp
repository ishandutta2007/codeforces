//	Codeforces Beta Round #2
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

char buf[1010];
int N, M;
int A[1010], P[1010];
string S[1010];
map<string,int> tr;
int s[1010], t[1010];

int main() {
	int i, j;
	int dai = -INF;
	
	N = in();
	for (i = 0; i < N; ++i) {
		scanf("%s%d", buf, &P[i]);
		if (!tr.count(buf)) {
			tr[S[M] = buf] = M++;
		}
		A[i] = tr[buf];
	}
	
	for (i = 0; i < N; ++i) {
		s[A[i]] += P[i];
	}
	for (j = 0; j < M; ++j) {
		if (dai < s[j]) dai = s[j];
	}
	for (i = 0; i < N; ++i) {
		t[A[i]] += P[i];
		if (s[A[i]] == dai && t[A[i]] >= dai) {
			cout << S[A[i]] << endl;
			return 0;
		}
	}
	
	return 0;
}