//	Codeforces Beta Round #77

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
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

#define MAX 100020

int sig(int x) { return (x < 0) ? -1 : (x > 0) ? +1 : 0; }

int M, N;
char SS[MAX], *S;
char T[MAX];

int pos[8][MAX], val[8][MAX];

bool greaterThan74() {
	int i;
	for (i = 0; i < N / 2; ++i) {
		if (S[i] - '0' > 7) return 1;
		if (S[i] - '0' < 7) return 0;
	}
	for (i = N / 2; i < N; ++i) {
		if (S[i] - '0' > 4) return 1;
		if (S[i] - '0' < 4) return 0;
	}
	return 0;
}

int main() {
	int g;
	int i;
	
	for (; S = SS, ~scanf("%s", S); ) {
		N = strlen(S);
		if (N % 2 != 0) ++N, *--S = '0';
		if (greaterThan74()) ++N, *--S = '0';
		if (N % 2 != 0) ++N, *--S = '0';
//cout<<"S = "<<S<<" : ";
		
		for (g = 4; g <= 7; ++g) {
			pos[g][N] = N;
			val[g][N] = 0;
			for (i = N; i--; ) {
				if (S[i] - '0' != g) {
					pos[g][i] = i;
					val[g][i] = S[i] - '0';
				} else {
					pos[g][i] = pos[g][i + 1];
					val[g][i] = val[g][i + 1];
				}
			}
		}
		
		int flg = 0;
		int a4, a7;
		a4 = a7 = N / 2;
		for (i = 0; i < N; ++i) {
			if (!a4) {
				T[i] = '7';
			} else if (!a7) {
				T[i] = '4';
			} else {
				if (flg) {
					T[i] = '4';
				} else {
					//	check 4
					int cmp = 0;
					if (pos[4][i] < i + 1) {
						cmp += sig(4 - val[4][i]) * 1000000;
					}
					if (pos[7][i + 1] < i + 1 + a7) {
						cmp += sig(7 - val[7][i + 1]) * 1000;
					}
					if (pos[4][i + 1 + a7] < N) {
						cmp += sig(4 - val[4][i + 1 + a7]) * 1;
					}
					if (cmp >= 0) {
						T[i] = '4';
					} else {
						T[i] = '7';
					}
				}
			}
			if (S[i] - '0' < T[i] - '0') {
				flg = 1;
			}
			if (T[i] == '4') {
				--a4;
			} else {
				--a7;
			}
		}
		T[N] = 0;
		puts(T);
		
	}
	
	return 0;
}