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

int N, M, A, B;
int T[110];

bool solve() {
	const int a = *min_element(T, T + M);
	const int b = *max_element(T, T + M);
	if (!(A <= a && b <= B)) {
		return false;
	}
	multiset<int> s(T, T + M);
	if (!s.count(A)) s.insert(A);
	if (!s.count(B)) s.insert(B);
	return ((int)s.size() <= N);
}

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		M = in();
		A = in();
		B = in();
		for (i = 0; i < M; ++i) {
			T[i] = in();
		}
		puts(solve() ? "Correct" : "Incorrect");
	}
	
	return 0;
}