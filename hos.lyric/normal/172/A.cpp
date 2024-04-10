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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, L;
char S[110];
int as[110];

int main() {
	int i, j;
	
	for (; ~scanf("%d", &N); ) {
		memset(as, 0, sizeof(as));
		for (i = 0; i < N; ++i) {
			scanf("%s", S);
			L = strlen(S);
			for (j = 0; j < L; ++j) {
				if (!as[j]) as[j] = S[j];
				if (as[j] != S[j]) as[j] = -1;
			}
		}
		for (j = 0; j < L; ++j) {
			if (as[j] == -1) break;
		}
		printf("%d\n", j);
	}
	
	return 0;
}