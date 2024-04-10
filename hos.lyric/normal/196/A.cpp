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

#define MAXN 100010

int N;
char S[MAXN];
char tails[MAXN];
int ansLen;
char ans[MAXN];

int main() {
	int i;
	
	for (; ~scanf("%s", S); ) {
		N = strlen(S);
		tails[N] = 0;
		for (i = N; i--; ) {
			tails[i] = max(S[i], tails[i + 1]);
		}
		ansLen = 0;
		for (i = 0; i < N; ++i) {
			if (S[i] == tails[i]) {
				ans[ansLen++] = S[i];
			}
		}
		ans[ansLen] = 0;
		puts(ans);
	}
	
	return 0;
}