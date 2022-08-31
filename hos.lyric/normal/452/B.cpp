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

const double INF = 1e+10;

int X, Y;
int len;
double xs[110], ys[110];

inline double dist(int a, int b) {
	return sqrt((xs[a] - xs[b]) * (xs[a] - xs[b]) + (ys[a] - ys[b]) * (ys[a] - ys[b]));
}

int main() {
	
	
	for (; ~scanf("%d%d", &X, &Y); ) {
		len = 0;
		for (int x = 0; x <= X; ++x) for (int y = 0; y <= Y; ++y) {
			if (min(x, X - x) + min(y, Y - y) < 4) {
				xs[len] = x;
				ys[len] = y;
				++len;
			}
		}
		double ans = 0.0;
		int am, bm, cm, dm;
		am = bm = cm = dm = -1;
		for (int a = 0; a < len; ++a) for (int b = 0; b < len; ++b) for (int c = 0; c < len; ++c) for (int d = 0; d < len; ++d) {
			if (a != b && a != c && a != d && b != c && b != d && c != d) {
				double tmp = 0.0;
				tmp += dist(a, b);
				tmp += dist(b, c);
				tmp += dist(c, d);
				if (ans < tmp) {
					ans = tmp;
					am = a;
					bm = b;
					cm = c;
					dm = d;
				}
			}
		}
		printf("%.f %.f\n", xs[am], ys[am]);
		printf("%.f %.f\n", xs[bm], ys[bm]);
		printf("%.f %.f\n", xs[cm], ys[cm]);
		printf("%.f %.f\n", xs[dm], ys[dm]);
	}
	
	return 0;
}