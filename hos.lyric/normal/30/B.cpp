//	Codeforces Beta Round #30
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

const int Q = 1000;
int DAYS[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, };

int A[10], B[10];

bool validDate() {
	if (!(1 <= B[1] && B[1] <= 12)) return 0;
	int days = DAYS[B[1]];
	if (B[0] % 4 == 0 && B[1] == 2) days = 29;
	if (!(1 <= B[2] && B[2] <= days)) return 0;
	return 1;
}

int main() {
	
	
	A[2] = in(); A[1] = in(); A[0] = in();
	B[2] = in(); B[1] = in(); B[0] = in();
	
	sort(B, B + 3);
	do {
		if (validDate()) {
			if ((A[0] * Q + A[1]) * Q + A[2] >= ((B[0] + 18) * Q + B[1]) * Q + B[2]) {
				puts("YES");
				return 0;
			}
		}
	} while (next_permutation(B, B + 3));
	
	puts("NO");
	
	return 0;
}