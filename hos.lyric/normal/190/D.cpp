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

#define MAXN 400010

int N, K;
int M;
map<int,int> tr;
int A[MAXN];
int B[MAXN];

int segN;
int seg[MAXN * 4];

void segInit(int n) {
	for (segN = 1; segN < n; segN <<= 1);
	memset(seg, 0, sizeof(seg));
}
void segAdd(int a, int val) {
	seg[a += segN] += val;
	for (; a >>= 1; ) {
		seg[a] = max(seg[a << 1], seg[a << 1 | 1]);
	}
}

int main() {
	int i, j;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		for (i = 0; i < N; ++i) {
			A[i] = in();
		}
		M = 0;
		tr.clear();
		for (i = 0; i < N; ++i) {
			if (!tr.count(A[i])) tr[A[i]] = M++;
			B[i] = tr[A[i]];
		}
// cout<<"B : ";pv(B,B+N);
		segInit(M);
		Int ans = 0;
		for (j = 0, i = 0; i < N; ++i) {
			for (; j < N && seg[1] < K; ++j) {
				segAdd(B[j], +1);
			}
			if (seg[1] >= K) {
				ans += N + 1 - j;
			}
			segAdd(B[i], -1);
		}
		cout << ans << endl;
	}
	
	return 0;
}