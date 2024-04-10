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

int N;
Int T[10010], C[10010];

int main() {
	int i;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			T[i] = in();
			C[i] = in();
		}
		Int ans = 0;
		Int t = 0;
		for (i = 0; i < N; ++i) {
			if (t <= T[i]) {
				chmax(ans, C[i]);
				t = T[i] + C[i];
			} else {
				chmax(ans, (t - T[i]) + C[i]);
				t += C[i];
			}
		}
		cout << t << " " << ans << endl;
	}
	
	return 0;
}