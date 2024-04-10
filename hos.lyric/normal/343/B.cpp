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

char S[100010];

int stLen;
int st[100010];

int main() {
	int i;
	
	for (; ~scanf("%s", S); ) {
		stLen = 0;
		for (i = 0; S[i]; ++i) {
			if (stLen > 0 && st[stLen - 1] == S[i]) {
				--stLen;
			} else {
				st[stLen++] = S[i];
			}
		}
		puts((stLen == 0) ? "Yes" : "No");
	}
	
	return 0;
}