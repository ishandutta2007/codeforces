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

int N, M;
int T[100010], X[100010];
int ans[100010];

int psLen;
pint ps[100010];

int main() {
	int i, j, k;
	int a, b;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (i = 0; i < N; ++i) {
			T[i] = in();
			X[i] = in();
		}
		int bus = 0;
		for (a = 0; a < N; a = b) {
			b = min(a + M, N);
			chmax(bus, T[b - 1]);
			psLen = 0;
			for (i = a; i < b; ++i) {
				ps[psLen++] = mp(X[i], i);
			}
			sort(ps, ps + psLen);
			int befX = 0;
			for (i = 0; i < psLen; i = j) {
				for (j = i; j < psLen && ps[i].first == ps[j].first; ++j);
				bus += ps[i].first - befX;
				befX = ps[i].first;
				for (k = i; k < j; ++k) ans[ps[k].second] = bus;
				bus += 1 + (j - i) / 2;
			}
			bus += ps[psLen - 1].first;
		}
		for (i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
	
	return 0;
}