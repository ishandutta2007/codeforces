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
char T[100010];
int A[100010];

bool can[100010];
bool app[100010];
bool was[100010];
int num[100010];
int prv[100010];

int segN;
int seg[400010];

int rangeMax(int a, int b) {
	int ret = 0;
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) chmax(ret, seg[a++]);
		if (~b & 1) chmax(ret, seg[b--]);
	}
	return ret;
}

int ansLen;
int ans[100010];

int main() {
	
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (int i = 0; i < M; ++i) {
			scanf(" %c%d", &T[i], &A[i]);
		}
		for (int u = 1; u <= N; ++u) {
			can[u] = true;
			app[u] = false;
			was[u] = false;
		}
		for (int i = 0; i <= M; ++i) {
			const int u = A[i];
			if (!app[u]) {
				app[u] = true;
				if (T[i] == '-') {
					was[u] = true;
				}
			}
		}
		num[0] = 0;
		for (int u = 1; u <= N; ++u) {
			if (was[u]) {
				++num[0];
			}
		}
		for (int i = 0; i < M; ++i) {
			num[i + 1] = num[i] + ((T[i] == '-') ? -1 : +1);
		}
		for (segN = 2; segN < M + 5; segN <<= 1);
		memset(seg, 0, sizeof(seg));
		for (int i = 0; i <= M; ++i) {
			seg[segN + i] = num[i];
		}
		for (int a = segN; --a; ) {
			seg[a] = max(seg[a << 1], seg[a << 1 | 1]);
		}
		
		for (int u = 1; u <= N; ++u) {
			prv[u] = -1;
		}
		for (int i = 0; i < M; ++i) {
			const int u = A[i];
			if (T[i] == '+') {
				if (rangeMax(prv[u] + 1, i) > 0) {
					can[u] = false;
				}
			}
			prv[u] = i;
		}
		for (int u = 1; u <= N; ++u) {
			if (prv[u] != -1 && T[prv[u]] == '-') {
				if (rangeMax(prv[u] + 1, M) > 0) {
					can[u] = false;
				}
			}
		}
		
		ansLen = 0;
		for (int u = 1; u <= N; ++u) {
			if (can[u]) {
				ans[ansLen++] = u;
			}
		}
		printf("%d\n", ansLen);
		if (ansLen > 0) {
			for (int j = 0; j < ansLen; ++j) {
				if (j) printf(" ");
				printf("%d", ans[j]);
			}
			puts("");
		}
	}
	
	return 0;
}