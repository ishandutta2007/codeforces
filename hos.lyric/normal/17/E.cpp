//	Codeforces Beta Round #17
//	Problem E

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

int palindrome(char t[], int r[]) {
	int nn = strlen(t) << 1;
	int i, j, k;
	for (i = j = 0; i < nn; i += k, j = max(j - k, 0)) {
		for (; 0 <= i - j && i + j + 1 < nn && t[i - j >> 1] == t[i + j + 1 >> 1]; ++j);
		r[i] = j;
		for (k = 1; 0 <= i - k && 0 <= j - k && r[i - k] != j - k; ++k) {
			r[i + k] = min(r[i - k], j - k);
		}
	}
	return nn;
}

const Int MO = 51123987;

int N, NN;
char S[2000010];
int R[4000010];
int lef[4000010];
int rig[4000010];

int main() {
	int i;
	
	scanf("%d%s", &N, S);
	NN = palindrome(S, R);
	
	for (i = 0; i < NN; ++i) {
		++lef[max(i - R[i], 0)];
		--lef[i + 1];
		++rig[i];
		--rig[i + R[i]];
	}
	partial_sum(lef, lef + NN, lef);
	partial_sum(rig, rig + NN, rig);
//pv(R,R+NN);pv(lef,lef+NN);pv(rig,rig+NN);
	
	Int all = 0;
	Int ans = 0;
	Int sum = 0;
	
	for (i = 0; i < NN; ++i) {
		all += (R[i] + 1) / 2;
		all %= MO;
	}
	for (i = N; i--; ) {
		ans += rig[i << 1] * sum;
		ans %= MO;
		sum += lef[i << 1];
		sum %= MO;
	}
	ans = all * (all - 1) / 2 - ans;
	ans %= MO;
	ans += MO;
	ans %= MO;
	cout << ans << endl;
	
	
	return 0;
}