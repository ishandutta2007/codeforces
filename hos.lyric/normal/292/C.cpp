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
int A[20];

int xs[20];

char buf[110];
vector<string> ans;

int getIt(int s, int t) {
	if (t - s >= 2 && xs[s] == 0) {
		return -1;
	}
	int val = 0;
	int j;
	for (j = s; j < t; ++j) {
		val = val * 10 + xs[j];
	}
	if (!(0 <= val && val < 256)) {
		return -1;
	}
	return val;
}

void doit(int m) {
// pv(xs,xs+m);
	int j;
	int a, b, c, d;
	int pa, pb, pc, pd;
	for (a = 1; a <= 3; ++a) for (b = 1; b <= 3; ++b) for (c = 1; c <= 3; ++c) {
		d = m - (a + b + c);
		if (1 <= d && d <= 3) {
			pa = getIt(0, a);
			pb = getIt(a, a + b);
			pc = getIt(a + b, a + b + c);
			pd = getIt(a + b + c, a + b + c + d);
			if (~pa && ~pb && ~pc && ~pd) {
				int pos = 0;
				for (j = 0; j < m; ++j) {
					if (j == a || j == a + b || j == a + b + c) {
						buf[pos++] = '.';
					}
					buf[pos++] = '0' + xs[j];
				}
				buf[pos] = 0;
				ans.push_back(buf);
			}
		}
	}
}

void dfs(int pos, int flg) {
	if (flg == (1 << N) - 1) {
		int l, j;
		for (l = pos * 2 - 1; l <= pos * 2; ++l) {
			for (j = pos; j < l; ++j) {
				xs[j] = xs[l - 1 - j];
			}
			doit(l);
		}
	}
	if (pos >= 6) {
		return;
	}
	int i;
	for (i = 0; i < N; ++i) {
		xs[pos] = A[i];
		dfs(pos + 1, flg | 1 << i);
	}
}

int main() {
	int i, k;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		if (N > 6) {
			puts("0");
			continue;
		}
		sort(A, A + N);
		ans.clear();
		dfs(0, 0);
		int sz = ans.size();
		printf("%d\n", sz);
		for (k = 0; k < sz; ++k) {
			puts(ans[k].c_str());
		}
	}
	
	return 0;
}