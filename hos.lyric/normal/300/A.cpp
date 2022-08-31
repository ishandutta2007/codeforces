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
int A[110];

int msLen, psLen, zsLen;
int ms[110], ps[110], zs[110];

int ns[3];
int as[3][110];

int main() {
	int i, j;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		msLen = psLen = zsLen = 0;
		for (i = 0; i < N; ++i) {
			if (A[i] < 0) {
				ms[msLen++] = A[i];
			} else if (A[i] > 0) {
				ps[psLen++] = A[i];
			} else {
				zs[zsLen++] = A[i];
			}
		}
		memset(ns, 0, sizeof(ns));
		as[0][ns[0]++] = ms[--msLen];
		if (psLen >= 1) {
			as[1][ns[1]++] = ps[--psLen];
		} else if (msLen >= 2) {
			as[1][ns[1]++] = ms[--msLen];
			as[1][ns[1]++] = ms[--msLen];
		} else {
			assert(0);
		}
		for (; msLen; ) as[2][ns[2]++] = ms[--msLen];
		for (; psLen; ) as[2][ns[2]++] = ps[--psLen];
		for (; zsLen; ) as[2][ns[2]++] = zs[--zsLen];
		for (j = 0; j < 3; ++j) {
			printf("%d", ns[j]);
			for (i = 0; i < ns[j]; ++i) {
				printf(" %d", as[j][i]);
			}
			puts("");
		}
	}
	
	return 0;
}