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
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const char CS[] = "AHIMOTUVWXY";
bool is[1010];

int N;
char S[100010];

bool solve() {
	N = strlen(S);
	for (int i = 0; i < N; ++i) {
		if (!is[S[i] - 0]) {
			return false;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (S[i] != S[N - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	
	
	for (int i = 0; CS[i]; ++i) {
		is[CS[i] - 0] = true;
	}
	
	for (; ~scanf("%s", S); ) {
		puts(solve() ? "YES" : "NO");
	}
	
	return 0;
}