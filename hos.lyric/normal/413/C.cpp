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

int N, M;
Int A[110];
int B[110];

int xsLen, ysLen;
Int xs[110], ys[110];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
		}
		for (int j = 0; j < M; ++j) {
			B[j] = in() - 1;
		}
		xsLen = ysLen = 0;
		for (int i = 0; i < N; ++i) {
			(count(B, B + M, i) ? xs[xsLen++] : ys[ysLen++]) = A[i];
		}
		sort(xs, xs + xsLen);
		sort(ys, ys + ysLen);
// cout<<"xs : ";pv(xs,xs+xsLen);
// cout<<"ys : ";pv(ys,ys+ysLen);
		Int ans = 0;
		for (int i = ysLen; i--; ) {
			ans += ys[i];
		}
		for (int i = xsLen; i--; ) {
			if (ans >= xs[i]) {
				ans *= 2;
			} else {
				ans += xs[i];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}