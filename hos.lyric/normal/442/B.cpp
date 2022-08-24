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

int N;
double P[110];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			scanf("%lf", &P[i]);
		}
		sort(P, P + N);
		double ans = 0.0;
		for (int h = 0; h < 2; ++h) {
			for (int i = 0; i < N; ++i) {
				double p0 = 1.0, p1 = 0.0;
				for (int j = i; j < N; ++j) {
					p1 = p0 * P[j] + p1 * (1.0 - P[j]);
					p0 = p0 * (1.0 - P[j]);
					chmax(ans, p1);
				}
			}
			reverse(P, P + N);
		}
		printf("%.10f\n", ans);
	}
	
	return 0;
}