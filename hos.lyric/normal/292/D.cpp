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

#define MAX 100010

int uf[MAX];
int root(int x) { return (uf[x] < 0) ? x : (uf[x] = root(uf[x])); }
bool conn(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return 0;
	if (uf[x] > uf[y]) swap(x, y);
	uf[x] += uf[y]; uf[y] = x;
	return 1;
}

int N, M;
int A[MAX], B[MAX];

int lsLens[MAX], rsLens[MAX];
int ls[MAX], rs[MAX];

int main() {
	int i, j;
	int u;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (i = 0; i < M; ++i) {
			A[i] = in() - 1;
			B[i] = in() - 1;
		}
		
		memset(uf, ~0, N << 2);
		lsLens[0] = 0;
		for (i = 0; i < M; ++i) {
			lsLens[i + 1] = lsLens[i];
			if (conn(A[i], B[i])) {
				ls[lsLens[i + 1]++] = i;
			}
		}
		
		memset(uf, ~0, N << 2);
		rsLens[M] = 0;
		for (i = M; i--; ) {
			rsLens[i] = rsLens[i + 1];
			if (conn(A[i], B[i])) {
				rs[rsLens[i]++] = i;
			}
		}
		
		for (int qry = in(); qry--; ) {
			int a = in() - 1;
			int b = in();
			memset(uf, ~0, N << 2);
			for (j = 0; j < lsLens[a]; ++j) {
				conn(A[ls[j]], B[ls[j]]);
			}
			for (j = 0; j < rsLens[b]; ++j) {
				conn(A[rs[j]], B[rs[j]]);
			}
			int ans = 0;
			for (u = 0; u < N; ++u) {
				if (uf[u] < 0) {
					++ans;
				}
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}