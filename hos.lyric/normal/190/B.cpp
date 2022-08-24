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



int main() {
	double xa, ya, ra;
	double xb, yb, rb;
	
	for (; ~scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &ra, &xb, &yb, &rb); ) {
		double d = hypot(xa - xb, ya - yb);
		double ans;
		if (d < abs(ra - rb)) {
			ans = (abs(ra - rb) - d) / 2;
		} else if (d > ra + rb) {
			ans = (d - (ra + rb)) / 2;
		} else {
			ans = 0;
		}
		printf("%.10f\n", ans);
	}
	
	return 0;
}