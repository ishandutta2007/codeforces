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
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int K, N[3], T[3];
int xs[10010];

int main() {
	
	
	for (; ~scanf("%d", &K); ) {
		for (int i = 0; i < 3; ++i) {
			N[i] = in();
		}
		for (int i = 0; i < 3; ++i) {
			T[i] = in();
		}
		fill(xs, xs + K, 0);
		for (int i = 0; i < 3; ++i) {
			for (int k = 0; k < K; ++k) {
				xs[k] = max(xs[k], (k - N[i] < 0) ? 0 : xs[k - N[i]]) + T[i];
			}
// cout<<"xs : ";pv(xs,xs+K);
		}
		const int ans = *max_element(xs, xs + K);
		printf("%d\n", ans);
	}
	
	return 0;
}