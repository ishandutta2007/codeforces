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

int N;
int A[1100010];
Int lt[110], gt[110];

void solve(int d, int S, int T) {
	if (T - S == 1) {
		return;
	}
	int U = (S + T) / 2;
	solve(d - 1, S, U);
	solve(d - 1, U, T);
	int i, lb = U, ub = U;
	for (i = S; i < U; ++i) {
		for (; lb < T; ++lb) if (A[lb] >= A[i]) break;
		for (; ub < T; ++ub) if (A[ub] >  A[i]) break;
		lt[d] += lb - U;
		gt[d] += T - ub;
	}
	inplace_merge(A + S, A + U, A + T);
}

int main() {
	int i;
	int d;
	
	for (; ~scanf("%d", &N); ) {
		for (i = 0; i < 1 << N; ++i) {
			A[i] = in();
		}
		memset(lt, 0, sizeof(lt));
		memset(gt, 0, sizeof(gt));
		solve(N - 1, 0, 1 << N);
// cout<<"lt : ";pv(lt,lt+N);
// cout<<"gt : ";pv(gt,gt+N);
		Int now = 0;
		for (d = 0; d < N; ++d) {
			now += lt[d];
		}
		for (int qry = in(); qry--; ) {
			int q = in();
			for (d = 0; d < q; ++d) {
				now = now - lt[d] + gt[d];
				swap(lt[d], gt[d]);
			}
			printf("%I64d\n", now);
		}
	}
	
	return 0;
}