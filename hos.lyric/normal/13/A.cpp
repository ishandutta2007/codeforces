//	Codeforces Beta Round #13
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

int digsum(int a, int b) {
	return a ? (a % b + digsum(a / b, b)) : 0;
}

int A;

int main() {
	int nmr, den;
	
	A = in();
	nmr = 0;
	den = A - 2;
	for (int b = 2; b <= A - 1; ++b) {
		nmr += digsum(A, b);
	}
	
	int g = __gcd(nmr, den);
	nmr /= g;
	den /= g;
	printf("%d/%d\n", nmr, den);
	
	return 0;
}